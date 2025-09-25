# ITextRow::Reset

## Description

Resets a row.

## Parameters

### `Value` [in]

Type: **long**

The [tomRowUpdate](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) reset value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## See also

[ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow)