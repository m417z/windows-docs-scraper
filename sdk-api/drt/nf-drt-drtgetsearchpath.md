# DrtGetSearchPath function

## Description

The **DrtGetSearchPath** function returns a list of nodes contacted during the search operation.

## Parameters

### `hSearchContext` [in]

Handle to the search context. This parameter is returned by the [DrtStartSearch](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtstartsearch) function.

### `ulSearchPathSize` [in, out]

The size of the search path which represents the number of nodes utilized in the search operation.

### `pSearchPath` [out]

Pointer to a [DRT_ADDRESS_LIST](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_address_list) structure containing the list of addresses.

## Return value

This function returns S_OK on success.

## See also

[DRT_ADDRESS_LIST](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_address_list)

[DrtGetSearchPathSize](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtgetsearchpathsize)