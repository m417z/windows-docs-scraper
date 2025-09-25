# MCIWndChangeStyles macro

## Syntax

```cpp
LONG MCIWndChangeStyles(
     hwnd,
     mask,
     value
);
```

## Return value

Type: **LONG**

Returns zero.

## Description

The **MCIWndChangeStyles** macro changes the styles used by the MCIWnd window. You can use this macro or explicitly send the [MCIWNDM_CHANGESTYLES](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-changestyles) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `mask`

Mask that identifies the styles that can change. This mask is the bitwise OR operator of all styles that will be permitted to change.

### `value`

New style settings for the window. Specify zero for this parameter to turn off all styles identified in the mask. For a list of the available styles, see the MCIWndCreate function.

## Remarks

For an example of using **MCIWndChangeStyles**, see [Pausing and Resuming Playback](https://learn.microsoft.com/windows/desktop/Multimedia/pausing-and-resuming-playback).

## See also

[MCIWNDM_CHANGESTYLES](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-changestyles)