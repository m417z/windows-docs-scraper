# ADsGetLastError function

## Description

The **ADsGetLastError** function retrieves the calling thread's last-error code value.

## Parameters

### `lpError` [out]

Type: **LPDWORD**

Pointer to the location that receives the error code.

### `lpErrorBuf` [out]

Type: **LPWSTR**

Pointer to the location that receives the null-terminated Unicode string that describes the error.

### `dwErrorBufLen` [in]

Type: **DWORD**

Size, in characters, of the *lpErrorBuf* buffer. If the buffer is too small to receive the error string, the string is truncated, but still null-terminated. A buffer, of at least 256 bytes, is recommended.

### `lpNameBuf` [out]

Type: **LPWSTR**

Pointer to the location that receives the null-terminated Unicode string that describes the name of the provider that raised the error.

### `dwNameBufLen` [in]

Type: **DWORD**

Size, in characters, of the *lpNameBuf* buffer. If the buffer is too small to receive the name of the provider, the string is truncated, but still null-terminated.

## Return value

Type: **HRESULT**

This method supports standard return values, as well as the following.

## Remarks

ADSI errors fall into two types according to the values of their facility code. The standard ADSI error codes have a facility code value of 0x5 and the extended ADSI error codes assume that of FACILITY_WIN32. The error values of the standard and extended ADSI error codes are of the forms of 0x80005xxx and 0x8007xxxx, respectively. Use the HRESULT_FACILITY(hr) macro to determine the ADSI error type.

**Note** The WinNT ADSI provider does not support **ADsGetLastError**.

The following code example shows how to get Win32 error codes and their descriptions using **ADsGetLastError**.

```cpp
if (FAILED(hr))
{
    wprintf(L"An error occurred.\n  HRESULT: %x\n",hr);
    // If facility is Win32, get the Win32 error
    if (HRESULT_FACILITY(hr)==FACILITY_WIN32)
    {
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
    }
}
```

If hr is 80071392, the code example returns the following.

```cpp
An error occurred.
    HRESULT: 80071392
    Error Code: 8305
    Error Text: 00002071: UpdErr: DSID-030502F1, problem 6005 (ENTRY_EXISTS), data 0
    Provider: LDAP Provider
```

**Note** The WinNT ADSI provider does not support **ADsGetLastError**.

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADSI Functions](https://learn.microsoft.com/windows/desktop/ADSI/adsi-functions)

[ADsSetLastError](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adssetlasterror)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)