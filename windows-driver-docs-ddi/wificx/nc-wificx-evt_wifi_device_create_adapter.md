## Description

WiFiCx client drivers implement *EvtWifiDeviceCreateAdapter* to create a NETADAPTER object.

## Parameters

### `Device`

[_In_] A handle to a framework device object that the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `AdapterInit`

[_Inout_] A pointer to a NETADAPTER_INIT object that describes the initialization information for the NETADAPTER.

## Return value

This callback function returns STATUS_SUCCESS if the operation was successful. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

A WiFiCx client driver must register an *EvtWifiDeviceCreateAdapter* callback function by calling [**WifiDeviceInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifideviceinitialize).

In its *EvtWifiDeviceCreateAdapter* callback, the client driver must:

1. Call [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate) to create the new NetAdapter object.

2. Call [**WifiAdapterInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifiadapterinitialize) to initialize the WiFiCx context and associate it with this NetAdapter object.

3. Call [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart) to start the adapter.

For more information, see [Writing a WiFiCx client driver](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver).

## See also

[**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)

[**WifiDeviceInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifideviceinitialize)

[**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate)

[**WifiAdapterInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifiadapterinitialize)

[**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart)

[Writing a WiFiCx client driver](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver)