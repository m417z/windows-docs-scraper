# MCIWndResume macro

## Syntax

```cpp
LONG MCIWndResume(
     hwnd
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndResume** macro resumes playback or recording content from the paused mode. This macro restarts playback or recording from the current position in the content. You can use this macro or explicitly send the [MCI_RESUME](https://learn.microsoft.com/windows/desktop/Multimedia/mci-resume) command.

## Parameters

### `hwnd`

Handle of the MCIWnd window.