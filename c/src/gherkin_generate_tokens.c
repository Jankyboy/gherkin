#include <locale.h>
#include <stdlib.h>
#include "file_reader.h"
#include "string_token_scanner.h"
//#include "file_token_scanner.h"
#include "token_matcher.h"
#include "parser.h"
#include "token_formatter_builder.h"

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");
    int i;
    for (i = 1; i < argc; ++i) {
        FileReader* file_reader = FileReader_new(argv[i]);
        const wchar_t* source = FileReader_read(file_reader);
        FileReader_delete(file_reader);
        TokenScanner* token_scanner = StringTokenScanner_new(source);
        //TokenScanner* token_scanner = FileTokenScanner_new(argv[i]);
        TokenMatcher* token_matcher = TokenMatcher_new(L"en");
        Builder* builder = TokenFormatterBuilder_new();
        Parser* parser = Parser_new(builder);
        Parser_parse(parser, token_matcher, token_scanner);
        free((void*)source);
        Parser_delete(parser);
        TokenFormatterBuilder_delete(builder);
        TokenMatcher_delete(token_matcher);
        TokenScanner_delete(token_scanner);
    }
    return 0;
}
