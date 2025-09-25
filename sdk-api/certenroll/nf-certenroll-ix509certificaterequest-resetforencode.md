# IX509CertificateRequest::ResetForEncode

## Description

The **ResetForEncode** method restores the state of the request object to that which existed before the [Encode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-encode) method was called.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****CERTSRV_E_PROPERTY_EMPTY**** | Certificate extensions and attributes have not been defined. |
| ****HRESULT_FROM_WIN32(ERROR_INVALID_STATE)**** | The request object is not encoded. |
| ****OLE_E_BLANK**** | The object is not initialized. |

## Remarks

You can use this method to reconfigure (re-encode and re-sign) a certificate request in response to rejection of the request by a certification authority. The signature and the raw data are cleared. The extensions and attributes are reset to the values they had before the [Encode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-encode) method was called, but critical extension flags are not. For a CMC request object, each nested request is also reset.

This method is typically used for a CMC key archival request when the private key is encrypted and included in the request.

## See also

[IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest)

[IX509CertificateRequestCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcertificate)

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)

[IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7)

[IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)