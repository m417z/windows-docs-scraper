# DefRawInputProc function

## Description

Unlike [DefWindowProcA](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-defwindowproca) and [DefWindowProcW](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-defwindowprocw), this function doesn't do any processing.

**DefRawInputProc** only checks whether **cbSizeHeader**'s value corresponds to the expected size of [RAWINPUTHEADER](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputheader).

## Parameters

### `paRawInput` [in]

Type: **PRAWINPUT***

Ignored.

### `nInput` [in]

Type: **INT**

Ignored.

### `cbSizeHeader` [in]

Type: **UINT**

The size, in bytes, of the [RAWINPUTHEADER](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputheader) structure.

## Return value

Type: **LRESULT**

If successful, the function returns **0**. Otherwise it returns **-1**.

## See also

**Conceptual**

[RAWINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinput)

[RAWINPUTHEADER](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputheader)

[Raw Input](https://learn.microsoft.com/windows/desktop/inputdev/raw-input)