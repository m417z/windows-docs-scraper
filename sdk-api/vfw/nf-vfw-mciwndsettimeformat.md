# MCIWndSetTimeFormat macro

## Syntax

```cpp
LONG MCIWndSetTimeFormat(
     hwnd,
     lp
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndSetTimeFormat** macro sets the time format of an MCI device. You can use this macro or explicitly send the [MCIWNDM_SETTIMEFORMAT](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-settimeformat) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `lp`

Pointer to a buffer containing the null-terminated string indicating the time format. Specify "frames" to set the time format to frames, or "ms" to set the time format to milliseconds.

## Remarks

An application can specify time formats other than frames or milliseconds as long as the formats are supported by the MCI device. Noncontinuous formats, such as tracks and SMPTE, can cause the trackbar to behave erratically. For these time formats, you might want to turn off the toolbar by using the [MCIWndChangeStyles](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mciwndchangestyles) macro and specifying the MCIWNDF_NOPLAYBAR window style.

If you want to set the time format to frames or milliseconds, you can also use the **MCIWndUseFrames** or **MCIWndUseTime** macro. For a list of time formats, see the **MCIWndGetTimeFormat** macro.