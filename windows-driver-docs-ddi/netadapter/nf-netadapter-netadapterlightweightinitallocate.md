## Description

The **NetAdapterLightweightInitAllocate** function allocates a NETADAPTER_INIT structure that a client driver uses when creating a new NETADAPTER object for a deviceless adapter.

## Parameters

### `NetworkInterfaceGuid` [_In_]

The GUID of a valid network interface using the to-be-created deviceless adapter.

## Return value

Returns a pointer to a framework-allocated NETADAPTER_INIT structure if the operation succeeds. Otherwise, this function returns **NULL**.

> [!IMPORTANT]
> If a client driver receives a NETADAPTER_INIT structure from a successful call to this function, the driver must always call [**NetAdapterInitFree**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterinitfree) to deallocate it regardless of the result of [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

## Remarks

## See also

[Device initialization](https://learn.microsoft.com/windows-hardware/drivers/netcx/device-initialization)

[**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate)

[**NetAdapterInitFree**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterinitfree)