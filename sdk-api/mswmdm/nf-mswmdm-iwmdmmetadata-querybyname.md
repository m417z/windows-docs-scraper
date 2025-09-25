# IWMDMMetaData::QueryByName

## Description

The **QueryByName** method retrieves the value of a property specified by name.

## Parameters

### `pwszTagName` [in]

Pointer to a wide-character **null**-terminated string specifying the property name. A list of standard property name constants is given in [Metadata Constants](https://learn.microsoft.com/windows/desktop/WMDM/metadata-constants).

### `pType` [out]

An [WMDM_TAG_DATATYPE](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-tag-datatype) enumerated value describing the type of data retrieved by *pValue*.

### `pValue` [out]

Pointer to a pointer to a byte array that receives the content of the value if the method succeeds. Windows Media Device Manager allocates this memory and the caller must free it using **CoTaskMemFree**.

### `pcbLength` [out]

Pointer to the size, in bytes, of the byte array *ppValue*. If the value is a string, this includes the termination character.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## See also

[IWMDMMetaData Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmmetadata)

[Metadata Constants](https://learn.microsoft.com/windows/desktop/WMDM/metadata-constants)

[QueryByIndex](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmmetadata-querybyindex)

[Setting Metadata on a File](https://learn.microsoft.com/windows/desktop/WMDM/setting-metadata-on-a-file)