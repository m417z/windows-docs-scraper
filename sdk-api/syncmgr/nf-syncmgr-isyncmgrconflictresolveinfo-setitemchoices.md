# ISyncMgrConflictResolveInfo::SetItemChoices

## Description

Sets the array of indexes that represents which items the user wants to keep. This method is used when the user chooses to apply the same operation to all selected conflicts of the same type from the same handler.

## Parameters

### `prgiConflictItemIndexes` [in]

Type: **UINT***

The array of indexes of items that the user wants to keep.

### `cChoices` [in]

Type: **UINT**

The number of item choices in *prgiConflictItemIndexes*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ISyncMgrConflictResolveInfo](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflictresolveinfo)

[ISyncMgrConflictResolveInfo::GetItemChoice](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrconflictresolveinfo-getitemchoice)