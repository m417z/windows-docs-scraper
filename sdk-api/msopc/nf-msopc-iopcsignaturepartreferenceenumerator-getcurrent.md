# IOpcSignaturePartReferenceEnumerator::GetCurrent

## Description

Gets the [IOpcSignaturePartReference](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturepartreference) interface pointer at the current position of the enumerator.

## Parameters

### `partReference` [out, retval]

An [IOpcSignaturePartReference](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturepartreference) interface pointer.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *partReference* parameter is **NULL**. |
| **OPC_E_ENUM_COLLECTION_CHANGED**<br><br>0x80510050 | The enumerator is invalid because the underlying set has changed. |
| **OPC_E_ENUM_INVALID_POSITION**<br><br>0x80510053 | The enumerator cannot perform this operation from its current position. |

## Remarks

When an enumerator is created, the current position precedes the first pointer. To set the current position to the first pointer of the enumerator, call the [MoveNext](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsignaturepartreferenceenumerator-movenext) method after creating the enumerator.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcSignaturePartReferenceEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturepartreferenceenumerator)

[IOpcSignaturePartReferenceSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturepartreferenceset)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**