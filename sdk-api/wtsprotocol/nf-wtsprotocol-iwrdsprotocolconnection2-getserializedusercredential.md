## Description

Returns a serialized user credential.

## Syntax

```cpp
HRESULT GetSerializedUserCredential(
    [out] WRDS_SERIALIZED_USER_CREDENTIAL** userCredential);
```

## Parameters

### `userCredential` [out]

Receives a pointer to an instance of **WTS_SERIALIZED_USER_CREDENTIAL** containing the serialized credential if the function succeeds. To free the allocated memory, the Remote Desktop Services service calls the *[WTSFreeMemoryEx](https://learn.microsoft.com/windows/win32/api/wtsapi32/nf-wtsapi32-wtsfreememoryexw)* function and pass **WTSTypeSerializedUserCredential** for the *WTSTypeClass* parameter.
Protocol implementations can transfer the ownership of the credential they obtained using **WTSCloudAuthConvertAssertionToSerializedUserCredential** (recommended) after which they should not use the credential anymore. Alternatively, protocol implementations can use **WTSCloudAuthDuplicateSerializedUserCredential*** to duplicate the serialized credentials obtained from **WTSCloudAuthConvertAssertionToSerializedUserCredential**.

## Return value

If the function succeeds, the function returns **S_OK**. If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see **[Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values)**.

## Remarks

If your protocol both returns an **HRESULT** error code in this method and in **[IWRdsProtocolConnection::GetUserCredentials](https://learn.microsoft.com/windows/win32/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-getusercredentials), WinLogon will display a logon screen to request credentials. If your protocol returns S_OK, the credentials will be passed to WinLogon to log on the user.