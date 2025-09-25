## Description

The protocol stack uses this method to return the session ID to be used for enhanced fast reconnect.

## Parameters

### `pSessionIdArray`

An array of session IDs that match the enhanced fast reconnect criteria.

### `dwSessionCount`

The size of the *pSessionIdArray* array (in elements).

### `pResultSessionId`

Pointer to LONG variable to receive the resultant session ID.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

## See also

[IWRdsEnhancedFastReconnectArbitrator](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsenhancedfastreconnectarbitrator)