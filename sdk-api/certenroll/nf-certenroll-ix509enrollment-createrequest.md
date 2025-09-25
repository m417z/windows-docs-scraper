# IX509Enrollment::CreateRequest

## Description

The **CreateRequest** method retrieves an encoded certificate request. The certificate request is contained in a byte array that is encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) as defined by the [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) standard. The DER-encoded byte array is represented by a string that is either a pure binary sequence or Unicode encoded. This method is web enabled.

## Parameters

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the DER-encoded request. The default value is **XCN_CRYPT_STRING_BASE64**.

### `pValue` [out]

Pointer to a **BSTR** variable that contains the DER-encoded request.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****CERTSRV_E_PROPERTY_EMPTY**** | The certificate request cannot be found. |
| ****OLE_E_BLANK**** | The enrollment object has not been initialized. |

## Remarks

The **CreateRequest** method calls the [Encode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-encode) method, if necessary, to encode the raw data from the associated request object.

This method uses the information provided during initialization and other properties that have been specified, creates a dummy certificate and places it in the request store. The method also creates a key pair if necessary. Depending on how you initialize the enrollment object and on what properties you set, there may be no need to create a key pair. For example, if you are renewing a certificate by using an existing key, or if the [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) object associated with the certificate request represents an existing key, this method does not create a new key pair.

If a smartcard is involved, this method encodes external properties as extensions, includes them in the dummy certificate, and writes the dummy certificate to the smartcard key container. Smartcard logon certificates are encoded to the request store, not the personal store.

Before calling the **CreateRequest** method, you must initialize the [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment) object by calling one of the following methods.

* [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-initialize)
* [InitializeFromRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-initializefromrequest)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-initializefromtemplatename)

## See also

[IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest)

[IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment)