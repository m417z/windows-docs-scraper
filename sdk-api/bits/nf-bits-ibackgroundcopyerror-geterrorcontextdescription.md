# IBackgroundCopyError::GetErrorContextDescription

## Description

Retrieves the description of the context in which the error occurred.

## Parameters

### `LanguageId` [in]

Identifies the locale to use to generate the description. To create the language identifier, use the
[MAKELANGID](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-makelangid) macro. For example, to specify U.S. English, use the following code sample.

`MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US)`

To retrieve the system's default user language identifier, use the following calls.

`LANGIDFROMLCID(GetThreadLocale())`

### `pContextDescription` [out]

Null-terminated string that contains the description of the context in which the error occurred. Call the
[CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *ppContextDescription* when done.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Description of the context was successfully retrieved. |
| **E_OUTOFMEMORY** | Not enough memory is available to complete the operation. |
| **E_INVALIDARG** | The *LanguageId* parameter cannot be 0. |
| **HRESULT_FROM_WIN32(ERROR_RESOURCE_LANG_NOT_FOUND)** | No string is available for the locale. |

## See also

[IBackgroundCopyError::GetError](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyerror-geterror)

[IBackgroundCopyError::GetErrorDescription](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyerror-geterrordescription)

[IBackgroundCopyError::GetFile](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyerror-getfile)