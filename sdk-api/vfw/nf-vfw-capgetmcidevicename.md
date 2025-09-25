# capGetMCIDeviceName macro

## Syntax

```cpp
BOOL capGetMCIDeviceName(
     hwnd,
     szName,
     wSize
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capGetMCIDeviceName** macro retrieves the name of an MCI device previously set with the [capSetMCIDeviceName](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capsetmcidevicename) macro. You can use this macro or explicitly call the [WM_CAP_GET_MCI_DEVICE](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-get-mci-device) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `szName`

Pointer to a null-terminated string that contains the MCI device name.

### `wSize`

Length, in bytes, of the buffer referenced by *szName* .

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)