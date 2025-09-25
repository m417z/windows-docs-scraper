# GetRawInputDeviceInfoW function

## Description

Retrieves information about the raw input device.

## Parameters

### `hDevice` [in, optional]

Type: **HANDLE**

A handle to the raw input device. This comes from the **hDevice** member of [RAWINPUTHEADER](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputheader) or from [GetRawInputDeviceList](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getrawinputdevicelist).

### `uiCommand` [in]

Type: **UINT**

Specifies what data will be returned in *pData*. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **RIDI_PREPARSEDDATA**<br><br>0x20000005 | *pData* is a [PHIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_collection_descriptor) pointer to a buffer for a [top-level collection's](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data). |
| **RIDI_DEVICENAME**<br><br>0x20000007 | *pData* points to a string that contains the [device interface name](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces).<br><br>If this device is [opened with Shared Access Mode](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-architecture#hid-clients-supported-in-windows) then you can call [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew) with this name to open a HID collection and use returned handle for calling [ReadFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile) to read input reports and [WriteFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-writefile) to send output reports.<br><br>For more information, see [Opening HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/opening-hid-collections) and [Handling HID Reports](https://learn.microsoft.com/windows-hardware/drivers/hid/handling-hid-reports).<br><br>For this *uiCommand* only, the value in *pcbSize* is the character count (not the byte count). |
| **RIDI_DEVICEINFO**<br><br>0x2000000b | *pData* points to an [RID_DEVICE_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rid_device_info) structure. |

### `pData` [in, out, optional]

Type: **LPVOID**

A pointer to a buffer that contains the information specified by *uiCommand*. Pointer should be aligned on a **DWORD** (32-bit) boundary.

If *uiCommand* is **RIDI_DEVICEINFO**, set the **cbSize** member of [RID_DEVICE_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rid_device_info) to `sizeof(RID_DEVICE_INFO)` before calling **GetRawInputDeviceInfo**.

### `pcbSize` [in, out]

Type: **PUINT**

The size, in bytes, of the data in *pData*.

## Return value

Type: **UINT**

If successful, this function returns a non-negative number indicating the number of bytes copied to *pData*.

If *pData* is not large enough for the data, the function returns -1. If *pData* is **NULL**, the function returns a value of zero. In both of these cases, *pcbSize* is set to the minimum size required for the *pData* buffer.

Call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to identify any other errors.

## See also

**Conceptual**

[RAWINPUTHEADER](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputheader)

[RID_DEVICE_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rid_device_info)

[Raw Input](https://learn.microsoft.com/windows/desktop/inputdev/raw-input)

**Reference**

[WM_INPUT](https://learn.microsoft.com/windows/desktop/inputdev/wm-input)

[Top-Level Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections)

[Preparsed Data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data)

[PHIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_collection_descriptor)

[Opening HID collections](https://learn.microsoft.com/windows-hardware/drivers/hid/opening-hid-collections)

[Handling HID Reports](https://learn.microsoft.com/windows-hardware/drivers/hid/handling-hid-reports)

## Remarks

> [!NOTE]
> The winuser.h header defines GetRawInputDeviceInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).