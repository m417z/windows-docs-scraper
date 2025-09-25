# IOpcDigitalSignature::GetPackageObjectReference

## Description

Gets an [IOpcSignatureReference](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturereference) interface pointer that represents the reference to the package-specific **Object** element that has been signed.

## Parameters

### `packageObjectReference` [out, retval]

An [IOpcSignatureReference](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturereference) interface pointer that represents the reference to the package-specific **Object** element that has been signed.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *packageObjectReference* parameter is **NULL**. |

## Remarks

The [IOpcSignatureReference](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturereference) interface pointer received in the *packageObjectReference* parameter represents the **Reference** element that has the **URI** attribute value set to "#idPackageObject". The **URI** attribute value of this element is the **Id** attribute value of the package-specific **Object** element, prefixed with a pound sign ("#").

When the signature is generated and serialized as signature markup, the reference and the referenced package-specific **Object** element are signed. The following markup shows the package-specific **Reference** element and the package-specific **Object** element in the resultant signature markup.

```xml
<!-- Signature markup. -->
<Signature>
    <SignedInfo>
        [...]
        <!-- A reference to the package-specific <Object> that
        is, or will be, signed. -->
        <Reference URI="#idPackageObject">
             [...]
        </Reference>
    </SignedInfo>
    [...]
    <!-- The package-specific <Object> element. -->
    <Object Id="idPackageObject">
        <!-- This element contains the <Reference> elements that
        refer to parts and relationships in the package that are
        or will be signed. -->
        <Manifest>
            [...]
        </Manifest>
    </Object>
</Signature>
```

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Digital Signatures Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/digital-signatures-overview)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcDigitalSignature](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignature)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**