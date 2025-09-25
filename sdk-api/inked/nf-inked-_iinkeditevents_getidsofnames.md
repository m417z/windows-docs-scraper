# IInkEditEvents_GetIDsOfNames function

## Description

Maps a set of names to a corresponding set of DISPIDs.

## Parameters

### `This`

The [IInkEditEvents interface](https://learn.microsoft.com/windows/win32/api/inked/nn-inked-_iinkeditevents) object.

### `riid`

Reserved. Use IID_NULL.

### `rgszNames`

Address of an array of wide-character strings that contain the names to be mapped.

### `cNames`

Size of the array given by the *rgszNames* parameter.

### `lcid`

Locale context in which to interpret the names. Can be **NULL**.

### `rgDispId`

Pointer to an array that receives the DISPIDs. Each element of receives an identifier that corresponds to one of the names passed in the *rgszNames* parameter.

## Remarks

## See also