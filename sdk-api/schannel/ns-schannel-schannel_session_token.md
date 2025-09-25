# SCHANNEL_SESSION_TOKEN structure

## Description

Specifies whether reconnections are enabled for an authentication session created by calling either the [InitializeSecurityContext (Schannel)](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) function or the [AcceptSecurityContext (Schannel)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) function.

## Members

### `dwTokenType`

Specifies the type of this structure. Set the value of this member to **SCHANNEL_SESSION**.

### `dwFlags`

Specifies whether reconnections are to be enabled or disabled. This member must be one of the following values.

| Value | Meaning |
| --- | --- |
| **SSL_SESSION_ENABLE_RECONNECTS**<br><br>1 | Reconnections are enabled. |
| **SSL_SESSION_DISABLE_RECONNECTS**<br><br>2 | Reconnections are disabled. |

## Remarks

Add a session token to a client context by using this structure as the value of the *pInput* parameter in a call to the [ApplyControlToken](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-applycontroltoken) function.

This API only applies to Session ID-based reconnects.