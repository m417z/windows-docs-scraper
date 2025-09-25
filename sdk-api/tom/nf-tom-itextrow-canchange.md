# ITextRow::CanChange

## Description

Determines whether changes can be made to this row.

## Parameters

### `pValue` [out, retval]

Type: **long***

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) indicating whether the row can be edited. It is **tomTrue** only if the row can be edited. The *pB* parameter can be **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The row can be changed only if no part of an associated range is protected and the associated document isn't read only.

## See also

[ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow)