# DRT_MATCH_TYPE enumeration

## Description

The **DRT_MATCH_TYPE** enumeration defines the exactness of a search result returned by [DrtGetSearchResult](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtgetsearchresult) after initiating a search with the [DrtStartSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtstartsearch) API.

## Constants

### `DRT_MATCH_EXACT:0`

The node found is publishing the target key or is publishing a key within the specified range.

### `DRT_MATCH_NEAR:1`

The node found is publishing the numerically closest key to the specified target key.

### `DRT_MATCH_INTERMEDIATE:2`

The node returned is an intermediate node. An application will receive this node match type if **fIterative** is set to **TRUE**.

## See also

[DrtGetSearchResult](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtgetsearchresult)

[DrtStartSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtstartsearch)