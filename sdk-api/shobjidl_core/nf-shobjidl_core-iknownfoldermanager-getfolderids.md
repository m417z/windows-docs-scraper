# IKnownFolderManager::GetFolderIds

## Description

Gets an array of all registered known folder IDs. This can be used in enumerating all known folders.

## Parameters

### `ppKFId` [out]

Type: **[KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid)****

When this method returns, contains a pointer to an array of all [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) values registered with the system. Use [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to free these resources when they are no longer needed.

### `pCount` [in, out]

Type: **UINT***

When this method returns, contains a pointer to the number of [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) values in the array at *ppKFId*. The [in] functionality of this parameter is not used.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The caller of this method must have User privileges.

You can use [StringFromCLSID](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-stringfromclsid) or [StringFromGUID2](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-stringfromguid2) to convert the retrieved [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) values to strings.

## See also

[IKnownFolderManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfoldermanager)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))