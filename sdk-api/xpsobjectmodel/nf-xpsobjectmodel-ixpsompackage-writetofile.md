# IXpsOMPackage::WriteToFile

## Description

Writes the XPS package to a specified file.

## Parameters

### `fileName` [in]

The name of the file to be created. This parameter must not be **NULL**.

### `securityAttributes` [in]

The [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure, which contains two distinct but related data members:

* **lpSecurityDescriptor**: an optional security descriptor
* **bInheritHandle**: a Boolean value that determines whether the returned handle can be inherited by child processes

If **lpSecurityDescriptor** is **NULL**, the file or device that is associated with the returned handle will be assigned a default security descriptor.

For more information about the *securityAttributes* parameter, refer to [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

### `flagsAndAttributes` [in]

Specifies the settings and attributes of the file to be created. For most files, a value of **FILE_ATTRIBUTE_NORMAL** can be used.

For more information about the *flagsAndAttributes* parameter, refer to [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

### `optimizeMarkupSize` [in]

A Boolean value that indicates whether the document markup is to be optimized for size when it is written to the file.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | The package writer will attempt to optimize the markup for minimum size. |
| ****FALSE**** | The package writer will not attempt any optimization. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *fileName* is **NULL**. |

This method calls the [Packaging](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging) API. For information about the Packaging API return values, see [Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors).

## Remarks

The *optimizeMarkupSize* value determines whether the markup inside the individual document parts is to be optimized. It has no effect on how the parts are interleaved.

**Note** Writing an XPS OM to a file does not automatically create a thumbnail for the XPS document. To create a thumbnail of the XPS document, use the [IXpsOMThumbnailGenerator](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomthumbnailgenerator) interface.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[IXpsOMPackage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackage)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))