# IWRdsProtocolShadowConnection::DoTarget

## Description

Requests that the protocol start the target side of a shadow connection.

## Parameters

### `pParam1` [in]

A pointer to a buffer that contains an arbitrary parameter.

### `Param1Size` [in]

An integer that contains the size, in bytes, of the value referenced by the *pParam1* parameter.

### `pParam2` [in]

A pointer to a buffer that contains an arbitrary parameter.

### `Param2Size` [in]

An integer that contains the size, in bytes, of the value referenced by the *pParam2* parameter.

### `pParam3` [in]

A pointer to a buffer that contains an arbitrary parameter.

### `Param3Size` [in]

An integer that contains the size, in bytes, of the value referenced by the *pParam3* parameter.

### `pParam4` [in]

A pointer to a buffer that contains an arbitrary parameter.

### `Param4Size` [in]

An integer that contains the size, in bytes, of the value referenced by the *pParam4* parameter.

### `pClientName` [in]

A pointer to a string that contains the name of the shadow client.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The four parameters *pParam1*, *pParam2*, *pParam3*, and *pParam4* can contain any information that must be exchanged between the shadow client and the shadow target. The Remote Desktop Services service passes the information through without modification.

## See also

[IWRdsProtocolShadowConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolshadowconnection)