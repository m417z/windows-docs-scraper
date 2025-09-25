# RAWINPUTDEVICE structure

## Description

Defines information for the raw input devices.

## Members

### `usUsagePage`

Type: **USHORT**

[Top level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) [Usage page](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages#usage-page) for the raw input device. See [HID Clients Supported in Windows](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-architecture#hid-clients-supported-in-windows) for details on possible values.

### `usUsage`

Type: **USHORT**

[Top level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) [Usage ID](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages#usage-id) for the raw input device. See [HID Clients Supported in Windows](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-architecture#hid-clients-supported-in-windows) for details on possible values.

### `dwFlags`

Type: **DWORD**

Mode flag that specifies how to interpret the information provided by **usUsagePage** and **usUsage**. It can be zero (the default) or one of the following values. By default, the operating system sends raw input from devices with the specified [top level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) (TLC) to the registered application as long as it has the window focus.

| Value | Meaning |
| --- | --- |
| **RIDEV_REMOVE**<br><br>0x00000001 | If set, this removes the top level collection from the inclusion list. This tells the operating system to stop reading from a device which matches the top level collection. |
| **RIDEV_EXCLUDE**<br><br>0x00000010 | If set, this specifies the top level collections to exclude when reading a complete usage page. This flag only affects a TLC whose usage page is already specified with **RIDEV_PAGEONLY**. |
| **RIDEV_PAGEONLY**<br><br>0x00000020 | If set, this specifies all devices whose top level collection is from the specified **usUsagePage**. Note that **usUsage** must be zero. To exclude a particular top level collection, use **RIDEV_EXCLUDE**. |
| **RIDEV_NOLEGACY**<br><br>0x00000030 | If set, this prevents any devices specified by **usUsagePage** or **usUsage** from generating [legacy messages](https://learn.microsoft.com/windows/win32/inputdev/mouse-input-notifications). This is only for the mouse and keyboard. See Remarks. |
| **RIDEV_INPUTSINK**<br><br>0x00000100 | If set, this enables the caller to receive the input even when the caller is not in the foreground. Note that **hwndTarget** must be specified. |
| **RIDEV_CAPTUREMOUSE**<br><br>0x00000200 | If set, the mouse button click does not activate the other window. **RIDEV_CAPTUREMOUSE** can be specified only if **RIDEV_NOLEGACY** is specified for a mouse device. |
| **RIDEV_NOHOTKEYS**<br><br>0x00000200 | If set, the application-defined keyboard device hotkeys are not handled. However, the system hotkeys; for example, ALT+TAB and CTRL+ALT+DEL, are still handled. By default, all keyboard hotkeys are handled. **RIDEV_NOHOTKEYS** can be specified even if **RIDEV_NOLEGACY** is not specified and **hwndTarget** is **NULL**. |
| **RIDEV_APPKEYS**<br><br>0x00000400 | If set, the application command keys are handled. **RIDEV_APPKEYS** can be specified only if **RIDEV_NOLEGACY** is specified for a keyboard device. |
| **RIDEV_EXINPUTSINK**<br><br>0x00001000 | If set, this enables the caller to receive input in the background only if the foreground application does not process it. In other words, if the foreground application is not registered for raw input, then the background application that is registered will receive the input. \ **Windows XP:** This flag is not supported until Windows Vista |
| **RIDEV_DEVNOTIFY**<br><br>0x00002000 | If set, this enables the caller to receive [WM_INPUT_DEVICE_CHANGE](https://learn.microsoft.com/windows/desktop/inputdev/wm-input-device-change) notifications for device arrival and device removal. \ **Windows XP:** This flag is not supported until Windows Vista |

### `hwndTarget`

Type: **HWND**

A handle to the target window. If **NULL**, raw input events follow the keyboard focus to ensure only the focused application window receives the events.

## Remarks

If **RIDEV_NOLEGACY** is set for a mouse or a keyboard, the system does not generate any legacy message for that device for the application. For example, if the mouse TLC is set with **RIDEV_NOLEGACY**, **WM_LBUTTONDOWN** and [related legacy mouse messages](https://learn.microsoft.com/windows/win32/inputdev/mouse-input-notifications) are not generated. Likewise, if the keyboard TLC is set with **RIDEV_NOLEGACY**, **WM_KEYDOWN** and [related legacy keyboard messages](https://learn.microsoft.com/windows/win32/inputdev/keyboard-input-notifications) are not generated.

If **RIDEV_REMOVE** is set and the **hwndTarget** member is not set to **NULL**, then [RegisterRawInputDevices](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-registerrawinputdevices) function will fail.

## See also

**Conceptual**

[GetRegisteredRawInputDevices](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getregisteredrawinputdevices)

[Raw Input](https://learn.microsoft.com/windows/desktop/inputdev/raw-input)

[Introduction to Human Interface Devices (HID)](https://learn.microsoft.com/windows-hardware/drivers/hid/)

[HID Clients Supported in Windows](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-architecture#hid-clients-supported-in-windows)

[HID USB homepage](https://www.usb.org/hid)

**Reference**

[RegisterRawInputDevices](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-registerrawinputdevices)