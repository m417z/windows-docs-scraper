# OleCreateStaticFromData function

## Description

Creates a static object, that contains only a representation, with no native data, from a data transfer object.

**Note** The OLESTREAM to [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) conversion functions also convert static objects.

## Parameters

### `pSrcDataObj` [in]

Pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the data transfer object that holds the data from which the object will be created.

### `iid` [in]

Reference to the identifier of the interface with which the caller is to communicate with the new object (usually IID_IOleObject, defined in the OLE headers as the interface identifier for [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)).

### `renderopt` [in]

Value from the enumeration [OLERENDER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olerender) indicating the locally cached drawing or data-retrieval capabilities that the container wants in the newly created component. It is an error to pass the render options OLERENDER_NONE or OLERENDER_ASIS to this function.

### `pFormatEtc` [in]

Depending on which of the [OLERENDER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olerender) flags is used as the value of *renderopt*, may be a pointer to one of the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) enumeration values. Refer to the **OLERENDER** enumeration for restrictions.

### `pClientSite` [in]

Pointer to an instance of [IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite), the primary interface through which the object will request services from its container. This parameter can be **NULL**.

### `pStg` [in]

Pointer to the [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface for storage for the object. This parameter cannot be **NULL**.

### `ppvObj` [out]

Address of pointer variable that receives the interface pointer requested in riid. Upon successful return, **ppvObj* contains the requested interface pointer on the newly created object.

## Return value

This function returns S_OK on success.

## Remarks

The **OleCreateStaticFromData** function can convert any object, as long as it provides an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface, to a static object. It is useful in implementing the Convert To Picture option for OLE linking or embedding.

Static objects can be created only if the source supports one of the OLE-rendered clipboard formats: CF_METAFILEPICT, CF_DIB, or CF_ BITMAP, and CF_ENHMETAFILE.

You can also call **OleCreateStaticFromData** to paste a static object from the clipboard. To determine whether an object is static, call the [OleQueryCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olequerycreatefromdata) function, which returns OLE_S_STATIC if one of CF_METAFILEPICT, CF_DIB, CF_BITMAP, or CF_ENHMETAFILE is present and an OLE format is not present. This indicates that you should call **OleCreateStaticFromData** rather than the [OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata) function to create the object.

The new static object is of class CLSID_StaticMetafile in the case of CF_METAFILEPICT, CLSID_StaticDib in the case of CF_DIB or CF_BITMAP, or CLSID_Picture_EnhMetafile in the case of CF_ENHMETAFILE. The static object sets the OLEMISC_STATIC and OLE_CANTLINKINSIDE bits returned from [IOleObject::GetMiscStatus](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getmiscstatus). The static object will have the aspect DVASPECT_CONTENT and a LINDEX of -1.

The *pSrcDataObject* is still valid after **OleCreateStaticFromData** returns. It is the caller's responsibility to free *pSrcDataObject* - OLE does not release it.

There cannot be more than one presentation stream in a static object.

## See also

[OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata)