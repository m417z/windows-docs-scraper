# NetAdapterInitAllocate function

## Description

The **NetAdapterInitAllocate** function allocates a NETADAPTER_INIT structure that a client driver uses when creating a new NETADAPTER object.

## Parameters

### `Device` [_In_]

A handle to a framework device object.

## Return value

Returns a pointer to a framework-allocated NETADAPTER_INIT structure if the operation succeeds. Otherwise, this function returns **NULL**.

> [!IMPORTANT]
> If a client driver receives a NETADAPTER_INIT structure from a successful call to this function, the driver must always call [**NetAdapterInitFree**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterinitfree) to deallocate it regardless of the result of [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

## Remarks

A client driver calls **NetAdapterInitAllocate** to obtain a NETADAPTER_INIT structure that it can pass to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

After **NetAdapterInitAllocate** succeeds, client drivers can optionally call **NetAdapterInitSetXxx** functions to set further initialization attributes for the NETADAPTER.

For a code example of creating a NETADAPTER, see [Device initialization](https://learn.microsoft.com/windows-hardware/drivers/netcx/device-initialization).

## See also

[Device initialization](https://learn.microsoft.com/windows-hardware/drivers/netcx/device-initialization)

[**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate)

[**NetAdapterInitFree**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterinitfree)