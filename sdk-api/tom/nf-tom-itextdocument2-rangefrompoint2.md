# ITextDocument2::RangeFromPoint2

## Description

Retrieves the degenerate range at (or nearest to) a particular point on the screen.

## Parameters

### `x` [in]

Type: **long**

The x-coordinate of a point, in screen coordinates.

### `y` [in]

Type: **long**

The y-coordinate of a point, in screen coordinates.

### `Type` [in]

Type: **long**

The alignment type of the specified point. For a list of valid values, see [ITextRange::GetPoint](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getpoint).

### `ppRange` [out, retval]

Type: **ITextRange2****

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)