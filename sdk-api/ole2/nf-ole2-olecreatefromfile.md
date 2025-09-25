# OleCreateFromFile function

## Description

Creates an embedded object from the contents of a named file.

## Parameters

### `rclsid` [in]

This parameter is reserved and must be CLSID_NULL.

### `lpszFileName` [in]

Pointer to a string specifying the full path of the file from which the object should be initialized.

### `riid` [in]

Reference to the identifier of the interface the caller later uses to communicate with the new object (usually IID_IOleObject, defined in the OLE headers as the interface ID of [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)).

### `renderopt` [in]

Value from the enumeration [OLERENDER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olerender) that indicates the locally cached drawing or data-retrieval capabilities the newly created object is to have. The **OLERENDER** value chosen affects the possible values for the *lpFormatEtc* parameter.

### `lpFormatEtc` [in]

 Depending on which of the [OLERENDER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olerender) flags is used as the value of *renderopt*, pointer to one of the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) enumeration values. Refer also to the **OLERENDER** enumeration for restrictions.

### `pClientSite` [in]

Pointer to an instance of [IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite), the primary interface through which the object will request services from its container. This parameter can be **NULL**.

### `pStg` [in]

Pointer to the [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on the storage object. This parameter cannot be **NULL**.

### `ppvObj` [out]

Address of pointer variable that receives the interface pointer requested in riid. Upon successful return, **ppvObj* contains the requested interface pointer on the newly created object.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **STG_E_FILENOTFOUND** | File not bound. |
| **OLE_E_CANT_BINDTOSOURCE** | Not able to bind to source. |
| **STG_E_MEDIUMFULL** | The medium is full. |
| **DV_E_TYMED** | Invalid [TYMED](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-tymed). |
| **DV_E_LINDEX** | Invalid LINDEX. |
| **DV_E_FORMATETC** | Invalid [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure. |

## Remarks

The **OleCreateFromFile** function creates a new embedded object from the contents of a named file. If the ProgID in the registration database contains the PackageOnFileDrop key, it creates a package. If not, the function calls the [GetClassFile](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-getclassfile) function to get the CLSID associated with the *lpszFileName* parameter, and then creates an OLE 2-embedded object associated with that CLSID. The *rclsid* parameter of **OleCreateFromFile** will always be ignored, and should be set to CLSID_NULL.

As for other OleCreateXxx functions, the newly created object is not shown to the user for editing, which requires a [DoVerb](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb) operation. It is used to implement insert file operations.

## See also

[GetClassFile](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-getclassfile)