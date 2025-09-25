# IWMDMMetaData::AddItem

## Description

The **AddItem** method adds a metadata property to the interface.

## Parameters

### `Type` [in]

An [WMDM_TAG_DATATYPE](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-tag-datatype) enumerated value specifying the type of metadata being saved.

### `pwszTagName` [in]

Pointer to a wide-character, null-terminated string specifying the name of the property to set. A list of standard property name constants is given in [Metadata Constants](https://learn.microsoft.com/windows/desktop/WMDM/metadata-constants).

### `pValue` [in]

Pointer to a byte array specifying the value to assign to the property. The submitted value is copied, so the memory can be freed after calling **AddItem**.

### `iLength` [in]

Integer specifying the size of *pValue*, in bytes.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## See also

[IWMDMMetaData Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmmetadata)

[Metadata Constants](https://learn.microsoft.com/windows/desktop/WMDM/metadata-constants)

[Setting Metadata on a File](https://learn.microsoft.com/windows/desktop/WMDM/setting-metadata-on-a-file)