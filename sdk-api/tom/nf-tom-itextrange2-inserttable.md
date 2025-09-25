# ITextRange2::InsertTable

## Description

Inserts a table in a range.

## Parameters

### `cCol` [in]

Type: **long**

The number of columns in the table.

### `cRow` [in]

Type: **long**

The number of rows in the table.

### `AutoFit` [in]

Type: **long**

Specifies how the cells fit the target space.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

If the range is nondegenerate, the table replaces the text in the range. The column widths are calculated according to the *AutoFit* parameter, and the borders are solid black with 0.5 point widths. To change these defaults, use the [ITextRange2::GetRow](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-getrow) method to obtain an [ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow) interface.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)