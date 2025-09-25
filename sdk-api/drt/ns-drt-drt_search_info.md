# DRT_SEARCH_INFO structure

## Description

The **DRT_SEARCH_INFO** structure represents a search query issued with [DrtStartSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtstartsearch).

## Members

### `dwSize`

Specifies the byte count of **DRT_SEARCH_INFO**.

### `fIterative`

Indicates whether the search is iterative. If set to **TRUE**, the search is iterative.

### `fAllowCurrentInstanceMatch`

Indicates whether search results can contain matches found in the local DRT instance. If set to **TRUE**, the search results are capable of containing matches found in the local DRT instance.

### `fAnyMatchInRange`

If set to **true**, the search will stop locating the first key falling within the specified range. Otherwise, the search for the closest match to the target key specified by [DrtStartSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtstartsearch) will continue.

### `cMaxEndpoints`

Specifies the number of results to return. This includes closest and exact matches. If this value is greater than 1 when **fIterative** is **TRUE**, the search will only return 1 result.

### `pMaximumKey`

Specifies the numerically largest key value the infrastructure should attempt to match.

### `pMinimumKey`

Specifies the numerically smallest key value the infrastructure should attempt to match.

## See also

[DrtStartSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtstartsearch)