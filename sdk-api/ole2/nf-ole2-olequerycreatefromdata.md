# OleQueryCreateFromData function

## Description

Checks whether a data object has one of the formats that would allow it to become an embedded object through a call to either the [OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata) or [OleCreateStaticFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatestaticfromdata) function.

## Parameters

### `pSrcDataObject` [in]

Pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the data transfer object to be queried.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | No formats are present that support either embedded- or static-object creation. |
| **OLE_S_STATIC** | Formats that support static-object creation are present. |

## Remarks

When an application retrieves a data transfer object through a call to the [OleGetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olegetclipboard) function, the application should call **OleQueryCreateFromData** as part of the process of deciding to enable or disable the **Edit/Paste** or **Edit/Paste Special...** commands. It tests for the presence of the following formats in the data object:

* CF_EMBEDDEDOBJECT
* CF_EMBEDSOURCE
* cfFileName
* CF_METAFILEPICT
* CF_DIB
* CF_BITMAP
* CF_ENHMETAFILE

Determining that the data object has one of these formats does not absolutely guarantee that the object creation will succeed, but is intended to help the process.

If **OleQueryCreateFromData** finds one of the CF_METAFILEPICT, CF_BITMAP, CF_DIB, or CF_ENHMETAFILE formats and none of the other formats, it returns OLE_S_STATIC, indicating that you should call the [OleCreateStaticFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatestaticfromdata) function to create the embedded object.

If **OleQueryCreateFromData** finds one of the other formats (CF_EMBEDDEDOBJECT, CF_EMBEDSOURCE, or cfFileName), even in combination with the static formats, it returns S_OK, indicating that you should call the [OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata) function to create the embedded object.

## See also

[OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata)

[OleCreateStaticFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatestaticfromdata)

[OleQueryLinkFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olequerylinkfromdata)