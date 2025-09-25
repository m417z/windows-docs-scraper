# ITextStrings::Append

## Description

Appends a string to the string at the specified index in the collection.

## Parameters

### `pRange` [in]

Type: **[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)***

The string to append.

### `iString` [in]

Type: **long**

The string index.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

The index is relative to the top of the collection, so if *iString* is equal to 0 the string is inserted at the top. If *iString* is equal to –1, it is inserted below the top string, and so on.

## See also

[ITextStrings](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstrings)