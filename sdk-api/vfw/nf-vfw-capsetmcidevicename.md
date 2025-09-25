# capSetMCIDeviceName macro

## Syntax

```cpp
BOOL capSetMCIDeviceName(
     hwnd,
     szName
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capSetMCIDeviceName** macro specifies the name of the MCI video device to be used to capture data. You can use this macro or explicitly call the [WM_CAP_SET_MCI_DEVICE](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-mci-device) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `szName`

Pointer to a null-terminated string containing the name of the device.

## Remarks

This message stores the MCI device name in an internal structure. It does not open or access the device. The default device name is **NULL**.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)