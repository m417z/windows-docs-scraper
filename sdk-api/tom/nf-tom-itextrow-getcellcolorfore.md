# ITextRow::GetCellColorFore

## Description

Gets the foreground color of the active cell.

## Parameters

### `pValue` [out, retval]

Type: **long***

The foreground color.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **S_OK**. If the method fails, it returns the following COM error code. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |

## See also

[ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow)

[ITextRow::SetCellColorFore](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrow-setcellcolorfore)