# GetRegisteredRawInputDevices function

## Description

Retrieves the information about the raw input devices for the current application.

## Parameters

### `pRawInputDevices` [out, optional]

Type: **PRAWINPUTDEVICE**

An array of [RAWINPUTDEVICE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputdevice) structures for the application. Pointer should be aligned on a **DWORD** (32-bit) boundary.

### `puiNumDevices` [in, out]

Type: **PUINT**

The number of [RAWINPUTDEVICE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputdevice) structures in **pRawInputDevices*.

### `cbSize` [in]

Type: **UINT**

The size, in bytes, of a [RAWINPUTDEVICE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputdevice) structure.

## Return value

Type: **UINT**

If successful, the function returns a non-negative number that is the number of [RAWINPUTDEVICE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputdevice) structures written to the buffer.

If the *pRawInputDevices* buffer is too small or **NULL**, the function sets the last error as **ERROR_INSUFFICIENT_BUFFER**, returns -1, and sets *puiNumDevices* to the required number of devices. If the function fails for any other reason, it returns -1. For more details, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To receive raw input from a device, an application must register it by using [RegisterRawInputDevices](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerrawinputdevices).

## See also

**Conceptual**

[RAWINPUTDEVICE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputdevice)

[Raw Input](https://learn.microsoft.com/windows/desktop/inputdev/raw-input)

**Reference**

[RegisterRawInputDevices](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerrawinputdevices)