# MCIWndEject macro

## Syntax

```cpp
LONG MCIWndEject(
     hwnd
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndEject** macro sends a command to an MCI device to eject its media. You can use this macro or explicitly send the [MCIWNDM_EJECT](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-eject) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_EJECT](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-eject)