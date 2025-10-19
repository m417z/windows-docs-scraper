# IX509CertificateRequestPkcs7::InitializeDecode

## Description

The **InitializeDecode** method decodes an existing signed or unsigned PKCS #7 request object and uses it to initialize the new PKCS #7 object. The existing request is contained in a byte array that has been encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) as defined by the [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) standard. The byte array is represented by a string that is either a pure binary sequence or is Unicode encoded.

## Parameters

### `strEncodedData` [in]

A **BSTR** variable that contains the DER-encoded request.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the input string that contains the DER-encoded request. The default value is **XCN_CRYPT_STRING_BASE64**.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The request object has already been initialized. |

## Remarks

The **InitializeDecode** method:

* Decodes the PKCS #7 request specified on input.
* Uses the decoded object to create an inner PKCS #10 request with the following collections:
  + An empty [ICryptAttributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icryptattributes) collection.
  + An empty [IX509Extensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensions) collection.
  + An empty [IObjectIds](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectids) collection for critical extensions.
  + An empty [IObjectIds](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectids) collection for attribute and extension OIDs to be suppressed from the new request.
* Adds the decoded extensions to the [IX509Extensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensions) collection.
* Adds the decoded attributes to the [ICryptAttributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icryptattributes) collection
* Sets the [ClientId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_clientid) property.
* Sets the [TemplateObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-get_templateobjectid) property.
* Uses the signature on the original PKCS #7 request to create a new [ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate) object.
* Retrieves an [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object from the [ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate) object.
* Initializes the new [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object by using the original signature and hash algorithms.
* Sets the PKCS #10 request as the inner request object.

By default, the **InitializeDecode** method assumes that the certificate request to be decoded is for an end user. Beginning with Windows 8 and Windows Server 2012, you can change this default behavior. After creating an instance of the [IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7) interface, call **InitializeDecode** by setting the *Encoding* parameter to **XCN_CRYPT_STRING_BINARY** and the *strEncodedData* parameter to one of the following values:

| Value | Description |
| --- | --- |
| L"ContextMachine" | The encoded certificate request is for a computer. |
| L"ContextUser" | The encoded certificate request is for an end user. |
| L"ContextAdministratorForceMachine" | The encoded certificate is being requested by an administrator acting on the behalf of a computer. |

Then, call the **InitializeDecode** method again with the encoded certificate set in the *strEncodedData* argument.

## See also

[IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7)