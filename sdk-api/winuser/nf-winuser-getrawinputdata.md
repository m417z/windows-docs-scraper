# GetRawInputData function

## Description

Retrieves the raw input from the specified device.

## Parameters

### `hRawInput` [in]

Type: **HRAWINPUT**

A handle to the [RAWINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinput) structure. This comes from the *lParam* in [WM_INPUT](https://learn.microsoft.com/windows/desktop/inputdev/wm-input).

### `uiCommand` [in]

Type: **UINT**

The command flag. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **RID_HEADER**<br><br>0x10000005 | Get the header information from the [RAWINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinput) structure. |
| **RID_INPUT**<br><br>0x10000003 | Get the raw data from the [RAWINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinput) structure. |

### `pData` [out, optional]

Type: **LPVOID**

A pointer to the data that comes from the [RAWINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinput) structure. This depends on the value of *uiCommand*. Pointer should be aligned on a **DWORD** (32-bit) boundary.

If *pData* is **NULL**, the required size of the buffer is returned in **pcbSize*.

### `pcbSize` [in, out]

Type: **PUINT**

The size, in bytes, of the data in *pData*.

### `cbSizeHeader` [in]

Type: **UINT**

The size, in bytes, of the [RAWINPUTHEADER](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputheader) structure.

## Return value

Type: **UINT**

If *pData* is **NULL** and the function is successful, the return value is 0. If *pData* is not **NULL** and the function is successful, the return value is the number of bytes copied into pData.

If there is an error, the return value is (**UINT**)-1.

## Remarks

**GetRawInputData** gets the raw input one [RAWINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinput) structure at a time. In contrast, [GetRawInputBuffer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getrawinputbuffer) gets an array of **RAWINPUT** structures.

## See also

**Conceptual**

[GetRawInputBuffer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getrawinputbuffer)

[RAWINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinput)

[RAWINPUTHEADER](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputheader)

[Raw Input](https://learn.microsoft.com/windows/desktop/inputdev/raw-input)

**Reference**