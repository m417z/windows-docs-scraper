# IDirectDrawPalette::SetEntries

## Description

Changes entries in a DirectDrawPalette object immediately.

## Parameters

### `unnamedParam1` [in]

Currently not used and must be set to 0.

### `unnamedParam2` [in]

First entry to be set.

### `unnamedParam3` [in]

Number of palette entries to be changed.

### `unnamedParam4` [in]

An array of [PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85)) structures that contains the palette entries that **SetEntries** uses to change the DirectDrawPalette object. The palette entries are 1 byte each if the DDPCAPS_8BITENTRIES flag is set, and 4 bytes otherwise. Each field is a color description.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOPALETTEATTACHED
* DDERR_NOTPALETTIZED
* DDERR_UNSUPPORTED

## Remarks

## See also

[IDirectDrawPalette](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawpalette)