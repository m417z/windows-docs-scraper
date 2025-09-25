# IOpcSignatureCustomObjectSet::Create

## Description

Creates an [IOpcSignatureCustomObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturecustomobject) interface pointer to represent an application-specific **Object** element in the signature, and adds the new interface to the set.

## Parameters

### `xmlMarkup` [in]

A buffer that contains the XML markup for the **Object** element to be represented.

This XML markup must include the opening **Object** and closing **/Object** tags.

The encoding of the markup contained in *xmlMarkup* will be inferred. Inclusion of a [byte order mark](https://learn.microsoft.com/previous-versions/ms776429(v=vs.85)) at the beginning of the buffer passed in *xmlMarkup* is optional.

The following encodings and [byte order mark](https://learn.microsoft.com/previous-versions/ms776429(v=vs.85)) values are supported:

| Encoding | Description | Byte order mark |
| --- | --- | --- |
| UTF8 | UTF-8 | EF BB BF |
| UTF16LE | UTF-16, little endian | FF FE |
| UTF16BE | UTF-16, big endian | FE FF |

### `count` [in]

The size of the *xmlMarkup* buffer.

### `customObject` [out, retval]

A new [IOpcSignatureCustomObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturecustomobject) interface pointer that represents the application-specific **Object** element.

This parameter can be **NULL** if a pointer to the new interface is not needed.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *count* parameter is 0. The *xmlMarkup* parameter must be passed valid XML markup. |
| **E_POINTER** | The *xmlMarkup* parameter is **NULL**. |

## Remarks

An [IOpcSignatureCustomObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturecustomobject) interface pointer provides access to the XML markup of the **Object** element it represents. To access the XML markup of the **Object** element, call the [IOpcSignatureCustomObject::GetXml](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsignaturecustomobject-getxml) method.

When an [IOpcSignatureCustomObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturecustomobject) interface pointer is created and added to the set, the **Object** it represents is saved when the package is saved.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcSignatureCustomObjectSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturecustomobjectset)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**