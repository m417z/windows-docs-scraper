# SHCreateShellPalette function

## Description

Creates a halftone palette for the specified device context.

## Parameters

### `hdc` [in, optional]

Type: **HDC**

The device context.

## Return value

Type: **HPALETTE**

Returns the palette if successful; otherwise 0.

## Remarks

This function behaves the same as [CreateHalftonePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createhalftonepalette). The palette that is returned depends on the device context in the following way:

* If *hdc* is set to **NULL**, a full palette is returned.
* If the device context is indexed, a full palette is returned.
* If the device context is not indexed, a default palette (VGA colors) is returned.