# ISyncMgrControl::StopItemSync

## Description

Stops the synchronization of specified items managed by a particular handler.

## Parameters

### `pszHandlerID` [in]

Type: **LPCWSTR**

a pointer to a buffer containing the unique ID of the handler. This string is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

### `ppszItemIDs` [in]

Type: **LPCWSTR***

The address of a pointer to a buffer containing an array of IDs of the items to stop synchronizing. Each ID is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

### `cItems` [in]

Type: **DWORD**

The number of IDs in *ppszItemIDs*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.