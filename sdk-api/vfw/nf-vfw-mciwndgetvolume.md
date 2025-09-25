# MCIWndGetVolume macro

## Syntax

```cpp
LONG MCIWndGetVolume(
     hwnd
);
```

## Return value

Type: **LONG**

Returns the current volume setting. The default value is 1000. Higher values indicate louder volumes; lower values indicate quieter volumes.

## Description

The **MCIWndGetVolume** macro retrieves the current volume setting of an MCI device. You can use this macro or explicitly send the [MCIWNDM_GETVOLUME](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getvolume) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_GETVOLUME](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getvolume)