# OleCreateLink function

## Description

Creates an OLE compound-document linked object.

## Parameters

### `pmkLinkSrc` [in]

Pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface on the moniker that can be used to locate the source of the linked object.

### `riid` [in]

Reference to the identifier of the interface the caller later uses to communicate with the new object (usually IID_IOleObject, defined in the OLE headers as the interface identifier for [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)).

### `renderopt` [in]

Specifies a value from the enumeration [OLERENDER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olerender) that indicates the locally cached drawing or data-retrieval capabilities the newly created object is to have. Additional considerations are described in the Remarks section below.

### `lpFormatEtc` [in]

Pointer to a value from the enumeration [OLERENDER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olerender) that indicates the locally cached drawing or data-retrieval capabilities the newly created object is to have. The **OLERENDER** value chosen affects the possible values for the *lpFormatEtc* parameter.

### `pClientSite` [in]

Pointer to an instance of [IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite), the primary interface through which the object will request services from its container. This parameter can be **NULL**.

### `pStg` [in]

Pointer to the [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on the storage object. This parameter cannot be **NULL**.

### `ppvObj` [out]

Address of pointer variable that receives the interface pointer requested in *riid*. Upon successful return, **ppvObj* contains the requested interface pointer on the newly created object.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_CANT_BINDTOSOURCE** | Not able to bind to source. |

## Remarks

Call **OleCreateLink** to allow a container to create a link to an object.

## See also

[IOleClientSite::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-getmoniker)

[IOleObject::SetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setmoniker)