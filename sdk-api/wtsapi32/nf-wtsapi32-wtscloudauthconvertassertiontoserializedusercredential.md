## Description

Validates the assertion and computes the serialized credential from the [assertion](https://learn.microsoft.com/openspecs/windows_protocols/ms-rdpbcgr/ba819b6b-257a-466f-b8e5-f262d78677f7).

## Syntax

```cpp
BOOL WINAPI WTSCloudAuthConvertAssertionToSerializedUserCredential(
  [in] WTS_CLOUD_AUTH_HANDLE cloudAuthHandle,
  [in] reads_bytes_(assertionLength) PCSTR assertion,
  [in] ULONG assertionLength,
  [in] z_ PCWSTR resourceId,
  [out] WTS_SERIALIZED_USER_CREDENTIAL** userCredential
);
```

## Parameters

### `cloudAuthHandle` [in]

The cloud authentication handle obtained by calling [WTSCloudAuthOpen](https://learn.microsoft.com/windows/win32/api/wtsapi32/nf-wtsapi32-wtscloudauthopen).

### `reads_bytes_(assertionLength)` PCSTR assertion [in]

A pointer to the assertion.

### `ULONG` assertionLength [in]

The size of the assertion string, in bytes.

### `z_` PCWSTR resourceId [in]

The expected identifier of the Resource App registered in Entra ID. This is used to ensure that the assertion targets the expected Resource App.

### `WTS_SERIALIZED_USER_CREDENTIAL**` userCredential [out]

Receives a pointer to an instance of `WTS_SERIALIZED_USER_CREDENTIAL` containing the serialized credential if the function succeeds. To free the allocated memory, call the `WTSFreeMemoryEx` function and pass `WTSTypeSerializedUserCredential` for the `WTSTypeClass` parameter.

## Return value

If the function succeeds, the return value is a nonzero value. If the function fails, the return value is zero. To get extended error information, call the [`GetLastError`](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

| Error Code | Description |
|---|---------------------------------|
| HRESULT_FROM_NT(STATUS_AAD_CLOUDAP_E_APNONCE_INVALID) | The server nonce has expired. |
| HRESULT_FROM_NT(STATUS_AAD_CLOUDAP_E_BAD_DEVICE_ACCESS_TOKEN_FORMAT) | The format of the access token is invalid. |
| HRESULT_FROM_NT(STATUS_AAD_CLOUDAP_E_ASSERTION_MALFORMED) | The format of the assertion is invalid. |
| HRESULT_FROM_NT(STATUS_AAD_CLOUDAP_E_INVALID_TENANT) | The Entra ID tenant specified in the server nonce or the assertion is invalid. |
| HRESULT_FROM_NT(STATUS_AAD_CLOUDAP_E_INVALID_DEVICE) | The target device specified in the server nonce or the assertion is invalid. |
| HRESULT_FROM_NT(STATUS_AAD_CLOUDAP_E_INVALID_ACCESS_TOKEN) | The access token is invalid. |
| HRESULT_FROM_NT(STATUS_AAD_CLOUDAP_E_INVALID_BINDING_KEY_ID) | The binding key specified in the assertion does not match the binding key specified in the access token. |
| HRESULT_FROM_NT(STATUS_AAD_CLOUDAP_E_CANT_FIND_ROOT_CERT) | The root certificate associated with the access token's signature cannot be found. |
| HRESULT_FROM_NT(STATUS_AAD_CLOUDAP_E_ASSERTION_INVALID) | The resource URL in the assertion does not match the audience specified in the access token. |
| HRESULT_FROM_NT(STATUS_AAD_CLOUDAP_E_CALLER_MISMATCH) | The specified resource ID does not match the audience specified in the access token. |

The STATUS_AAD_CLOUDAP_E_* error codes are defined in winnt.h and ntstatus.h.

## Remarks

The client constructs the assertion, and the protocol is responsible for transporting the assertion to the server. The output serialized credentials can be used in `WTSCloudAuthNetworkLogonWithSerializedCredentials` to perform a network logon and additional authorization. Later, they can also be used in `IWRdsProtocolConnection2::GetSerializedUserCredentials` where a protocol can provide serialized credentials to the Remote Desktop Services service which performs an interactive logon on their behalf.