# NetAdapterInitFree function

## Description

The **NetAdapterInitFree** function deallocates a NETADAPTER_INIT structure.

## Parameters

### `AdapterInit` [_In_]

A pointer to a NETADAPTER_INIT structure.

## Remarks

If a client driver receives a NETADAPTER_INIT structure from a call to [**NetAdapterInitAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterinitallocate), the driver must always call **NetAdapterInitFree** to deallocate it regardless of the result of [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

For more information and a code example about calling [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate), see [Device initialization](https://learn.microsoft.com/windows-hardware/drivers/netcx/device-initialization).

## See also

[**NetAdapterInitAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterinitallocate)

[**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate)

[Device initialization](https://learn.microsoft.com/windows-hardware/drivers/netcx/device-initialization)