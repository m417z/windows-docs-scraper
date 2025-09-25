# IBackgroundCopyJobHttpOptions2::GetHttpMethod

## Description

Retrieves a wide string containing the HTTP method name for the BITS transfer. By default, download jobs will be "GET", and upload and upload-reply jobs will be "BITS_POST".

## Parameters

### `method` [out]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The address of a pointer to a null-terminated string of wide characters. If successful, the method updates the pointer to point to a string containing the HTTP method name. When you're done with this string, free it with a call to [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBackgroundCopyJobHttpOptions2](https://learn.microsoft.com/windows/win32/api/bits10_2/nn-bits10_2-ibackgroundcopyjobhttpoptions2)