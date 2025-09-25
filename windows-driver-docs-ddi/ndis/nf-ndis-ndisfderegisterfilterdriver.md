# NdisFDeregisterFilterDriver function

## Description

A filter drivers calls the
**NdisFDeregisterFilterDriver** function to release resources that it previously allocated with the
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) function.

## Parameters

### `NdisFilterDriverHandle` [in]

The filter driver handle that identifies this filter driver. NDIS returned the handle to the
filter driver in a call to
**NdisFRegisterFilterDriver**.

## Remarks

A filter driver must call
**NdisFDeregisterFilterDriver** from its
[FilterDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/network/unloading-a-filter-driver) routine.

## See also

[FilterDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/network/unloading-a-filter-driver)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)