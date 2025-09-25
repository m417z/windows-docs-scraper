# IXpsOMObjectFactory::CreatePackageFromFile

## Description

Opens an XPS package file and returns an instantiated XPS document object tree.

## Parameters

### `filename` [in]

The name of the XPS package file.

### `reuseObjects` [in]

A Boolean value that indicates whether the software is to attempt to optimize the document object tree by sharing objects that are identical in all properties and children.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | The software will attempt to optimize the object tree. |
| ****FALSE**** | The software will not attempt to optimize the object tree. |

### `package` [out, retval]

A pointer to the new [IXpsOMPackage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackage) interface that contains the resulting XPS document object tree.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *filename* or *package* is **NULL**. |

This method calls the [Packaging](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging) API. For information about the Packaging API return values, see [Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors).

## Remarks

This method does not validate the contents of any stream-based resources that it loads from the stream into the objects of the XPS OM. Instead, the application must validate these resources before it uses them.

This method does not deserialize the document pages; it only deserializes the XPS package down to the page reference parts. The actual pages can be deserialized as they are needed, by calling the [IXpsOMPageReference::GetPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompagereference-getpage) method. Because the pages are not deserialized when **GetPage** is called, it is possible for this method to return S_OK or, if an attempt is made to load a problematic page in an XPS package, to return an error.

If you write an XPS OM immediately after you have read an XPS package into it, some of the original content might be lost or changed.

Some of the changes that can occur in such a case are listed in the table that follows:

| Document feature | Action |
| --- | --- |
| Digital signatures | Removed from document |
| DiscardControl part | Removed from document |
| Foreign document parts | Removed from document |
| FixedPage markup | Modified from original |
| Resource dictionary markup | Modified from original if Optimization flag is set |

For information about using [IXpsOMPackage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackage) interface in a program, see [Create a Blank XPS OM](https://learn.microsoft.com/previous-versions/windows/desktop/dd316970(v=vs.85)).

## See also

[Create a Blank XPS OM](https://learn.microsoft.com/previous-versions/windows/desktop/dd316970(v=vs.85))

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[IXpsOMPackage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackage)

[IXpsOMPageReference::GetPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompagereference-getpage)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))