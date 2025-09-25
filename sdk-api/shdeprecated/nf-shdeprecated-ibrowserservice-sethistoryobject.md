# IBrowserService::SetHistoryObject

## Description

Deprecated. Sets the browser's history object.

## Parameters

### `pole` [in]

Type: **[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)***

A pointer to an [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject) that represents the history object to set.

### `fIsLocalAnchor` [in]

Type: **BOOL**

A value that specifies whether the new entry is a local or a remote file. Used in the case of the reuse of an inner object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method will fail if the browser already has a history object.