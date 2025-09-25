# MCIWndGetTimeFormat macro

## Syntax

```cpp
LONG MCIWndGetTimeFormat(
     hwnd,
     lp,
     len
);
```

## Return value

Type: **LONG**

Returns an integer corresponding to the MCI constant defining the time format.

## Description

The **MCIWndGetTimeFormat** macro retrieves the current time format of an MCI device in two forms: as a numerical value and as a string. You can use this macro or explicitly send the [MCIWNDM_GETTIMEFORMAT](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-gettimeformat) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `lp`

Pointer to a buffer to contain the null-terminated string form of the time format.

### `len`

Size, in bytes, of the buffer.

## Remarks

If the time format string is longer than the return buffer, MCIWnd truncates the string.

An MCI device can support one or more of the following time formats:

| Time format | MCI constant |
| --- | --- |
| Bytes | MCI_FORMAT_BYTES |
| Frames | MCI_FORMAT_FRAMES |
| Hours, minutes, seconds | MCI_FORMAT_HMS |
| Milliseconds | MCI_FORMAT_MILLISECONDS |
| Minutes, seconds, frames | MCI_FORMAT_MSF |
| Samples | MCI_FORMAT_SAMPLES |
| SMPTE 24 | MCI_FORMAT_SMPTE_24 |
| SMPTE 25 | MCI_FORMAT_SMPTE_25 |
| SMPTE 30 drop | MCI_FORMAT_SMPTE_30DROP |
| SMPTE 30 (non-drop) | MCI_FORMAT_SMPTE_30 |
| Tracks, minutes, seconds, frames | MCI_FORMAT_TMSF |

## See also

[MCIWNDM_GETTIMEFORMAT](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-gettimeformat)