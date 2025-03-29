#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string& source) {
  Corpus tokens;

  auto whitespaces = find_all(source.begin(), source.end(), ::isspace);

  if (whitespaces.size() < 2) return tokens;  // No valid tokens possible

  std::transform(whitespaces.begin(), whitespaces.end() - 1,
                 whitespaces.begin() + 1,
                 std::inserter(tokens, tokens.end()),
                 [&source](auto start, auto finish) {
                   if (start >= source.end()) return Token(source, source.end(), source.end());  
                   return Token(source, start, finish);
                 });

  std::erase_if(tokens, [](const auto& token) { return token.content.empty(); });

  return tokens;
}


namespace rv = std::ranges::views;
std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  auto view =   
    source  | rv::filter([&dictionary](const Token& token){ return !dictionary.contains(token.content); })
            | rv::transform([&dictionary](Token token)
              { 
                auto suggestions_view = 
                  dictionary  | rv::filter([&token](auto word){ return levenshtein(token.content, word) == 1; });
                std::set<std::string> suggestions(suggestions_view.begin(), suggestions_view.end());
                return Mispelling{token, suggestions};
              })
            | rv::filter([](const Mispelling& mispelling){ return !mispelling.suggestions.empty(); });

  std::set<Mispelling> mispellings(view.begin(), view.end());

  return mispellings;
};

/* Helper methods */

#include "utils.cpp"