# ISyncMgrSynchronizeInvoke::UpdateItems

## Description

Programmatically starts an update for specified items.

## Parameters

### `dwInvokeFlags` [in]

Type: **DWORD**

Specifies how an item should be invoked using the [SYNCMGRINVOKEFLAGS](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrinvokeflags) enumeration values.

### `clsid` [in]

Type: **REFCLSID**

The CLSID of a registered application to be invoked for an update.

### `cbCookie` [in]

Type: **DWORD**

The size of *pCookie* data, in bytes.

### `pCookie` [in]

Type: **const BYTE***

A pointer to a private token that identifies an application. The token is passed in the [Initialize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-initialize) method.

## Return value

Type: **HRESULT**

This method supports the standard return values E_INVALIDARG, E_UNEXPECTED and E_OUTOFMEMORY, and the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The synchronization is successfully updated. |
| **E_FAIL** | The errors occur during a synchronization update. |

## See also

[ISyncMgrSynchronizeInvoke](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizeinvoke)

[Initialize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-initialize)

[SYNCMGRINVOKEFLAGS](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrinvokeflags)