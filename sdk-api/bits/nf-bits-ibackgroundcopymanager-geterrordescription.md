# IBackgroundCopyManager::GetErrorDescription

## Description

Retrieves a description for the specified error code.

## Parameters

### `hResult` [in]

Error code from a previous call to a BITS method.

### `LanguageId` [in]

Identifies the language identifier to use to generate the description. To create the language identifier, use the
[MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid) macro. For example, to specify U.S. English, use the following code sample.

`MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US)`

To retrieve the system's default user language identifier, use the following calls.

`LANGIDFROMLCID(GetThreadLocale())`

### `pErrorDescription` [out]

Null-terminated string that contains a description of the error. Call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *ppErrorDescription* when done.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Error code description was successfully retrieved. |
| **HRESULT_FROM_WIN32(ERROR_RESOURCE_LANG_NOT_FOUND)** | No string is available for the locale. |

## Remarks

Descriptions for HTTP errors are localized.

**Windows XP/2000:** Descriptions for HTTP errors are not localized.

#### Examples

The following example shows how to retrieve the description associated with an error code. The g_XferManager variable in the example is an
[IBackgroundCopyManager](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopymanager) interface pointer. For details on creating the
**IBackgroundCopyManager** interface pointer, see
[Connecting to the BITS Service](https://learn.microsoft.com/windows/desktop/Bits/connecting-to-the-bits-service).

```cpp
HRESULT hr = 0;
IBackgroundCopyJob* pJob = NULL;
WCHAR* pszDescription = NULL;

//Call fails because the third parameter is NULL.
hr = g_XferManager->CreateJob(L"DummyJob", BG_JOB_TYPE_DOWNLOAD, NULL, &pJob);
if (FAILED(hr))
{
  hr = g_XferManager->GetErrorDescription(hr, LANGIDFROMLCID(GetThreadLocale()), &pszDescription);
  if (SUCCEEDED(hr))
  {
    //Do something with pszDescription.
    CoTaskMemFree(pszDescription);
  }
}
```

## See also

[Handling Errors](https://learn.microsoft.com/windows/desktop/Bits/handling-errors)

[IBackgroundCopyError](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyerror)

[IBackgroundCopyJob::GetError](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-geterror)