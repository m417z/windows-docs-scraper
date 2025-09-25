# IXpsOMObjectFactory1::CreatePackageWriterOnFile1

## Description

Opens a file for writing the contents of an XPS OM to an XPS package of a specified type. This method produces a package writer for either an MSXPS document or an OpenXPS document.

## Parameters

### `fileName`

[in] The name of the file to be created.

### `securityAttributes`

[in, unique] The [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure, which contains two separate but related members:

* **lpSecurityDescriptor**: an optional security descriptor
* **bInheritHandle**: a Boolean value that determines whether the returned handle can be inherited by child processes

If **lpSecurityDescriptor** is **NULL**, the file or device associated with the returned handle is assigned a default security descriptor.

 For more information about *securityAttributes*, see [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

### `flagsAndAttributes`

[in] Specifies the settings and attributes of the file to be created. For most files, the **FILE_ATTRIBUTE_NORMAL** value can be used.

See [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) for more information about this parameter.

### `optimizeMarkupSize`

[in] A Boolean value that indicates whether the document markup will be optimized for size when the contents of the XPS OM are written to the XPS package.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | The package writer will try to optimize the markup for minimum size. |
| ****FALSE**** | The package writer will not try to perform any optimization. |

### `interleaving`

[in] Specifies whether the content of the XPS OM will be interleaved when it is written to the file.

### `documentSequencePartName`

[in] The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the part name of the document sequence in the new file.

### `coreProperties`

[in] The [IXpsOMCoreProperties](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcoreproperties) interface that contains the core document properties to be given to the new file. This parameter can be set to **NULL**.

### `packageThumbnail`

[in] The [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface that contains the thumbnail image to be assigned to the new file. This parameter can be set to **NULL**.

### `documentSequencePrintTicket`

[in] The [IXpsOMPrintTicketResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomprintticketresource) interface that contains the package-level print ticket to be assigned to the new file. This parameter can be set to **NULL**.

### `discardControlPartName`

[in] The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the name of the discard control part. This parameter can be set to **NULL**.

### `documentType`

[in] Specifies the document type of the package writer. The value of this parameter cannot be XPS_DOCUMENT_TYPE_UNSPECIFIED.

### `packageWriter`

[out, retval] A pointer to the new [IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter) interface created by this method.

## Return value

Possible values include, but are not limited to, the following. For information about XPS document API return values that are not listed here, see XPS Document Errors.

S_OK: The method succeeded and packageWriter was set correctly.

E_INVALIDARG: The document type was not a valid XPS document format.

## Remarks

Use this method to produce a package writer for either an MSXPS document or an OpenXPS document. [CreatePackageWriterOnFile](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomobjectfactory-createpackagewriteronfile), released in Windows 7, only creates XPS document files in the MSXPS format.

### Additional References

Additional References: Legacy method description

## See also

[IXpsOMObjectFactory1](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsomobjectfactory1)