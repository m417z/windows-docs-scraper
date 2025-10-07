# IOpcSignatureCustomObject::GetXml

## Description

Gets the XML markup of an application-specific **Object** element.

## Parameters

### `xmlMarkup` [out]

A pointer to a buffer that contains the XML markup of an **Object** element and includes the opening and closing **Object** tags.

In the buffer, XML markup is preceded by a [byte order mark](https://learn.microsoft.com/previous-versions/ms776429(v=vs.85)) that corresponds to the encoding of the markup.

Supported encodings and [byte order mark](https://learn.microsoft.com/previous-versions/ms776429(v=vs.85)) values.

| Encoding | Description | Byte order mark |
| --- | --- | --- |
| UTF8 | UTF-8 | EF BB BF |
| UTF16LE | UTF-16, little endian | FF FE |
| UTF16BE | UTF-16, big endian | FE FF |

For an example of a buffer with a [byte order mark](https://learn.microsoft.com/previous-versions/ms776429(v=vs.85)), see the Remarks section.

### `count` [out]

A pointer to the size of the *xmlMarkup* buffer.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the *xmlMarkup*, and *count* parameters is **NULL**. |

## Remarks

This method allocates memory used by the buffer returned in *xmlMarkup*. If the method succeeds, call the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

Serialized application-specific **Object** elements in signature markup can be added, removed, or modified by replacing the signature markup.

To replace signature markup, call the [IOpcDigitalSignatureManager::ReplaceSignatureXml](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcdigitalsignaturemanager-replacesignaturexml) method. The caller must ensure that addition, deletion, or modification of application-specific **Object** elements does not break the signature.

To sign an application-specific **Object** element or a child of that element, create a reference to the XML element to be signed. Create the reference by calling the [IOpcSignatureReferenceSet::Create](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsignaturereferenceset-create) method with the *referenceUri* parameter value set to "#" followed by the **Id** attribute value of the referenced element. For example, if the **Id** attribute of the referenced element is "Application", set *referenceUri* to "#Application".

The following table shows a [byte order mark](https://learn.microsoft.com/previous-versions/ms776429(v=vs.85)) at the beginning of an *xmlMarkup* buffer that contains "\<Object Id="id1">\</Object>":

|  |  |  |  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Buffer Byte Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | ... |
| UTF8 Value | EF | BB | BF | '<' | 'O' | 'b' | 'j' | 'e' | ... |
| UTF16LE Value | FF | FE | '<' | 00 | 'O' | 00 | 'b' | 00 | ... |

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcDigitalSignatureManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignaturemanager)

[IOpcSignatureCustomObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturecustomobject)

[IOpcSignatureReferenceSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturereferenceset)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**