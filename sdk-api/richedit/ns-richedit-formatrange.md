# FORMATRANGE structure

## Description

Information that a rich edit control uses to format its output for a particular device. This structure is used with the [EM_FORMATRANGE](https://learn.microsoft.com/windows/win32/controls/em-formatrange) message.

## Members

### `hdcTarget`

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An HDC for the target device to format for.

### `hdc`

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A HDC for the device to render to, if [EM_FORMATRANGE](https://learn.microsoft.com/windows/win32/controls/em-formatrange) is being used to send the output to a device.

### `rc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The area within the *rcPage* rectangle to render to. Units are measured in twips.

### `rcPage`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The entire area of a page on the rendering device. Units are measured in twips.

### `chrg`

Type: **[CHARRANGE](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charrange)**

The range of characters to format.

## Remarks

**hdcTarget** contains the HDC to format for, which is usually the same as the HDC specified by **hdc** but can be different. For example, if you create a print preview module, **hdc** is the HDC of the window in which the output is viewed, and **hdcTarget** is the HDC for the printer.

The values for **rc** and **rcPage** can be obtained by using [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps).

## See also

[EM_FORMATRANGE](https://learn.microsoft.com/windows/win32/controls/em-formatrange)