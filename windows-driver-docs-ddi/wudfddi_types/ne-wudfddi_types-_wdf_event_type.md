# _WDF_EVENT_TYPE enumeration (wudfddi_types.h)

## Description

[Applies to UMDF only]

The **WDF_EVENT_TYPE** enumeration specifies types of events about which a driver can notify a registered application.

## Constants

### `WdfEventReserved`

Reserved for system use.

### `WdfEventBroadcast`

In the current version of UMDF, the driver must specify **WdfEventBroadcast**. For more information, see [WdfDevicePostEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicepostevent).

### `WdfEventMaximum`

Reserved for system use.

## See also

[IWDFDevice::PostEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-postevent)

[WdfDevicePostEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicepostevent)