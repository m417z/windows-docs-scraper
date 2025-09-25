## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

The **DBCONTENTVECTOR** structure represents specific information required by the DBOP_content_vector_or operator.

## Members

### `lWeight`

Node weight.

### `dwRankingMethod`

Jaccard, dice, and so on.

## Remarks

For valid values of the **dwRankingMethod** member, see [Vector Rank Constants](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/vector-rank-constants).

For more information on the DBOP_content_vector operator, see [Content Search Operators](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/content-search-operators).