# IOleUILinkContainerW::CancelLink

## Description

Disconnects the selected links.

## Parameters

### `dwLink`

Container-defined unique identifier for a single link. Containers can use the pointer to the link's container site for this value.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Insufficient access permissions. |
| **E_FAIL** | The operation failed. |
| **E_INVALIDARG** | The specified identifier is invalid. |
| **E_OUTOFMEMORY** | There is insufficient memory available for this operation. |

## Remarks

### Notes to Callers

Call **IOleUILinkContainer::CancelLink** when the user selects the **Break Link** button from the **Links** dialog box. The link should be converted to a picture. The **Links** dialog box will not be dismissed for OLE links.

### Notes to Implementers

For OLE links, [OleCreateStaticFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatestaticfromdata) can be used to create a static picture object using the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface of the link as the source.

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera)

[OleCreateStaticFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatestaticfromdata)