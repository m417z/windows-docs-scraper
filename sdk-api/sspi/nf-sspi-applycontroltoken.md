# ApplyControlToken function

## Description

The **ApplyControlToken** function provides a way to apply a control token to a [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). A token can be received when the security context is being established by a call to
the [InitializeSecurityContext (Schannel)](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) function or with a per-message security service, such as verify or unseal.

This function is supported only by the Schannel [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSP).

This function is not supported in kernel mode.

This function allows additional or replacement tokens to be applied to a context.

## Parameters

### `phContext` [in]

A handle to the context to which the token is applied.

For information about the way the Schannel SSP notifies the remote party of the shutdown, see the Remarks section of [DecryptMessage (Schannel)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-decryptmessage). For additional information on the use of this function, see
[Shutting Down an Schannel Connection](https://learn.microsoft.com/windows/desktop/SecAuthN/shutting-down-an-schannel-connection).

### `pInput` [in]

A pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure that contains a pointer to a
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure that contains the input token to apply to the context.

## Return value

If the function succeeds, the function returns SEC_E_OK.

If the function fails, it returns a nonzero error code. The following error code is one of the possible error codes that can be returned.

| Return code | Description |
| --- | --- |
| **SEC_E_UNSUPPORTED_FUNCTION** | This value is returned by Schannel kernel mode to indicate that this function is not supported. |

## Remarks

The **ApplyControlToken** function can modify the context based on this token. Among the tokens that this function can add to the client context are [SCHANNEL_ALERT_TOKEN](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-schannel_alert_token) and [SCHANNEL_SESSION_TOKEN](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-schannel_session_token).

This function can be used to shut down the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) that underlies an existing Schannel connection. For information about how to do this, see [Shutting Down an Schannel Connection](https://learn.microsoft.com/windows/desktop/SecAuthN/shutting-down-an-schannel-connection).

## See also

[DecryptMessage (Schannel)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-decryptmessage)

[ImpersonateSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-impersonatesecuritycontext)

[SCHANNEL_ALERT_TOKEN](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-schannel_alert_token)

[SCHANNEL_SESSION_TOKEN](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-schannel_session_token)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)

[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer)

[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc)