# IMEAPPLETUI structure

## Description

Used by [IImePadApplet::CreateUI](https://learn.microsoft.com/windows/desktop/api/imepad/nf-imepad-iimepadapplet-createui) to specify applet window style.

## Members

### `hwnd`

Window handle created by applet window.

### `dwStyle`

Applet window style. The style is a combination of **IPAWS_*** flags; see the Remarks of [IImePad::Request](https://learn.microsoft.com/windows/desktop/api/imepad/nf-imepad-iimepad-request) for the possible **IPAWS_*** flags.

### `width`

The applet window's initial width.

### `height`

The applet window's initial height.

### `minWidth`

Minimum width of the applet window. Valid only when **IPAWS_MINWIDTHFIXED** style is set in *dwStyle*.

### `minHeight`

Minimum height of applet window. Valid only when **IPAWS_MINHEIGHTFIXED** is set in *dwStyle*.

### `maxWidth`

Maximum width of applet window. Valid only when **IPAWS_MAXWIDTHFIXED** is set in *dwStyle*.

### `maxHeight`

Maximum height of applet window. Valid only when **IPAWS_MAXHEIGHTFIXED** is set in *dwStyle*.

### `lReserved1`

Reserved.

### `lReserved2`

Reserved.