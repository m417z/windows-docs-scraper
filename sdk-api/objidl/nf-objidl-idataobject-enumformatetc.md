# IDataObject::EnumFormatEtc

## Description

Creates an object to enumerate the formats supported by a data object.

## Parameters

### `dwDirection` [in]

The direction of the data. Possible values come from the [DATADIR](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-datadir) enumeration.

The value DATADIR_GET enumerates the formats that can be passed in to a call to [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata). The value DATADIR_SET enumerates those formats that can be passed in to a call to [IDataObject::SetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-setdata).

### `ppenumFormatEtc` [out]

A pointer to an [IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc) pointer variable that receives the interface pointer to the new enumerator object.

## Return value

This method returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The supplied *dwDirection* is invalid. |
| **E_OUTOFMEMORY** | Insufficient memory available for this operation. |
| **E_NOTIMPL** | The direction specified by *dwDirection* is not supported. |
| **OLE_S_USEREG** | Requests that OLE enumerate the formats from the registry. |

## Remarks

**EnumFormatEtc** creates an enumerator object that can be used to determine all of the ways the data object can describe data in a [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure, and provides a pointer to its [IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc) interface. This is one of the standard enumerator interfaces.

### Notes to Callers

Having obtained the pointer, the caller can enumerate the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structures by calling the enumeration methods of [IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc). Because the formats can change over time, there is no guarantee that an enumerated format is currently supported because the formats can change over time. Accordingly, applications should treat the enumeration as a hint of the format types that can be passed. The caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when it is finished with the enumerator.

**EnumFormatEtc** is called when one of the following actions occurs:

* An application calls [OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard). OLE must determine what data to place on the clipboard and whether it is necessary to put OLE 1 compatibility formats on the clipboard.
* Data is being pasted from the clipboard or dropped. An application uses the first acceptable format.
* The **Paste Special** dialog box is displayed. The target application builds the list of formats from the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) entries.

### Notes to Implementers

Formats can be registered statically in the registry or dynamically during object initialization. If an object has an unchanging list of formats and these formats are registered in the registry, OLE provides an implementation of a [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) enumeration object that can enumerate formats registered under a specific CLSID in the registry. A pointer to its [IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc) interface is available through a call to the helper function [OleRegEnumFormatEtc](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleregenumformatetc). In this situation, therefore, you can implement the **EnumFormatEtc** method simply with a call to this function.

EXE applications can effectively do the same thing by implementing the method to return the value OLE_S_USEREG. This return value instructs the default object handler to call [OleRegEnumFormatEtc](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleregenumformatetc). Object applications that are implemented as DLL object applications cannot return OLE_S_USEREG, so must call **OleRegEnumFormatEtc** directly.

Private formats can be enumerated for OLE 1 objects, if they are registered with the RequestDataFormats or SetDataFormats keys in the registry. Also, private formats can be enumerated for OLE objects (all versions after OLE 1), if they are registered with the GetDataFormats or SetDataFormats keys.

For OLE 1 objects whose servers do not have RequestDataFormats or SetDataFormats information registered in the registry, a call to **EnumFormatEtc** passing DATADIR_GET only enumerates the native and metafile formats, regardless of whether they support these formats or others. Calling **EnumFormatEtc** passing DATADIR_SET on such objects only enumerates native, regardless of whether the object supports being set with other formats.

The [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure returned by the enumeration usually indicates a **NULL** target device (ptd). This is appropriate because, unlike the other members of **FORMATETC**, the target device does not participate in the object's decision as to whether it can accept or provide the data in either a SetData or GetData call.

The **tymed** member of [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) often indicates that more than one kind of storage medium is acceptable. You should always mask and test for this by using a Boolean OR operator.

## See also

[FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc)

[IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata)

[IDataObject::SetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-setdata)

[IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc)

[OleRegEnumFormatEtc](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleregenumformatetc)