# ITextStrings::GetCch

## Description

Gets the count of characters for a selected string index.

## Parameters

### `iString` [in]

Type: **long**

The string index.

### `pcch` [out]

Type: **long***

The string character count.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The index is relative to the top of the collection, so *iString* = 0 returns the character count of the top string, *iString* = –1 returns that for the one below the top string, and so on.

## See also

[ITextStrings](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstrings)