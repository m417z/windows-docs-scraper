# STRUCTURED_QUERY_SYNTAX enumeration

## Description

Specifies the type of query syntax.

## Constants

### `SQS_NO_SYNTAX:0`

No syntax.

### `SQS_ADVANCED_QUERY_SYNTAX`

Specifies the Advanced Query Syntax. For example, "kind:email to:david to:bill".

### `SQS_NATURAL_QUERY_SYNTAX`

Specifies the Natural Query Syntax. This syntax removes the requirement for a colon between properties and values, for example, "email from david to bill".

## Remarks

Use this enumeration to set the desired SQSO_SYNTAX flag in [STRUCTURED_QUERY_SINGLE_OPTION](https://learn.microsoft.com/windows/win32/api/structuredquery/ne-structuredquery-structured_query_single_option), which is used with the methods [IQueryParser::SetOption](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iqueryparser-setoption) and [IQueryParser::GetOption](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iqueryparser-getoption).