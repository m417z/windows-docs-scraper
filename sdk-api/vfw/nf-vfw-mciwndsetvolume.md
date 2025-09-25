# MCIWndSetVolume macro

## Syntax

```cpp
LONG MCIWndSetVolume(
     hwnd,
     iVol
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndSetVolume** macro sets the volume level of an MCI device. You can use this macro or explicitly send the [MCIWNDM_SETVOLUME](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-setvolume) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `iVol`

New volume level. Specify 1000 for normal volume level. Specify a higher value for a louder volume or a lower value for a quieter volume.