# MCIWndStep macro

## Syntax

```cpp
LONG MCIWndStep(
     hwnd,
     n
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndStep** macro moves the current position in the content forward or backward by a specified increment. You can use this macro or explicitly send the [MCI_STEP](https://learn.microsoft.com/windows/desktop/Multimedia/mci-step) command.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `n`

Step value. Negative values step the device through the content in reverse. The units for the step value depend on the current time format.