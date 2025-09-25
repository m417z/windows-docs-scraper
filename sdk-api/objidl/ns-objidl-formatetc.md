# FORMATETC structure

## Description

Represents a generalized clipboard format. It is enhanced to encompass a target device, the aspect or view of the data, and a storage medium indicator. Where one might expect to find a clipboard format, OLE uses a **FORMATETC** data structure instead. This structure is used as a parameter in OLE functions and methods that require data format information.

## Members

### `cfFormat`

The clipboard format of interest. There are three types of formats recognized by OLE:

* Standard interchange formats, such as CF_TEXT.
* Private application formats understood only by the application offering the format, or by other applications offering similar features.
* OLE formats, which are used to create linked or embedded objects.

### `ptd`

A pointer to a [DVTARGETDEVICE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-dvtargetdevice) structure containing information about the target device for which the data is being composed. A **NULL** value is used whenever the specified data format is independent of the target device or when the caller doesn't care what device is used. In the latter case, if the data requires a target device, the object should pick an appropriate default device (often the display for visual components). Data obtained from an object with a **NULL** target device, such as most metafiles, is independent of the target device. The resulting data is usually the same as it would be if the user chose the **Save As** command from the **File** menu and selected an interchange format.

### `dwAspect`

Indicates how much detail should be contained in the rendering. This parameter should be one of the [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect) enumeration values. A single clipboard format can support multiple aspects or views of the object. Most data and presentation transfer and caching methods pass aspect information. For example, a caller might request an object's iconic picture, using the metafile clipboard format to retrieve it. Note that only one **DVASPECT** value can be used in **dwAspect**. That is, **dwAspect** cannot be the result of a Boolean OR operation on several **DVASPECT** values.

### `lindex`

Part of the aspect when the data must be split across page boundaries. The most common value is -1, which identifies all of the data. Zero-based index should be used for [CFSTR_FILECONTENTS](https://learn.microsoft.com/windows/win32/shell/clipboard) format. For the aspects DVASPECT_THUMBNAIL and DVASPECT_ICON, lindex is ignored.

### `tymed`

One of the [TYMED](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-tymed) enumeration constants which indicate the type of storage medium used to transfer the object's data. Data can be transferred using whatever medium makes sense for the object. For example, data can be passed using global memory, a disk file, or structured storage objects. For more information, see the **TYMED** enumeration.

## Remarks

The **FORMATETC** structure is used by methods in the data transfer and presentation interfaces as a parameter specifying the data being transferred. For example, the [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) method uses the **FORMATETC** structure to indicate exactly what kind of data the caller is requesting.

## See also

[DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect)

[IDataAdviseHolder](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataadviseholder)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc)

[IOleCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache)

[OleCreate](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olecreate)

[OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata)

[OleCreateLink](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatelink)

[OleCreateLinkFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatelinkfromdata)

[OleCreateLinkToFile](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatelinktofile)

[OleCreateStaticFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatestaticfromdata)

[STATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statdata)

[STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1)

[TYMED](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-tymed)