# OBJECTDESCRIPTOR structure

## Description

Represents the data structure used for the CF_OBJECTDESRIPTOR and CF_LINKSRCDESCRIPTOR file formats. These formats provide user interface information during data transfer operations, for example, the **Paste Special** dialog box or target feedback information during drag-and-drop operations.

## Members

### `cbSize`

The size of structure, in bytes.

### `clsid`

The CLSID of the object being transferred. The clsid is used to obtain the icon for the **Display As Icon** option in the **Paste Special** dialog box and is applicable only if the Embed Source or Embedded Object formats are offered. If neither is offered, the value of clsid should be CLSID_NULL. The clsid can be retrieved by the source by loading the object and calling the [IOleObject::GetUserClassID](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getuserclassid) method. Note that for link objects, this value is not the same as the value returned by the [IPersist::GetClassID](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersist-getclassid) method.

### `dwDrawAspect`

The display aspect of the object. Typically, this value is DVASPECT_CONTENT or DVASPECT_ICON. If the source application did not draw the object originally, the **dwDrawAspect** field contains a zero value (which is not the same as DVASPECT_CONTENT). For more information, see [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect).

### `sizel`

The true extent of the object (without cropping or scaling) in **HIMETRIC** units. Setting this field is optional. The value can be (0,0) for applications that do not draw the object being transferred. This field is used primarily by targets of drag-and-drop operations, so they can give appropriate feedback to the user.

### `pointl`

The offset in **HIMETRIC** units from the upper-left corner of the object where a drag-and-drop operation was initiated. This field is only meaningful for a drag-and-drop transfer operation since it corresponds to the point where the mouse was clicked to initiate the drag-and-drop operation. The value is (0,0) for other transfer situations, such as a clipboard copy and paste.

### `dwStatus`

The copy of the status flags for the object. These flags are defined by the [OLEMISC](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olemisc) enumeration. If an embedded object is being transferred, they are returned by calling the [IOleObject::GetMiscStatus](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getmiscstatus) method.

### `dwFullUserTypeName`

The offset for finding the full user type name of the object being transferred. It specifies the offset, in bytes, from the beginning of the **OBJECTDESCRIPTOR** data structure to the null-terminated string that specifies the full user type name of the object being transferred. The value is zero if the string is not present. This string is used by the destination of a data transfer to create labels in the **Paste Special** dialog box. The destination application must be able to handle the cases when this string is omitted.

### `dwSrcOfCopy`

The offset, in bytes, from the beginning of the data structure to the null-terminated string that specifies the source of the transfer. The **dwSrcOfCopy** member is typically implemented as the display name of the temporary moniker that identifies the data source. The value for **dwSrcOfCopy** is displayed in the Source line of the **Paste Special** dialog box. A zero value indicates that the string is not present. If **dwSrcOfCopy** is zero, the string "Unknown Source" is displayed in the **Paste Special** dialog box.

## See also

[FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)