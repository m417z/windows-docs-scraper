# IBackgroundCopyError::GetErrorDescription

## Description

Retrieves the error text associated with the error.

## Parameters

### `LanguageId` [in]

Identifies the locale to use to generate the description. To create the language identifier, use the
[MAKELANGID](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-makelangid) macro. For example, to specify U.S. English, use the following code sample.

`MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US)`

To retrieve the system's default user language identifier, use the following calls.

`LANGIDFROMLCID(GetThreadLocale())`

### `pErrorDescription` [out]

Null-terminated string that contains the error text associated with the error. Call the
[CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *ppErrorDescription* when done.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Description of the error was successfully retrieved. |
| **E_OUTOFMEMORY** | Not enough memory is available to complete the operation. |
| **E_INVALIDARG** | The *LanguageId* parameter cannot be 0. |
| **HRESULT_FROM_WIN32(ERROR_RESOURCE_LANG_NOT_FOUND)** | No string is available for the locale. |

## Remarks

You can also call the
[IBackgroundCopyManager::GetErrorDescription](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopymanager-geterrordescription) method to retrieve the error text associated with an error code.

Descriptions for HTTP errors are localized.

**Windows XP/2000:** Descriptions for HTTP errors are not localized.

#### Examples

See the example code in the
[Handling Errors](https://learn.microsoft.com/windows/desktop/Bits/handling-errors) topic.

## See also

[IBackgroundCopyError::GetError](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyerror-geterror)

[IBackgroundCopyError::GetErrorContextDescription](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyerror-geterrorcontextdescription)

[IBackgroundCopyError::GetFile](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyerror-getfile)

[IBackgroundCopyManager::GetErrorDescription](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopymanager-geterrordescription)