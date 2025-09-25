# ISyncMgrHandlerCollection::GetHandlerEnumerator

## Description

Gets an enumerator that provides access to the IDs of sync handlers exposed to and managed by the user.

## Parameters

### `ppenum` [out]

Type: **[IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring)****

When this method returns, contains an address of a pointer to an instance of [IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring) that enumerates the IDs of known sync handlers.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A sync handler ID is a string that uniquely represents the handler. The ID must be unique across all handlers in the system and is limited to a maximum length of **MAX_SYNCMGR_ID**, including the terminating null character.

Earlier versions of Windows relied on GUIDs to represent handler and item IDs. Windows Vista uses strings for their greater flexibility. It is still recommended that the string contain a GUID to ensure uniqueness, but it can also contain other information of use to the handler, specific to the application or device.