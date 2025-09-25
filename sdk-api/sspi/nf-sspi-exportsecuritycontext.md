# ExportSecurityContext function

## Description

The **ExportSecurityContext** function creates a serialized representation of a [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) that can later be imported into a different process by calling
[ImportSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-importsecuritycontexta). The process that imports the security context must be running on the same computer as the process that called **ExportSecurityContext**.

## Parameters

### `phContext` [in]

A handle of the security context to be exported.

### `fFlags` [in]

This parameter can be a bitwise-**OR** combination of the following values.

| Value | Meaning |
| --- | --- |
| **SECPKG_CONTEXT_EXPORT_RESET_NEW**<br><br>1 (0x1) | The new security context is reset to its initial state. |
| **SECPKG_CONTEXT_EXPORT_DELETE_OLD**<br><br>2 (0x2) | The old security context is deleted. |
| **SECPKG_CONTEXT_EXPORT_TO_KERNEL**<br><br>4 (0x4) | This value is not supported. <br><br>**Windows Server 2003 and Windows XP/2000:** The security context is to be exported to the kernel.This value is supported only in Schannel kernel mode. |

### `pPackedContext` [out]

A pointer to a buffer of type **SECBUFFER_EMPTY** that receives the [serialized](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) security context. When you have finished using this context, free it by calling the
[FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer) function.

### `pToken` [out, optional]

A pointer to receive the handle of the context's token.

When you have finished using the user token, release the handle by calling the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.

## Return value

If the function succeeds, the function returns SEC_E_OK.

If the function fails, it returns one of the following error codes.

| Return code | Description |
| --- | --- |
| **SEC_E_INSUFFICIENT_MEMORY** | There is not enough memory available to complete the requested action. |
| **SEC_E_INVALID_HANDLE** | The *phContext* parameter does not point to a valid handle. |
| **SEC_E_NOT_SUPPORTED** | Schannel kernel mode does not support this function. |

## See also

[FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer)

[ImportSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-importsecuritycontexta)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)