# CASE_REQUIREMENT enumeration

## Description

Specifies the case requirements of keywords, if any, for a query.

## Constants

### `CASE_REQUIREMENT_ANY:0`

Keywords are recognized regardless of case.

### `CASE_REQUIREMENT_UPPER_IF_AQS`

Keywords are recognized only if uppercase when AQS is the syntax. When AQS is not the syntax, keywords are recognized regardless of case.

## Remarks

Keywords include Boolean operators such as AND, NOT, and OR.

## See also

[STRUCTURED_QUERY_RESOLVE_OPTION](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-structured_query_resolve_option)