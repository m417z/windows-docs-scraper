# ITextRange2::AddSubrange

## Description

Adds a subrange to this range.

## Parameters

### `cp1` [in]

Type: **long**

The active-end character position of the subrange.

### `cp2` [in]

Type: **long**

The anchor-end character position of the subrange.

### `Activate` [in]

Type: **long**

The activate parameter. If this parameter is **tomTrue**, the new subrange is the active subrange, with *cp1* as the active end, and *cp2* the anchor end.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)