# ItsPubPlugin2::DeletePersonalDesktopAssignment

## Description

Called to delete a mapping between the specified user and a virtual machine in a personal virtual desktop collection.

## Parameters

### `userId` [in]

A null-terminated string that contains the security identifier (SID) of the user.

### `poolId` [in]

A null-terminated string that contains the identifier of the collection that the personal desktop exists in.

### `endpointName` [in]

A null-terminated string that contains the name of the desktop end point to be deleted.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ItsPubPlugin2](https://learn.microsoft.com/windows/desktop/api/tspubplugin2com/nn-tspubplugin2com-itspubplugin2)