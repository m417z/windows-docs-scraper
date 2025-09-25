# MI_DestinationOptions_AddProxyCredentials function

## Description

Adds credentials to authenticate against a proxy.

## Parameters

### `options` [in, out]

A pointer to a destination options structure.

### `credentials` [in]

Credentials used when communicating with the destination machine.

## Return value

This function returns MI_INLINE MI_Result.

## Remarks

Not all protocol transports support proxy configuration. Not all proxy servers support all authentication types. If the proxy requires dual-factor authentication this function can be called with both sets of credentials.