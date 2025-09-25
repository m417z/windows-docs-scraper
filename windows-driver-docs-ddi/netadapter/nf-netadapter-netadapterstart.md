# NetAdapterStart function

## Description

The **NetAdapterStart** function starts a NETADAPTER object.

## Parameters

### `Adapter` [_In_]

The **NETADAPTER** object created by a prior call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

## Return value

The function returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

For this function to succeed, the **NETADAPTER** object must have been previously created by calling [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

## See also

[**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate)

[**NetAdapterStop**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstop)