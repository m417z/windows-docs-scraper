# MCIWndGetMode macro

## Syntax

```cpp
LONG MCIWndGetMode(
     hwnd,
     lp,
     len
);
```

## Return value

Type: **LONG**

Returns an integer corresponding to the MCI constant defining the mode.

## Description

The **MCIWndGetMode** macro retrieves the current operating mode of an MCI device. MCI devices have several operating modes, which are designated by constants. You can use this macro or explicitly send the [MCIWNDM_GETMODE](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getmode) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `lp`

Pointer to the application-defined buffer used to return the mode.

### `len`

Size, in bytes, of the buffer.

## Remarks

If the null-terminated string describing the mode is longer than the buffer, it is truncated.

Not all devices can operate in every mode. For example, the MCIAVI device is a playback device; it doesn't support the recording mode. The following modes can be retrieved by using [MCIWNDM_GETMODE](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getmode):

| Operating mode | MCI constant |
| --- | --- |
| not ready | MCI_MODE_NOT_READY |
| open | MCI_MODE_OPEN |
| paused | MCI_MODE_PAUSE |
| playing | MCI_MODE_PLAY |
| recording | MCI_MODE_RECORD |
| seeking | MCI_MODE_SEEK |
| stopped | MCI_MODE_STOP |

## See also

[MCIWNDM_GETMODE](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getmode)