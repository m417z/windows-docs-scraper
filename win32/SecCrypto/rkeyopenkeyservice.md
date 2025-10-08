# RKeyOpenKeyService function

The **RKeyOpenKeyService** function is not supported.

**Windows Server 2003:** The **RKeyOpenKeyService** function establishes a connection to a remote computer and opens a key service handle. The key service handle can subsequently be used by the [**RKeyPFXInstall**](https://learn.microsoft.com/windows/win32/seccrypto/rkeypfxinstall) function. Note that this behavior has changed with Windows Server 2003 with Service Pack 1 (SP1).

## Parameters

*pszMachineName* \[in\]

Long pointer to a null-terminated string that represents the computer where the key service handle will be opened.

*OwnerType* \[in\]

[**KEYSVC\_TYPE**](https://learn.microsoft.com/windows/win32/seccrypto/keysvc-type) value that represents the key type. The only supported value is **KeySvcMachine**.

*pwszOwnerName* \[in\]

Reserved. Set this value to **NULL**.

*pAuthentication* \[in\]

A pointer to a **void** that represents the authentication settings. This pointer can point to a value of zero or the following value.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------|
| **RKEYSVC\_CONNECT\_SECURE\_ONLY**<br> | The client requires mutual authentication. If this value is specified, fallback to NTLM will fail.<br> |

*pReserved* \[in, out\]

Reserved. Set this value to **NULL**.

*phKeySvcCli* \[out\]

A pointer to a [**KEYSVCC\_HANDLE**](https://learn.microsoft.com/windows/win32/seccrypto/keysvcc-handle) that receives the opened key service handle. When you have finished using the handle, free the resource by calling the [**RKeyCloseKeyService**](https://learn.microsoft.com/windows/win32/seccrypto/rkeyclosekeyservice) function.

## Return value

If the function is successful, the return value is S\_OK.

If the function fails, the return value is a **ULONG** that indicates the error.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Rkeysvcc.h |

## See also

[**RKeyCloseKeyService**](https://learn.microsoft.com/windows/win32/seccrypto/rkeyclosekeyservice)

[**RKeyPFXInstall**](https://learn.microsoft.com/windows/win32/seccrypto/rkeypfxinstall)

