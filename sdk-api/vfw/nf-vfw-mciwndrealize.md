# MCIWndRealize macro

## Syntax

```cpp
LONG MCIWndRealize(
     hwnd,
     fBkgnd
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndRealize** macro controls how an MCI window realized in the foreground or background. This macro also causes the palette for the MCI window to be realized in the process. You can use this macro or explicitly send the [MCIWNDM_REALIZE](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-realize) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `fBkgnd`

Background flag. Specify **TRUE** for this parameter for the window to be realized in the background or **FALSE** if the window can be realized in the foreground.

## Remarks

A common use for **MCIWndRealize** is to coordinate palette ownership between an MCI control and the application that contains it. The application can have the MCI window realize in the background and realize its own palette in the foreground.

If your application contains an MCI control, but does not need to realize its palette, you can use this macro to handle the WM_PALETTECHANGED and WM_QUERYNEWPALETTE messages, instead of using **RealizePalette**. However, it is usually easier to call the **SendMessage** function to forward the message to the MCIWnd window, which will automatically realize the palette.