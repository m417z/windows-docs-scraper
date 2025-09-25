# ISyncMgrSynchronize::GetHandlerInfo

## Description

Obtains handler information.

## Parameters

### `ppSyncMgrHandlerInfo` [out]

Type: **[SYNCMGRHANDLERINFO](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgrhandlerinfo)****

A pointer to a [SYNCMGRHANDLERINFO](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgrhandlerinfo) structure.

## Return value

Type: **HRESULT**

This method supports the standard return values E_INVALIDARG, E_UNEXPECTED, and E_OUTOFMEMORY, and the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Handler information is returned successfully. |

## Remarks

The handler should use the [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) function to allocate memory.

## See also

[ISyncMgrSynchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronize)

[SYNCMGRHANDLERINFO](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgrhandlerinfo)