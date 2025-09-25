# KsQueryDevicePnpObject function

## Description

The **KsQueryDevicePnpObject** function returns the PnP device object that can be stored in the device header. This is the next device object on the PnP stack and is the device object that PnP requests are forwarded to if **KsDefaultDispatchPnp** is used.

## Parameters

### `Header` [in]

Points to a header previously allocated by [KsAllocateDeviceHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedeviceheader) whose PnP device object is to be returned.

## Return value

The **KsQueryDevicePnpObject** function returns the previously set PnP device object. If none was set, it returns **NULL**.

## See also

[KsDefaultDispatchPnp](https://learn.microsoft.com/previous-versions/ff561665(v=vs.85))