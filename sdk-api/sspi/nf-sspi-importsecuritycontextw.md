# ImportSecurityContextW function

## Description

The **ImportSecurityContext** function imports a [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The security context must have been exported to the process calling **ImportSecurityContext** by a previous call to [ExportSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-exportsecuritycontext).

## Parameters

### `pszPackage` [in]

A string that contains the name of the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to which the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) was exported.

### `pPackedContext` [in]

A pointer to a buffer that contains the [serialized](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) security context created by [ExportSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-exportsecuritycontext).

### `Token` [in, optional]

A handle to the context's token.

### `phContext` [out]

A handle of the new security context created from *pPackedContext*. When you have finished using the context, delete it by calling the [DeleteSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-deletesecuritycontext) function.

## Return value

If the function succeeds, the function returns SEC_E_OK.

If the function fails, it returns one of the following error codes.

| Return code | Description |
| --- | --- |
| **SEC_E_UNKNOWN_CREDENTIALS** | The credentials supplied to the package were not recognized. |
| **SEC_E_NO_CREDENTIALS** | No credentials are available in the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). |
| **SEC_E_NOT_OWNER** | The caller of the function does not have the necessary credentials. |
| **SEC_E_INSUFFICIENT_MEMORY** | There is not enough memory available to complete the requested action. |
| **SEC_E_INTERNAL_ERROR** | An error occurred that did not map to an SSPI error code. |

## See also

[ExportSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-exportsecuritycontext)

[FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)

## Remarks

> [!NOTE]
> The sspi.h header defines ImportSecurityContext as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).