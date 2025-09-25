# HidD_GetHidGuid function

## Description

The **HidD_GetHidGuid** routine returns the [device interface](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes) [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) for HIDClass devices.

## Parameters

### `HidGuid` [out]

Pointer to a caller-allocated GUID buffer that the routine uses to return the [device interface GUID for HIDClass devices](https://learn.microsoft.com/windows-hardware/drivers/install/guid-devinterface-hid).

## Remarks

Only user-mode applications can call **HidD_GetHidGuid**.

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[GUID_DEVINTERFACE_HID](https://learn.microsoft.com/windows-hardware/drivers/install/guid-devinterface-hid)

[IoGetDeviceInterfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceinterfaces)