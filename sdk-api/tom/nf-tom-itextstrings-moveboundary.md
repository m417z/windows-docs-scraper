# ITextStrings::MoveBoundary

## Description

Moves the start boundary of a string, by index, for a selected number of characters.

## Parameters

### `iString` [in]

Type: **long**

The string index.

### `cch` [in]

Type: **long**

The selected number of characters to move the boundary.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The index is relative to the top of the collection, so *iString* = 0 moves the top string boundary, *iString* = –1 moves the boundary of the string below the top string, and so on.

## See also

[ITextStrings](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstrings)