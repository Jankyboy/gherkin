#ifndef GHERKIN_TOKEN_MATCHER_H_
#define GHERKIN_TOKEN_MATCHER_H_

#include <stdbool.h>
#include "token.h"
#include "error_list.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Dialect Dialect;

typedef struct TokenMatcher TokenMatcher;

typedef void (*matcher_reset_function) (TokenMatcher*);

typedef bool (*match_function) (TokenMatcher*, Token*);

typedef struct TokenMatcher {
    const wchar_t* default_language;
    const wchar_t* language;
    const Dialect* dialect;
    const wchar_t* active_doc_string_separator;
    int indent_to_remove;
    ErrorList* errors;
    matcher_reset_function reset;
    match_function match_FeatureLine;
    match_function match_ScenarioLine;
    match_function match_ScenarioOutlineLine;
    match_function match_ExamplesLine;
    match_function match_BackgroundLine;
    match_function match_StepLine;
    match_function match_Empty;
    match_function match_TableRow;
    match_function match_Comment;
    match_function match_TagLine;
    match_function match_DocStringSeparator;
    match_function match_Language;
    match_function match_Other;
    match_function match_EOF;
} TokenMatcher;

TokenMatcher* TokenMatcher_new(const wchar_t* default_language);

void TokenMatcher_delete(TokenMatcher* token_matcher);

#ifdef __cplusplus
}
#endif
#endif /* GHERKIN_TOKEN_MATCHER_H_ */
