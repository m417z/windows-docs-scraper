# DateTime_SetMonthCalFont macro

## Syntax

```cpp
void DateTime_SetMonthCalFont(
   HWND  hdp,
   HFONT hfont,
   long  fRedraw
);
```

## Description

Sets the font to be used by the date and time picker (DTP) control's child month calendar control. You can use this macro or explicitly send the [DTM_SETMCFONT](https://learn.microsoft.com/windows/desktop/Controls/dtm-setmcfont) message.

## Parameters

### `hdp`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a DTP control.

### `hfont`

Type: **[HFONT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the font that will be set.

### `fRedraw`

Type: **long**

Specifies whether the control should be redrawn immediately upon setting the font. Setting this parameter to **TRUE** causes the control to redraw itself.