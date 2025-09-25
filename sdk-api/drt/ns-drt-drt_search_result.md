## Description

The **DRT_SEARCH_RESULT** contains the registration entry and the type of match of the search result returned by [DrtGetSearchResult](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtgetsearchresult) when the *hEvent* passed into [DrtStartSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtstartsearch) is signaled.

## Members

### `dwSize`

The size of the **DRT_SEARCH_RESULT** structure.

### `type`

Specifies the exactness of the search. This member corresponds to the [DRT_MATCH_TYPE](https://learn.microsoft.com/windows/desktop/api/drt/ne-drt-drt_match_type) enumeration.

### `pvContext`

Pointer to the context data passed to the [DrtStartSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtstartsearch) API.

### `registration`

Contains the registration result.

## See also

[DRT_MATCH_TYPE](https://learn.microsoft.com/windows/desktop/api/drt/ne-drt-drt_match_type)

[DrtGetSearchResult](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtgetsearchresult)

[DrtStartSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtstartsearch)