# SspiIsPromptingNeeded function

## Description

Indicates whether an error returned after a call to either the [InitializeSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) or the [AcceptSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) function requires an additional call to the [SspiPromptForCredentials](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspipromptforcredentialsa) function.

## Parameters

### `ErrorOrNtStatus` [in]

The error to test.

## Return value

**TRUE** if the error specified by the *ErrorOrNtStatus* parameter indicates that an additional call to [SspiPromptForCredentials](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspipromptforcredentialsa) is necessary; otherwise, **FALSE**.