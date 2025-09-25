# ISCPSession::BeginSession

## Description

The **BeginSession** method indicates beginning of a transfer session. It can be used to optimize operations that need to occur only once per transfer session.

## Parameters

### `pIDevice` [in]

Pointer to an [IMDSPDevice](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice) object.

### `pCtx` [in]

Pointer to the context.

### `dwSizeCtx` [in]

**DWORD** containing the size of context.

## Return value

If the method succeeds, it returns S_OK. If the method fails, it returns an **HRESULT** error code.

## See also

[ISCPSession Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsession)