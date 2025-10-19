# IXpsOMObjectFactory::CreatePackageWriterOnFile

## Description

Opens a file for writing the contents of an XPS OM to an XPS package.

## Parameters

### `fileName` [in]

The name of the file to be created.

### `securityAttributes` [in]

The [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure, which contains two separate but related members:

* **lpSecurityDescriptor**: an optional security descriptor
* **bInheritHandle**: a Boolean value that determines whether the returned handle can be inherited by child processes

If **lpSecurityDescriptor** is **NULL**, the file or device associated with the returned handle is assigned a default security descriptor.

 For more information about *securityAttributes*, see [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

### `flagsAndAttributes` [in]

Specifies the settings and attributes of the file to be created. For most files, the **FILE_ATTRIBUTE_NORMAL** value can be used.

See [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) for more information about this parameter.

### `optimizeMarkupSize` [in]

A Boolean value that indicates whether the document markup will be optimized for size when the contents of the XPS OM are written to the XPS package.

| Value | Meaning |
| --- | --- |
| **TRUE** | The package writer will try to optimize the markup for minimum size. |
| **FALSE** | The package writer will not try to perform any optimization. |

### `interleaving` [in]

Specifies whether the content of the XPS OM will be interleaved when it is written to the file.

### `documentSequencePartName` [in]

The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the part name of the document sequence in the new file.

### `coreProperties` [in]

The [IXpsOMCoreProperties](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcoreproperties) interface that contains the core document properties to be given to the new file. This parameter can be set to **NULL**.

### `packageThumbnail` [in]

The [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface that contains the thumbnail image to be assigned to the new file. This parameter can be set to **NULL**.

### `documentSequencePrintTicket` [in]

The [IXpsOMPrintTicketResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomprintticketresource) interface that contains the package-level print ticket to be assigned to the new file. This parameter can be set to **NULL**.

### `discardControlPartName` [in]

The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the name of the discard control part. This parameter can be set to **NULL**.

### `packageWriter` [out, retval]

A pointer to the new [IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter) interface created by this method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *filename*, *documentSequencePartName*, or *packageWriter* is **NULL**. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *coreProperties*, *documentSequencePrintTicket*, or *packageThumbnail* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

This method calls the [Packaging](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging) API. For information about the Packaging API return values, see [Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors).

## Remarks

 The file is opened and initialized and the [IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter) interface that is returned is then used to write content types, package relationships, core properties, document sequence resources, and document sequence relationships.

If *documentSequencePrintTicket* is set to **NULL** and the value of *interleaving* is **XPS_INTERLEAVING_ON**, this method creates a blank job-level print ticket and adds a relationship to the blank print ticket. This is done to provide more efficient streaming consumption of the package.

If *documentSequencePrintTicket* is set to **NULL** and the value of *interleaving* is **XPS_INTERLEAVING_OFF**, no blank print ticket is created.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[IXpsOMCoreProperties](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcoreproperties)

[IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource)

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter)

[IXpsOMPrintTicketResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomprintticketresource)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))