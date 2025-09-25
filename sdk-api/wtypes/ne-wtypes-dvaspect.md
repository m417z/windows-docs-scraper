# DVASPECT enumeration

## Description

Specifies the desired data or view aspect of the object when drawing or getting data.

## Constants

### `DVASPECT_CONTENT:1`

Provides a representation of an object so it can be displayed as an embedded object inside of a container. This value is typically specified for compound document objects. The presentation can be provided for the screen or printer.

### `DVASPECT_THUMBNAIL:2`

Provides a thumbnail representation of an object so it can be displayed in a browsing tool. The thumbnail is approximately a 120 by 120 pixel, 16-color (recommended) device-independent bitmap potentially wrapped in a metafile.

### `DVASPECT_ICON:4`

Provides an iconic representation of an object.

### `DVASPECT_DOCPRINT:8`

Provides a representation of the object on the screen as though it were printed to a printer using the **Print** command from the **File** menu. The described data may represent a sequence of pages.

## Remarks

Values of this enumeration are used to define the **dwAspect** member of the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure. Only one **DVASPECT** value can be used to specify a single presentation aspect in a **FORMATETC** structure. The **FORMATETC** structure is used in many OLE functions and interface methods that require information on data presentation.

The default value of **MiscStatus** is used if a subkey corresponding to the specified **DVASPECT** is not found. To set an OLE control, specify DVASPECT==1. This will cause the following to occur in the registry:

```
HKEY_CLASSES_ROOT\CLSID\ . . .
   MiscStatus = 1
```

## See also

[FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc)

[IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IViewObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iviewobject)

[IViewObject2](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iviewobject2)

[OBJECTDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/oleidl/ns-oleidl-objectdescriptor)

[OleDraw](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-oledraw)