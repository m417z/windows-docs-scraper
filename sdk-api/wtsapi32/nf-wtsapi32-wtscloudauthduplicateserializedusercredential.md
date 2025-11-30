## Description

Duplicates an instance of *[WTS_SERIALIZED_USER_CREDENTIAL](https://learn.microsoft.com/windows/win32/api/wtsapi32/ns-wtsapi32-wts_serialized_user_credential)*.

## Syntax

```cpp
BOOL WINAPI WTSCloudAuthDuplicateSerializedUserCredential(
  [in] const WTS_SERIALIZED_USER_CREDENTIAL* userCredential,
  [out] WTS_SERIALIZED_USER_CREDENTIAL** duplicatedUserCredential
);
```

## Parameters

### `userCredential` [in]

The user credential obtained by calling *[WTSCloudAuthConvertAssertionToSerializedUserCredential](https://learn.microsoft.com/windows/win32/api/wtsapi32/nf-wtsapi32-wtscloudauthconvertassertiontoserializedusercredential)*.

### `duplicatedUserCredential` [out]

Receives a pointer to the duplicated instance of *WTS_SERIALIZED_USER_CREDENTIAL*. To free the allocated memory, call the *[WTSFreeMemoryEx](https://learn.microsoft.com/windows/win32/api/wtsapi32/nf-wtsapi32-wtsfreememoryexw)* function and pass *WTSTypeSerializedUserCredential* for the *WTSTypeClass* parameter.

## Return value

If the function succeeds, the return value is a nonzero value.
If the function fails, the return value is zero. To get extended error information, call the [`GetLastError'](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

## See also