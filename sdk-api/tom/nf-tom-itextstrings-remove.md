# ITextStrings::Remove

## Description

Removes a string from a string collection, starting at an index.

## Parameters

### `iString` [in]

Type: **long**

The string index.

### `cString` [in]

Type: **long**

The count of strings to remove.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |

## Remarks

The index is relative to the top of the collection, so *iString* = 0 removes the top string (*cString* must be 1), *iString* = –1 removes the one below the top string (and the top string if *cString* = 2), and so on.

## See also

[ITextStrings](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstrings)