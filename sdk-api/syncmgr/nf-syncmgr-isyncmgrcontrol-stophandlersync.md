# ISyncMgrControl::StopHandlerSync

## Description

Stops the synchronization of a specified handler.

## Parameters

### `pszHandlerID` [in]

Type: **LPCWSTR**

A pointer to a buffer containing the unique ID of the handler. This string is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.