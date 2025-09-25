# SEARCH_TERM_EXPANSION enumeration

## Description

Indicates wildcard options on search terms. Used by [ISearchQueryHelper::get_QueryTermExpansion](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-get_querytermexpansion) and [ISearchQueryHelper::put_QueryTermExpansion](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-put_querytermexpansion) methods.

## Constants

### `SEARCH_TERM_NO_EXPANSION:0`

No expansion is applied to search terms.

### `SEARCH_TERM_PREFIX_ALL`

All search terms are expanded.

### `SEARCH_TERM_STEM_ALL`

Stem expansion is applied to all terms.

## Remarks

While the **SEARCH_TERM_EXPANSION** enumerated type lets you specify stem expansion, Windows Search does not currently support its use with the [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper) interface.