# DrtGetSearchPathSize function

## Description

The **DrtGetSearchPathSize** function returns the size of the search path, which represents the number of nodes utilized in the search operation.

## Parameters

### `hSearchContext` [in]

Handle to the search context. This parameter is returned by the [DrtStartSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtstartsearch) function.

### `pulSearchPathSize` [out]

Pointer to a **ULONG** value that indicates the size of the search path.

## Return value

This function returns S_OK on success.

## See also

[DRT_ADDRESS_LIST](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_address_list)

[DrtGetSearchPathSize](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtgetsearchpathsize)