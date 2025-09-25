# ITextStrings::InsertNullStr

## Description

Inserts a **NULL** string in the collection at a selected string index.

## Parameters

### `iString` [in]

Type: **long**

The string index.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The index is relative to the top of the collection, so *iString* = 0 inserts the **NULL** string at the top, *iString* = –1 inserts it below the top string, and so on.

## See also

[ITextStrings](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstrings)