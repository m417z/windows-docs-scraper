# DBCONTENT structure

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

The **DBCONTENT** structure represents specific information required by the DBOP_content operator.

## Members

### `pwszPhrase`

text

### `dwGenerateMethod`

exact, prefix, stemmed

### `lWeight`

weight of node

### `lcid`

locale

## Remarks

For valid values of the **dwGenerateMethod** member, see [Generate Method Constants](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/generate-method-constants).

For more information on the DBOP_content operator, see [Content Search Operators](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/content-search-operators).