# ISignerCertificate::Initialize

## Description

The **Initialize** method initializes the object from a signing certificate.

## Parameters

### `MachineContext` [in]

A **VARIANT_BOOL** variable that indicates whether to search the local computer certificate store context or the user context to find the certificate identified by the *strCertificate* parameter. Specify **VARIANT_TRUE** for the computer and **VARIANT_FALSE** for the user.

### `VerifyType` [in]

An [X509PrivateKeyVerify](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509privatekeyverify) enumeration value that specifies whether the private key used to sign the certificate must be verified and, if so, whether the verification must be silent or allows user input.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded certificate string.

### `strCertificate` [in]

A **BSTR** variable that contains the DER-encoded certificate.

Beginning with Windows 7 and Windows Server 2008 R2, you can specify a certificate thumb print or serial number rather than an encoded certificate. Doing so causes the function to search the appropriate local stores for the matching certificate. Keep in mind the following points:

* The **BSTR** must be an even number of hexadecimal digits.
* Whitespace between hexadecimal pairs is ignored.
* The *Encoding* parameter must be set to **XCN_CRYPT_STRING_HEXRAW**.
* The *MachineContext* parameter determines whether the user or computer stores or both are searched.
* If a private key is needed, only the personal and request stores are searched.
* If a private key is not needed, the root and intermediate CA stores are also searched.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The [ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate) object has already been initialized. |

## Remarks

The **Initialize** method:

* Verifies whether the private key associated with the certificate exists.
* Creates an [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object and assigns it to the [ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate) object.
* Retrieves the public key algorithm from the private key.
* Assigns the public key algorithm to the [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object.

Set the following properties before calling **Initialize**:

* [ParentWindow](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_parentwindow)
* [Pin](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-put_pin)
* [Silent](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_silent)
* [UIContextMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_uicontextmessage)

## See also

[ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate)