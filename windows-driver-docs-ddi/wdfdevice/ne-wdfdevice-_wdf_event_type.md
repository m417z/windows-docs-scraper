# _WDF_EVENT_TYPE enumeration (wdfdevice.h)

## Description

[Applies to UMDF only]

The **WDF_EVENT_TYPE** enumeration specifies types of events about which a driver can notify a registered application.

## Constants

### `WdfEventReserved:0`

Reserved for system use.

### `WdfEventBroadcast:1`

In the current version of UMDF, the driver must specify **WdfEventBroadcast**. For more information, see [WdfDevicePostEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicepostevent).

### `WdfEventMaximum`

Reserved for system use.

## See also

[IWDFDevice::PostEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-postevent)

[WdfDevicePostEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicepostevent)