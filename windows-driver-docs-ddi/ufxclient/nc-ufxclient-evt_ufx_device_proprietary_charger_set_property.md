# EVT_UFX_DEVICE_PROPRIETARY_CHARGER_SET_PROPERTY callback function

## Description

The client driver's implementation to set charger information that it uses to enable charging over USB.

## Parameters

### `unnamedParam1` [in]

The handle to a USB device object that the client driver received in a previous call to the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

### `unnamedParam2` [in]

The handle framework request object that for an [IOCTL_INTERNAL_CONFIGURE_CHARGER_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/charging/ni-charging-ioctl_internal_configure_charger_property) request from the battery minidriver.

## Remarks

*EVT_UFX_DEVICE_PROPRIETARY_CHARGER_SET_PROPERTY* is an optional event callback.

*WdfRequest* is contains a request for [IOCTL_INTERNAL_CONFIGURE_CHARGER_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/charging/ni-charging-ioctl_internal_configure_charger_property), which specifies a charger ID that is known by the client driver and battery miniclass driver, and a voltage value in millivolts. The client driver can use this information to enable charging over the USB port at an appropriate current/voltage level.

## See also

[UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate)

[UfxDeviceProprietaryChargerDetectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceproprietarychargerdetectcomplete)