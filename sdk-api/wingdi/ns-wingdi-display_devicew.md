# DISPLAY_DEVICEW structure

## Description

The **DISPLAY_DEVICE** structure receives information about the display device specified by the *iDevNum* parameter of the [EnumDisplayDevices](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaydevicesa) function.

## Members

### `cb`

Size, in bytes, of the **DISPLAY_DEVICE** structure. This must be initialized prior to calling [EnumDisplayDevices](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaydevicesa).

### `DeviceName`

An array of characters identifying the device name. This is either the adapter device or the monitor device.

### `DeviceString`

An array of characters containing the device context string. This is either a description of the display adapter or of the display monitor.

### `StateFlags`

Device state flags. It can be any reasonable combination of the following.

| Value | Meaning |
| --- | --- |
| DISPLAY_DEVICE_ACTIVE | DISPLAY_DEVICE_ACTIVE specifies whether a monitor is presented as being "on" by the respective GDI view. **Windows Vista:** EnumDisplayDevices will only enumerate monitors that can be presented as being "on." |
| DISPLAY_DEVICE_MIRRORING_DRIVER | Represents a pseudo device used to mirror application drawing for remoting or other purposes. An invisible pseudo monitor is associated with this device. For example, NetMeeting uses it. Note that [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) (SM_MONITORS) only accounts for visible display monitors. |
| DISPLAY_DEVICE_MODESPRUNED | The device has more display modes than its output devices support. |
| DISPLAY_DEVICE_PRIMARY_DEVICE | The primary desktop is on the device. For a system with a single display card, this is always set. For a system with multiple display cards, only one device can have this set. |
| DISPLAY_DEVICE_REMOVABLE | The device is removable; it cannot be the primary display. |
| DISPLAY_DEVICE_VGA_COMPATIBLE | The device is VGA compatible. |

### `DeviceID`

Not used.

### `DeviceKey`

Reserved.

## Remarks

The four string members are set based on the parameters passed to [EnumDisplayDevices](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaydevicesa). If the *lpDevice* param is **NULL**, then DISPLAY_DEVICE is filled in with information about the display adapter(s). If it is a valid device name, then it is filled in with information about the monitor(s) for that device.

> [!NOTE]
> The wingdi.h header defines DISPLAY_DEVICE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Device Context Structures](https://learn.microsoft.com/windows/desktop/gdi/device-context-structures)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[EnumDisplayDevices](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaydevicesa)

[GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)