# STRUCTURED_QUERY_PARSE_ERROR enumeration

## Description

A set of flags to be used with [IQuerySolution::GetErrors](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iquerysolution-geterrors) to identify parsing error(s). Each parsing error indicates that one or more tokens were ignored when parsing a query string.

## Constants

### `SQPE_NONE:0`

No error.

### `SQPE_EXTRA_OPENING_PARENTHESIS`

An extraneous **(**.

### `SQPE_EXTRA_CLOSING_PARENTHESIS`

An extraneous **)**.

### `SQPE_IGNORED_MODIFIER`

An extraneous **NOT**, **<**, **>**, **=**, and so forth.

### `SQPE_IGNORED_CONNECTOR`

An extraneous **AND** or **OR**.

### `SQPE_IGNORED_KEYWORD`

A property or other keyword used in the wrong context.

### `SQPE_UNHANDLED`

Any other parse error.

## See also

[IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk)