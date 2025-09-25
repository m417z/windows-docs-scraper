# WsRevokeSecurityContext function

## Description

Revokes a security context. Can only be called on the server side.
Further requests using this security context will fail and a fault will be sent to the client.

This function can be used when the server knows that no more messages are
coming and does not want to wait for the client or the context timeouts to
trigger the reclaiming of resources, or when the server wants to engage in
active context management.

## Parameters

### `securityContext` [in]

The security context to be revoked.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.