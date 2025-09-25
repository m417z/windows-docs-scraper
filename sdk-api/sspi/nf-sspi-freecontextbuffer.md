# FreeContextBuffer function

## Description

The **FreeContextBuffer** function enables callers of [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) functions to free memory buffers allocated by the security package.

## Parameters

### `pvContextBuffer` [in]

A pointer to memory to be freed.

## Return value

If the function succeeds, the function returns SEC_E_OK.

If the function fails, it returns a nonzero error code.

## Remarks

Memory buffers are typically allocated by the [InitializeSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) and [AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) functions.

The **FreeContextBuffer** function can free any memory allocated by a security package.

## See also

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)