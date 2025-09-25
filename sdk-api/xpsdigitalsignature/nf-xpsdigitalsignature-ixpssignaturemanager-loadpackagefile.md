# IXpsSignatureManager::LoadPackageFile

## Description

Loads an existing XPS package from a file into the digital signature manager.

## Parameters

### `fileName` [in]

The file name of the XPS package to be loaded.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For return values that are not listed in this table, see [XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85)) and [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *fileName* is **NULL**. |
| **XPS_E_PACKAGE_ALREADY_OPENED** | An XPS package has already been opened in the signature manager. |

## Remarks

 After the interface has been instantiated, the XPS package must be loaded by calling this method or [LoadPackageStream](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssignaturemanager-loadpackagestream) before
calling any other method in this interface.

After an XPS package has been loaded into an instance of [IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager), calling **LoadPackageFile** or [LoadPackageStream](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssignaturemanager-loadpackagestream) in the same instance will return an error.

After **LoadPackageFile** or [LoadPackageStream](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssignaturemanager-loadpackagestream) has been called, the same object cannot be reused for another XPS package file or stream. To load another XPS package, a new instance of [IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager) must be instantiated.

[LoadPackageStream](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssignaturemanager-loadpackagestream) does not validate all content of the XPS package; it does not, for example, detect invalid markup in a FixedPage part.

## See also

[IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85))

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))