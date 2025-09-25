# EVT_MBB_DEVICE_CREATE_ADAPTER callback function

## Description

The *EvtMbbDeviceCreateAdapter* callback function is implemented by the client driver to create a NETADAPTER object for a data session.

## Parameters

### `Device`

A handle to a framework device object the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `AdapterInit`

A NETADAPTER_INIT object that describes the initialization information for the NETADAPTER.

## Return value

This callback function returns STATUS_SUCCESS if the operation was successful. Otherwise, it returns an appropriate NTSTATUS error code.

## Prototype

```cpp
//Declaration

EVT_MBB_DEVICE_CREATE_ADAPTER EvtMbbDeviceCreateAdapter;

// Definition

NTSTATUS EvtMbbDeviceCreateAdapter
(
	WDFDEVICE			Device,
	NETADAPTER_INIT *	AdapterInit
)
{...}

```

## Remarks

An MBBCx client driver must register an *EvtMbbDeviceCreateAdapter* callback function by calling [**MbbDeviceInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbbdeviceinitialize).

In this callback, the client driver creates a NETADAPTER object that is used by MBBCx to represent the network interface for a data session. MBBCx invokes this callback function at least once to establish the primary PDP context/default EPS bearer, then it might invoke it more times, once for every data session to be established.

Before returning from *EvtMbbDeviceCreateAdapter*, client drivers must start the adapter by calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart). Optionally, they can also set the adapter's capabilities by calling one or more of these functions *before* the call to **NetAdapterStart**:

- [**NetAdapterSetDatapathCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetdatapathcapabilities)
- [**NetAdapterSetLinkLayerCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetlinklayercapabilities)
- [**NetAdapterSetLinkLayerMtuSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetlinklayermtusize)

For more information and a code example, see [Creating the NetAdapter interface for the PDP context/EPS bearer](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-an-mbbcx-client-driver#creating-the-netadapter-interface-for-the-pdp-contexteps-bearer).

## See also