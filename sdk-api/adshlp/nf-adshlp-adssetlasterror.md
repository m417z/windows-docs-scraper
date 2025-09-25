# ADsSetLastError function

## Description

The **ADsSetLastError** sets the last-error code value for the calling thread. Directory service providers can use this function to set extended errors. The function saves the error data in a per-thread data structure. **ADsSetLastError** operates similar to the [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) function.

## Parameters

### `dwErr` [in]

Type: **DWORD**

The error code that occurred. If this is an error defined by Windows, *pszError* is ignored. If this is ERROR_EXTENDED_ERROR, it indicates the provider has a network-specific error to report.

### `pszError` [in]

Type: **LPWSTR**

The null-terminated Unicode string that describes the network-specific error.

### `pszProvider` [in]

Type: **LPWSTR**

The null-terminated Unicode string that names the ADSI provider that raised the error.

## Remarks

In a custom implementation of an ADSI provider, for example, an LDAP provider, you can set an operation error message as follows.

```cpp
ADsSetLastError(HRESULT_FROM_WIN32(ERROR_DS_OPERATIONS_ERROR),
                L"ERROR_DS_OPERATIONS_ERROR",
                L"LDAP Provider");
```

The user can use the following code example to examine this operation code.

```cpp
DWORD dwLastError;
WCHAR szErrorBuf[MAX_PATH];
WCHAR szNameBuf[MAX_PATH];
// Get extended error value.
HRESULT hr_return =S_OK;
hr_return = ADsGetLastError( &dwLastError,
                               szErrorBuf,
                               MAX_PATH,
                               szNameBuf,
                               MAX_PATH);
if (SUCCEEDED(hr_return))
{
    wprintf(L"Error Code: %d\n Error Text: %ws\n Provider: %ws\n", dwLastError, szErrorBuf, szNameBuf);
}
```

The previous code example produces the following output for the operations error code set above.

```cpp
Error value: 80072020
Error Text: ERROR_DS_OPERATIONS_ERROR
Provider: LDAP Provider
```

If you use **ERROR_DS_OPERATIONS_ERROR** without invoking the HRESULT_FROM_WIN32 macro when setting the error, the following output is returned.

```cpp
Error value: 2020
Error Text: ERROR_DS_OPERATIONS_ERROR
Provider: LDAP Provider
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADSI Functions](https://learn.microsoft.com/windows/desktop/ADSI/adsi-functions)

[ADsGetLastError](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsgetlasterror)

[SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror)