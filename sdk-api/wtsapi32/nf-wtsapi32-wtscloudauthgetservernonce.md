## Description

Requests a server nonce from the Cloud Authentication security support provider.

## Syntax

```cpp
BOOL WINAPI WTSCloudAuthGetServerNonce(
    [in] WTS_CLOUD_AUTH_HANDLE cloudAuthHandle,
    [out] PWSTR* serverNonce
);
```

## Parameters

### `cloudAuthHandle` [in]

The cloud authentication handle obtained by calling *WTSCloudAuthOpen*.

### `serverNonce` [out]

Receives the generated server nonce if the function succeeds. To free the allocated memory, call the *[WTSFreeMemoryEx](https://learn.microsoft.com/windows/win32/api/wtsapi32/nf-wtsapi32-wtsfreememoryexw)* function and pass *WTSTypeCloudAuthServerNonce* for the *WTSTypeClass* parameter.

## Return value

If the function succeeds, the return value is a nonzero value. If the function fails, the return value is zero. To get extended error information, call the [`GetLastError`](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

The server nonce is required to build an [assertion](https://learn.microsoft.com/openspecs/windows_protocols/ms-rdpbcgr/ba819b6b-257a-466f-b8e5-f262d78677f7) to authenticate to the server when using Entra authentication. The caller is responsible for transporting the server nonce to the client to use for the purposes of constructing the assertion.