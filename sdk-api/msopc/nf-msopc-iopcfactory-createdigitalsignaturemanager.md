# IOpcFactory::CreateDigitalSignatureManager

## Description

Creates a digital signature manager object for a package object.

## Parameters

### `package` [in]

A pointer to the [IOpcPackage](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpackage) interface of the package object to associate with the digital signature manager object.

### `signatureManager` [out, retval]

A pointer to the [IOpcDigitalSignatureManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignaturemanager) interface of the digital signature manager object that is created for use with the package object.

A digital signature manager object provides access to the Packaging API's digital signature interfaces and methods. These can be used to sign the package represented by the package object or to validate the signatures in a package that has already been signed.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | This method is not implemented for this version of Windows. |
| **OPC_E_DS_DUPLICATE_SIGNATURE_ORIGIN_RELATIONSHIP**<br><br>0x8051001B | More than one relationship of the digital signature origin relationship type exists, but only one such relationship is allowed.<br><br>For more information about this relationship type, see the *OPC*. |
| **OPC_E_DS_INVALID_SIGNATURE_ORIGIN_RELATIONSHIP**<br><br>0x8051001C | A package relationship of type digital signature origin is targeting a location that is external to the package. Digital Signature Origin parts must be located internally.<br><br>For more information about this relationship type, see the *OPC*. |
| **OPC_E_DS_MISSING_SIGNATURE_ORIGIN_PART**<br><br>0x8051001F | A relationship of type digital signature origin was found, but the Digital Signature Origin part itself was not.<br><br>For more information about this relationship type, see the *OPC*. |

## Remarks

If a package is modified while [Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces) are being used to sign the package, signing may fail or result in an inconsistent signature or package.

### Support on Previous Versions of Windows

This method is not supported on versions of Windows prior to Windows 7. For more information, see [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview), and [Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal).

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Digital Signatures Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/digital-signatures-overview)

[ECMA-376 OpenXML](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcFactory](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcfactory)

[Music Bundle Signature Sample](https://learn.microsoft.com/previous-versions/windows/desktop/opc/music-bundle-signature-sample)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal)

**Reference**