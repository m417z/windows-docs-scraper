# IOpcDigitalSignatureManager::SetSignatureOriginPartName

## Description

Sets the part name of the Digital Signature Origin part to the name represented by a specified [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface pointer.

## Parameters

### `signatureOriginPartName` [in]

A pointer to an [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface pointer that represents the desired part name for the Digital Signature Origin part.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **OPC_E_DS_SIGNATURE_ORIGIN_EXISTS**<br><br>0x80510054 | A Digital Signature Origin part already exists in the package and cannot be renamed. |
| **OPC_E_DUPLICATE_PART**<br><br>0x8051000B | A part with the specified part name already exists in the current package. |

## Remarks

If the Digital Signature Origin part exists or if the part name that is in the *signatureOriginPartName* parameter is being used for another part, this method will fail.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Digital Signatures Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/digital-signatures-overview)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcDigitalSignatureManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignaturemanager)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**