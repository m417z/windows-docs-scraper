# GetRawInputDeviceList function

## Description

Enumerates the raw input devices attached to the system.

## Parameters

### `pRawInputDeviceList` [out, optional]

Type: **PRAWINPUTDEVICELIST**

An array of [RAWINPUTDEVICELIST](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputdevicelist) structures for the devices attached to the system. Pointer should be aligned on a **DWORD** (32-bit) boundary.

If **NULL**, the number of devices are returned in **puiNumDevices*.

### `puiNumDevices` [in, out]

Type: **PUINT**

If *pRawInputDeviceList* is **NULL**, the function populates this variable with the number of devices attached to the system; otherwise, this variable specifies the number of [RAWINPUTDEVICELIST](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputdevicelist) structures that can be contained in the buffer to which *pRawInputDeviceList* points. If this value is less than the number of devices attached to the system, the function returns the actual number of devices in this variable and fails with **ERROR_INSUFFICIENT_BUFFER**.
If this value is greater than or equal to the number of devices attached to the system, then the value is unchanged, and the number of devices is reported as the return value.

### `cbSize` [in]

Type: **UINT**

The size of a [RAWINPUTDEVICELIST](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputdevicelist) structure, in bytes.

## Return value

Type: **UINT**

If the function is successful, the return value is the number of devices stored in the buffer pointed to by *pRawInputDeviceList*.

On any other error, the function returns (**UINT**) -1 and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the error indication.

## Remarks

The devices returned from this function are the mouse, the keyboard, and other Human Interface Device (HID) devices.

To get more detailed information about the attached devices, call [GetRawInputDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getrawinputdeviceinfoa) using the hDevice from [RAWINPUTDEVICELIST](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputdevicelist).

Input devices accessed through Remote Desktop Protocal (RDP) do not appear in the raw input device list.

#### Examples

The following sample code shows a typical call to **GetRawInputDeviceList**:

```cpp
UINT nDevices;
PRAWINPUTDEVICELIST pRawInputDeviceList = NULL;
while (true) {
    if (GetRawInputDeviceList(NULL, &nDevices, sizeof(RAWINPUTDEVICELIST)) != 0) { Error();}
    if (nDevices == 0) { break; }
    if ((pRawInputDeviceList = malloc(sizeof(RAWINPUTDEVICELIST) * nDevices)) == NULL) {Error();}
    nDevices = GetRawInputDeviceList(pRawInputDeviceList, &nDevices, sizeof(RAWINPUTDEVICELIST));
    if (nDevices == (UINT)-1) {
        if (GetLastError() != ERROR_INSUFFICIENT_BUFFER) { Error(); }
        // Devices were added.
        free(pRawInputDeviceList);
        continue;
    }
    break;
}
// do the job...
// after the job, free the RAWINPUTDEVICELIST
free(pRawInputDeviceList);
```

## See also

**Conceptual**

[GetRawInputDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getrawinputdeviceinfoa)

[RAWINPUTDEVICELIST](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputdevicelist)

[Raw Input](https://learn.microsoft.com/windows/desktop/inputdev/raw-input)