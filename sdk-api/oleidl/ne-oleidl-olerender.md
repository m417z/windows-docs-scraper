# OLERENDER enumeration

## Description

Indicates the type of caching requested for newly created objects.

## Constants

### `OLERENDER_NONE:0`

The client is not requesting any locally cached drawing or data retrieval capabilities in the object. The *pFormatEtc* parameter of the calls is ignored when this value is specified for the *renderopts* parameter.

### `OLERENDER_DRAW:1`

The client will draw the content of the object on the screen (a **NULL** target device) using [IViewObject::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw). The object itself determines the data formats that need to be cached. With this render option, only the **ptd** and **dwAspect** members of *pFormatEtc* are significant, since the object may cache things differently depending on the parameter values. However, *pFormatEtc* can legally be **NULL** here, in which case the object is to assume the display target device and the DVASPECT_CONTENT aspect.

### `OLERENDER_FORMAT:2`

The client will pull one format from the object using [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata). The format of the data to be cached is passed in *pFormatEtc*, which may not in this case be **NULL**.

### `OLERENDER_ASIS:3`

The client is not requesting any locally cached drawing or data retrieval capabilities in the object. *pFormatEtc* is ignored for this option. The difference between this and the OLERENDER_FORMAT value is important in such functions as [OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata) and [OleCreateLinkFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatelinkfromdata).

## See also

[OleCreate](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olecreate)

[OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata)

[OleCreateFromFile](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olecreatefromfile)

[OleCreateLink](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatelink)

[OleCreateLinkFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatelinkfromdata)

[OleCreateLinkToFile](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatelinktofile)

[OleCreateStaticFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatestaticfromdata)