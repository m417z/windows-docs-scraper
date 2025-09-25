# ISyncMgrConflictStore::GetCount

## Description

Gets the number of conflicts in the store.

## Parameters

### `pszHandlerID` [in]

Type: **LPCWSTR**

A pointer to a sync handler ID as a Unicode string.

### `pszItemID` [in]

Type: **LPCWSTR**

A pointer to a sync item ID as a Unicode string.

### `pnConflicts` [out]

Type: **DWORD***

When this method returns, contains the conflict count.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.