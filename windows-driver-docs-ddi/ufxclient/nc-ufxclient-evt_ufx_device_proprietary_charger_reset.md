# EVT_UFX_DEVICE_PROPRIETARY_CHARGER_RESET callback function

## Description

The client driver's implementation to resets proprietary charger.

## Parameters

### `unnamedParam1` [in]

The handle to a USB device object that the client driver received in a previous call to the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate) method.

## Remarks

*EVT_UFX_DEVICE_PROPRIETARY_CHARGER_RESET* is an optional event callback.

The USB function class extension (UFX) invokes this event callback to indicate that the USB device has been detached from the charger. The client driver initiates a request to the lower filter driver to reset the proprietary charger its initial state.

## See also

- [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate)
- [UfxDeviceProprietaryChargerDetectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceproprietarychargerdetectcomplete)