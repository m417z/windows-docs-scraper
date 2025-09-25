# IXpsSignatureManager::SetSignatureOriginPartName

## Description

Sets the part name of the signature origin part.

## Parameters

### `signatureOriginPartName` [in]

A pointer to an [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the part name of the signature origin part.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code shown in the table that follows or an **HRESULT** error code that is returned by [IOpcDigitalSignatureManager::SetSignatureOriginPartName](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcdigitalsignaturemanager-setsignatureoriginpartname).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_PACKAGE_NOT_OPENED** | An XPS package was not loaded into the digital signature manager before calling this method. |

## Remarks

The part name cannot be set if any signatures exist.

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)