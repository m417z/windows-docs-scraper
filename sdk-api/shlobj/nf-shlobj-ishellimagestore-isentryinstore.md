# IShellImageStore::IsEntryInStore

## Description

Checks to see if the image is in the store.

## Parameters

### `pszName` [in]

Type: **PCWSTR**

A pointer to a null-terminated string that specifies the path to the file that contains the image.

### `pftTimeStamp` [out]

Type: **[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)***

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that specifies the time stamp for the image.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The entry is in the store. |
| **S_FALSE** | The entry is not in the store. |
| **E_UNEXPECTED** | The store is not open. |

## Remarks

**Note** [IShellImageStore](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-ishellimagestore) is supported through Windows XP. It is not supported in later operating systems.