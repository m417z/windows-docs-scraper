# IWTSProtocolShadowCallback::InvokeTargetShadow

## Description

[**IWTSProtocolShadowCallback::InvokeTargetShadow** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolShadowCallback::InvokeTargetShadow](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolshadowcallback-invoketargetshadow).]

Instructs the Remote Desktop Services service to begin the target side of the shadow and passes any information that must be exchanged between the client and the target.

## Parameters

### `pTargetServerName` [in]

A pointer to a string that contains the name of the shadow target server.

### `TargetSessionId` [in]

An integer that specifies the ID of the target session to shadow.

### `pParam1` [in]

A pointer to a byte that contains an arbitrary parameter.

### `Param1Size` [in]

An integer that contains the size, in bytes, of the value referenced by the *pParam1* parameter.

### `pParam2` [in]

A pointer to a byte that contains an arbitrary parameter.

### `Param2Size` [in]

An integer that contains the size, in bytes, of the value referenced by the *pParam2* parameter.

### `pParam3` [in]

A pointer to a byte that contains an arbitrary parameter.

### `Param3Size` [in]

An integer that contains the size, in bytes, of the value referenced by the *pParam3* parameter.

### `pParam4` [in]

A pointer to a byte that contains an arbitrary parameter.

### `Param4Size` [in]

An integer that contains the size, in bytes, of the value referenced by the *pParam4* parameter.

### `pClientName` [in]

A pointer to a string that contains the name of the shadow client.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The four parameters *pParam1*, *pParam2*, *pParam3*, and *pParam4* can contain any information that must be exchanged between the shadow client and the shadow target. The Remote Desktop Services service passes the information without modification.

## See also

[IWTSProtocolShadowCallback](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolshadowcallback)