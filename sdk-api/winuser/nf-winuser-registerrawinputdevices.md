# RegisterRawInputDevices function

## Description

Registers the devices that supply the raw input data.

## Parameters

### `pRawInputDevices` [in]

Type: **PCRAWINPUTDEVICE**

An array of [RAWINPUTDEVICE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputdevice) structures that represent the devices that supply the raw input. Pointer should be aligned on a **DWORD** (32-bit) boundary.

### `uiNumDevices` [in]

Type: **UINT**

The number of [RAWINPUTDEVICE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputdevice) structures pointed to by *pRawInputDevices*.

### `cbSize` [in]

Type: **UINT**

The size, in bytes, of a [RAWINPUTDEVICE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputdevice) structure.

## Return value

Type: **BOOL**

**TRUE** if the function succeeds; otherwise, **FALSE**. If the function fails, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for more information.

## Remarks

To receive [WM_INPUT](https://learn.microsoft.com/windows/desktop/inputdev/wm-input) messages, an application must first register the raw input devices using **RegisterRawInputDevices**. By default, an application does not receive raw input.

To receive [WM_INPUT_DEVICE_CHANGE](https://learn.microsoft.com/windows/desktop/inputdev/wm-input-device-change) messages, an application must specify the RIDEV_DEVNOTIFY flag for each device class that is specified by the usUsagePage and usUsage fields of the [RAWINPUTDEVICE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputdevice) structure . By default, an application does not receive **WM_INPUT_DEVICE_CHANGE** notifications for raw input device arrival and removal.

If a [RAWINPUTDEVICE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputdevice) structure has the RIDEV_REMOVE flag set and the hwndTarget parameter is not set to NULL, then parameter validation will fail.

Only one window per raw input device class may be registered to receive raw input within a process (the window passed in the last call to RegisterRawInputDevices). Because of this, RegisterRawInputDevices should not be used from a library, as it may interfere with any raw input processing logic already present in applications that load it.

## See also

**Conceptual**

[RAWINPUTDEVICE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputdevice)

[Raw Input](https://learn.microsoft.com/windows/desktop/inputdev/raw-input)

**Reference**

[WM_INPUT](https://learn.microsoft.com/windows/desktop/inputdev/wm-input)