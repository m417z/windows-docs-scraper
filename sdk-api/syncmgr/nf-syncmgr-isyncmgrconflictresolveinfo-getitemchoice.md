# ISyncMgrConflictResolveInfo::GetItemChoice

## Description

Gets the index of an item that the user wants to keep.

## Parameters

### `iChoice` [in]

Type: **UINT**

The item that the user wants to keep.

### `piChoiceIndex` [out]

Type: **UINT***

The index into the conflict's item array. This value is passed to the resolver for subsequent conflicts in the same conflict set if the user chooses to apply the same operation to all selected conflicts of the same type from the same handler.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ISyncMgrConflictResolveInfo](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflictresolveinfo)

[ISyncMgrConflictResolveInfo::SetItemChoices](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrconflictresolveinfo-setitemchoices)