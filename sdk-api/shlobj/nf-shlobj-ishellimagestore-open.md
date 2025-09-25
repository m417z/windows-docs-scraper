# IShellImageStore::Open

## Description

[[IShellImageStore](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-ishellimagestore) is supported through Windows XP. It is not supported in later operating systems.]

Opens the store and returns a lock.

## Parameters

### `dwMode`

Type: **DWORD**

The storage instantiation mode specified by one of the [STGM](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants) values.

### `pdwLock` [out]

Type: **DWORD***

A pointer to a variable of type **DWORD** that receives the lock.

## Return value

Type: **HRESULT**

If the process is successful, the method returns the result of [StgOpenStorage](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorage). Otherwise, it returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_FALSE** | The storage is already open with the instantiation mode specified by *dwMode*. |
| **E_UNEXPECTED** | An unexpected error occurred. For example, store path is not initialized. |
| **STG_E_ACCESSDENIED** | You do not have access to open the storage with the permissions specified by *dwMode*. |