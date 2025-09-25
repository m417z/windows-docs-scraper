# ISyncMgrSynchronize::EnumSyncMgrItems

## Description

Obtains the
[ISyncMgrEnumItems](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrenumitems) interface for the items that are handled by a registered application.

## Parameters

### `ppSyncMgrEnumItems` [out]

Type: **[ISyncMgrEnumItems](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrenumitems)****

The address of the variable that receives a pointer to a valid
[ISyncMgrEnumItems](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrenumitems) interface.

## Return value

Type: **HRESULT**

This method supports the standard return values E_INVALIDARG, E_UNEXPECTED, and E_OUTOFMEMORY, and the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The enumeration interface is returned successfully. |
| **S_SYNCMGR_MISSINGITEMS** | The enumeration interface object is returned successfully, but some items are missing. When this success code is returned, the synchronization manager does not remove any stored preferences for ItemIds that are not returned in the enumerator. |

## Remarks

The enumeration object that this method creates implements the
[ISyncMgrEnumItems](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrenumitems) interface, which is a standard enumeration interface that contains the [Next](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrenumitems-next), [Reset](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrenumitems-reset), [Clone](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrenumitems-clone), and [Skip](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrenumitems-skip) methods.

## See also

[ISyncMgrEnumItems](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrenumitems)

[ISyncMgrSynchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronize)