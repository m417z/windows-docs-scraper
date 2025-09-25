# ITextStrings::Add

## Description

Adds a string to the end of the collection.

## Parameters

### `bstr` [in]

Type: **BSTR**

The string. The value can be **NULL** for a null string.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

Adding an item to the end of a collection is like pushing a parameter onto the stack.

## See also

[ITextStrings](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstrings)