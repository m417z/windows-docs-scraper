# IXpsSignatureManager::Sign

## Description

Signs the contents of an XPS package as specified by the signing options and returns the resulting digital signature.

## Parameters

### `signOptions` [in]

A pointer to the [IXpsSigningOptions](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssigningoptions) interface that contains the signing options.

**Note**

The SignatureMethod and the DigestMethod properties of the [IXpsSigningOptions](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssigningoptions) interface must be initialized before the pointer to that interface can be used in the *signOptions* parameter.

### `x509Certificate` [in]

A pointer to the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the X.509 certificate to be used for signing.

### `signature` [out, retval]

A pointer to the [IXpsSignature](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignature) interface that contains the new digital signature.

If successful, this method creates the signature part, adds it to the package, and in *signature* returns a pointer to the interface of that signature part.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For return values that are not listed in this table, see [XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85)) and [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_MARKUP_COMPATIBILITY_ELEMENTS** | The [XPS_SIGN_FLAGS](https://learn.microsoft.com/windows/win32/api/xpsdigitalsignature/ne-xpsdigitalsignature-xps_sign_flags) value specified that no markup compatibility elements were expected; however, markup compatibility elements were found. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *signOptions* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |
| **XPS_E_PACKAGE_NOT_OPENED** | An XPS package has not yet been opened in the signature manager. |

## Remarks

Adding a new signature does not overwrite the original file or stream that was read by calling the [LoadPackageFile](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssignaturemanager-loadpackagefile) or [LoadPackageStream](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssignaturemanager-loadpackagestream) method.
The signature will be added to the in-memory copy of the XPS package until the package is saved (by calling the [SavePackageToFile](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssignaturemanager-savepackagetofile) or [SavePackageToStream](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssignaturemanager-savepackagetostream) method).

If the new signature includes parts that contain markup compatibility elements, the default is for this method to fail with an error of **XPS_E_MARKUP_COMPATIBILITY_ELEMENTS**.
To override this behavior, call [IXpsSigningOptions::SetFlags](https://learn.microsoft.com/windows/win32/api/xpsdigitalsignature/ne-xpsdigitalsignature-xps_sign_flags); this will set the **XPS_SIGN_FLAGS_IGNORE_MARKUP_COMPATIBILITY** flag in the [IXpsSigningOptions](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssigningoptions) interface referenced by the *signOptions* parameter.

If this method returns an **HRESULT** value that is not in the list of its return values, the signature manager should be released and recreated.

This method will succeed even if the new signature breaks existing signatures.

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[IXpsSignature](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignature)

[IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager)

[IXpsSigningOptions](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssigningoptions)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85))

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))