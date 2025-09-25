# ISyncMgrEvent::GetTime

## Description

Gets the creation time.

## Parameters

### `pfCreationTime` [out]

Type: **FILETIME***

When this method returns, contains a pointer to a creation time as a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.