# DBCONTENTPROXIMITY structure

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

The **DBCONTENTPROXIMITY** structure represents specific information required by the DBOP_content_proximity operator.

## Members

### `dwProximityUnit`

words, paras, chapters etc.

### `ulProximityDistance`

how near is "near"?

### `lWeight`

weight of the proximity node

## Remarks

For valid values of the **dwProximityUnit** member, see [Proximity Unit Constants](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/proximity-unit-constants).

For more information on the DBOP_content_proximity operator, see [Content Search Operators](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/content-search-operators).