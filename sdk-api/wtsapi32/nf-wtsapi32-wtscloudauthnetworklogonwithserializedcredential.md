## Description

Performs a network logon using the provided serialized credentials.

## Syntax

```cpp
BOOL WINAPI WTSCloudAuthNetworkLogonWithSerializedCredential(
    [in]  WTS_CLOUD_AUTH_HANDLE cloudAuthHandle,
    [in]  WTS_SERIALIZED_USER_CREDENTIAL* userCredential,
    [out] HANDLE* tokenHandle
);
```

## Parameters

### `cloudAuthHandle` [in]

The cloud authentication handle obtained by calling [`WTSCloudAuthOpen`](https://learn.microsoft.com/windows/win32/api/wtsapi32/nf-wtsapi32-wtscloudauthopen).

### `userCredential` [in]

The serialized credential obtained by calling [`WTSCloudAuthConvertAssertionToSerializedCredential`](https://learn.microsoft.com/windows/win32/api/wtsapi32/nf-wtsapi32-wtscloudauthconvertassertiontoserializedusercredential).

### `tokenHandle` [out]

Receives a handle that represents the user token if the function succeeds. Use [`CloseHandle`](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle) to close the handle.

## Return value

If the function succeeds, the return value is a nonzero value. If the function fails, the return value is zero. To get extended error information, call the [`GetLastError`](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

The user token handle can be used to perform additional checks by, for instance, calling [`CheckTokenMembership`](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-checktokenmembership).