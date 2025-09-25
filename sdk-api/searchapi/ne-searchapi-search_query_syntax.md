# SEARCH_QUERY_SYNTAX enumeration

## Description

Specifies the type of query syntax.

## Constants

### `SEARCH_NO_QUERY_SYNTAX:0`

No syntax.

### `SEARCH_ADVANCED_QUERY_SYNTAX`

Specifies the Advanced Query Syntax. For example, "kind:email to:david to:bill".

### `SEARCH_NATURAL_QUERY_SYNTAX`

Specifies the Natural Query Syntax. This syntax removes the requirement for a colon between properties and values, for example, "email from david to bill".

## Remarks

This enumerated type is used by the [ISearchQueryHelper::get_QuerySyntax](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-get_querysyntax) and [ISearchQueryHelper::put_QuerySyntax](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-put_querysyntax) methods.

**Note** In Windows 7, the names are prefixed with SQS_ instead of SEARCH_.