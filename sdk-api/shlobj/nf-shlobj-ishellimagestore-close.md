# IShellImageStore::Close

## Description

Closes the image cache.

## Parameters

### `pdwLock` [in]

Type: **const DWORD***

A pointer to a variable of type **DWORD** that specifies the address that receives the lock during the call to the [IShellImageStore::Open](https://learn.microsoft.com/windows/desktop/api/shlobj/nf-shlobj-ishellimagestore-open) method.

## Return value

Type: **HRESULT**

Returns S_FALSE if the store is not open or if the store cannot be saved. Returns the result of [IShellImageStore::Commit](https://learn.microsoft.com/windows/desktop/api/shlobj/nf-shlobj-ishellimagestore-commit) otherwise.

## Remarks

**Note** [IShellImageStore](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-ishellimagestore) is supported through Windows XP. It is not supported in later operating systems.