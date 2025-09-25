# IDirectDrawPalette::GetEntries

## Description

Retrieves palette values from a DirectDrawPalette object.

## Parameters

### `unnamedParam1` [in]

Currently not used and must be set to 0.

### `unnamedParam2` [in]

Start of the entries to be retrieved sequentially.

### `unnamedParam3` [in]

Number of palette entries that can fit in the array that *lpEntries* specifies. The colors of the palette entries are returned in sequence, from the value of the *dwStartingEntry* parameter through the value of the *dwCount* parameter minus 1. (These parameters are set by [IDirectDrawPalette::SetEntries](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawpalette-setentries).)

### `unnamedParam4` [out]

An array of [PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85)) structures that receives the palette entries from the DirectDrawPalette object. The palette entries are 1 byte each if the DDPCAPS_8BITENTRIES flag is set, and 4 bytes otherwise. Each field is a color description.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOTPALETTIZED

## Remarks

## See also

[IDirectDrawPalette](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawpalette)