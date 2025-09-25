# OleQueryLinkFromData function

## Description

Determines whether an OLE linked object (rather than an OLE embedded object) can be created from a clipboard data object.

## Parameters

### `pSrcDataObject` [in]

Pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the clipboard data object from which the object is to be created.

## Return value

Returns S_OK if the [OleCreateLinkFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatelinkfromdata) function can be used to create the linked object; otherwise S_FALSE.

## Remarks

The **OleQueryLinkFromData** function is similar to the [OleQueryCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olequerycreatefromdata) function, but determines whether an OLE linked object (rather than an OLE embedded object) can be created from the clipboard data object. If the return value is S_OK, the application can then attempt to create the object with a call to [OleCreateLinkFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatelinkfromdata). A successful return from **OleQueryLinkFromData** does not, however, guarantee the successful creation of a link.