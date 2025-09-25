## Description

The **WifiDeviceGetOsWdiVersion** function gets the TLV version that WifiCx uses to initialize client driver's [TLV parser/generator](https://learn.microsoft.com/windows-hardware/drivers/netcx/wificx-tlv-generator-interface).

## Parameters

### `Device`

[_In_] A handle to a framework device object that the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

## Return value

Returns the TLV version that WifiCx uses to initialize client driver's TLV parser/generator.

## Remarks

## See also

[WiFiCx TLV parser/generator](https://learn.microsoft.com/windows-hardware/drivers/netcx/wificx-tlv-generator-interface)

[**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)