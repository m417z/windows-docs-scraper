# DBSORTINFO structure

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

The **DBSORTINFO** structure stores the order in which a column will be sorted (that is, ascending or descending). This information is stored inside a DBOP_sort_list_element node.

## Members

### `fDesc`

TRUE = ascending, FALSE = descending

### `lcid`

locale identifier

## Remarks

The locale identifier (LCID) specifies a set of user preference information related to the user's language. It determines how times are formatted, how items are alphabetically sorted, and how strings are compared.

For additional information on LCIDs see [Locales](https://learn.microsoft.com/previous-versions/ms776264(v=vs.85)).