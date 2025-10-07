# RKeyCloseKeyService function

The **RKeyCloseKeyService** function is not supported.

**Windows Server 2003:** The **RKeyCloseKeyService** function closes a key service handle opened by a previous call to the [**RKeyOpenKeyService**](https://learn.microsoft.com/windows/win32/seccrypto/rkeyopenkeyservice) function. Note that this behavior has changed with Windows Server 2003 with Service Pack 1 (SP1).

## Parameters

*hKeySvcCli* \[in\]

A [**KEYSVCC\_HANDLE**](https://learn.microsoft.com/windows/win32/seccrypto/keysvcc-handle) handle previously opened by [**RKeyOpenKeyService**](https://learn.microsoft.com/windows/win32/seccrypto/rkeyopenkeyservice). This value cannot be **NULL**.

*pReserved* \[in, out\]

Reserved. Set this value to **NULL**.

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

[**RKeyOpenKeyService**](https://learn.microsoft.com/windows/win32/seccrypto/rkeyopenkeyservice)

[**RKeyPFXInstall**](https://learn.microsoft.com/windows/win32/seccrypto/rkeypfxinstall)

