## Description

Gets the config info associated with the provider ID.

## Parameters

### `providerID`

Type: \_In\_ **[PCWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A string containing the provider ID.

### `configStringBufferLength`

Type: \_Inout\_ **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

A pointer to the buffer length (the size of *configString* in chars).

### `configString`

Type: \_Out\_writes\_to\_opt\_(*configStringBufferLength, *configStringBufferLength) **[PWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A buffer which, if the function completes successfully, will contain the config info.

If the buffer isn't large enough to hold the data, then the function returns **ERROR_MORE_DATA**, and stores the required buffer size in the variable pointed to by *configStringBufferLength*. In that case, the contents of the *configString* buffer are undefined.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

## Remarks

## See also