# DateTime_GetMonthCalFont macro

## Syntax

```cpp
HFONT DateTime_GetMonthCalFont(
   HWND hdp
);
```

## Return value

Type: **[HFONT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns an HFONT value that is the handle to the current font.

## Description

Gets the font that the date and time picker (DTP) control's child month calendar control is currently using. You can use this macro or send the [DTM_GETMCFONT](https://learn.microsoft.com/windows/desktop/Controls/dtm-getmcfont) message explicitly.

## Parameters

### `hdp`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a DTP control.