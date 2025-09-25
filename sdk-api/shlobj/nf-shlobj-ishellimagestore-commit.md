# IShellImageStore::Commit

## Description

Writes the contents specified by *pdwLoc* to storage.

## Parameters

### `pdwLock` [in]

Type: **const DWORD***

A pointer to a variable of type **DWORD** that specifies the address that receives the lock.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value, including the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Content was saved successfully. |
| **S_FALSE** | Saving was unsuccessful. The storage is not open or is open without write access. |

## Remarks

**Note** [IShellImageStore](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-ishellimagestore) is supported through Windows XP. It is not supported in later operating systems.