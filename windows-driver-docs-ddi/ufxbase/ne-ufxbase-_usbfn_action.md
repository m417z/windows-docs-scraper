# _USBFN_ACTION enumeration

## Description

Defines special actions UFX should take when the client driver calls the [UfxDevicePortDetectCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceportdetectcompleteex) function.

## Constants

### `UsbfnActionNone`

No special action should be taken.

### `UsbfnActionNoCad`

UFX should not notify the battery manager about the detected port type or the maximum current that can be drawn from the upstream port.

### `UsbfnActionDetectProprietaryCharger`

UFX should initiate proprietary charger detection by calling the client driver’s [EVT_UFX_DEVICE_DETECT_PROPRIETARY_CHARGER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_proprietary_charger_detect) callback function.