# ICertPropertyRenewal::InitializeFromCertificateHash

## Description

The **InitializeFromCertificateHash** method initializes the object from the new certificate.

## Parameters

### `MachineContext` [in]

A **VARIANT_BOOL** value that indicates whether the certificate store is for the local computer or the current user. Specify **VARIANT_TRUE** for the computer and **VARIANT_FALSE** for the user.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the input string that contains the DER-encoded certificate.

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
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The object is already initialized. |

## Remarks

 This method creates a SHA-1 hash by using the specified certificate. The certificate must be encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) as defined by the [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) standard. You must also specify the type of Unicode encoding applied to the string that contains the DER-encoded certificate.

Typically the [ICertPropertyRenewal](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyrenewal) object is initialized during the enrollment process. You can retrieve the certificate used during enrollment by calling the [Certificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-get_certificate) property on the [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment) interface.

Call the [SetValueOnCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-setvalueoncertificate) method to associate the property with a certificate. Call the [Renewal](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyrenewal-get_renewal) property to retrieve the hash.

## See also

[ICertPropertyRenewal](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyrenewal)