# MCIWndSeek macro

## Syntax

```cpp
LONG MCIWndSeek(
     hwnd,
     lPos
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndSeek** macro moves the playback position to the specified location in the content. You can use this macro or explicitly use the [MCI_SEEK](https://learn.microsoft.com/windows/desktop/Multimedia/mci-seek) command.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `lPos`

Position to seek. You can specify a position using the current time format, the MCIWND_START constant to designate the beginning of the content, or the MCIWND_END constant to designate the end of the content.