# IMDSPStorage4::GetReferences

## Description

The **GetReferences** method returns an array of pointers to **IMDSPStorage** objects comprising the references contained in an association storage, such as one representing playlist or album objects.

## Parameters

### `pdwRefs` [out]

Pointer to the count of **IWMDMStorage** interface pointers being returned in *pppIWMDMStorage*.

### `pppISPStorage` [out]

Pointer to a pointer to the array of **IWMDMStorage** interface pointers that represent references on a storage. Such references can, for example, represent items in a playlist or album. The ordering of references matches the ordering in this array. Memory for this array should be allocated by the service provider.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Windows Media Device Manager uses this method for obtaining the references on an association storage such as a playlist or an album.

If the storage has references to one or more items that have been deleted from the device, the SP should not include these references in the references returned. The SP should indicate such condition by returning S_FALSE. The application might choose to refresh the association storage object by using the known-good references returned here. The SP can also refresh the references itself.

If the count of references is 0, service provider must return an array of references with 0 elements in it.

## See also

[IMDSPStorage4 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage4)

[IMDSPStorage4::SetReferences](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage4-setreferences)