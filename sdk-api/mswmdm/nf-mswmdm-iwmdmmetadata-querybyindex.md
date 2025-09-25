# IWMDMMetaData::QueryByIndex

## Description

The **QueryByIndex** method retrieves the value of a property specified by index.

## Parameters

### `iIndex` [in]

Integer specifying the zero-based index of the property. The number of items is obtained through the [GetItemCount](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmmetadata-getitemcount) call.

### `ppwszName` [out]

Name of the property. Windows Media Device Manager allocates this memory, and the caller must free it using **CoTaskMemFree**.

### `pType` [out]

An [WMDM_TAG_DATATYPE](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-tag-datatype) enumerated value describing the type of data returned in *ppValue*.

### `ppValue` [out]

Pointer to a pointer to a byte array that receives the content of the value if the method succeeds. This memory is allocated by Windows Media Device Manager, and the caller must free it using **CoTaskMemFree**.

### `pcbLength` [out]

Pointer to the size, in bytes, of the byte array *ppValue*. If the value is a string, this includes the termination character.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## See also

[GetItemCount](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmmetadata-getitemcount)

[IWMDMMetaData Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmmetadata)

[QueryByName](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmmetadata-querybyname)

[Setting Metadata on a File](https://learn.microsoft.com/windows/desktop/WMDM/setting-metadata-on-a-file)