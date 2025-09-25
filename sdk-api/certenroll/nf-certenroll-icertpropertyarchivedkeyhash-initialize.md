# ICertPropertyArchivedKeyHash::Initialize

## Description

The **Initialize** method initializes the object from a byte array that contains the hash. The byte array is represented as a Unicode-encoded string.

## Parameters

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the input string.

### `strArchivedKeyHashValue` [in]

A **BSTR** variable that contains a SHA-1 hash of the encrypted private key.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The object is already initialized. |

## Remarks

 Call the [SetValueOnCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-setvalueoncertificate) method to associate the property with a certificate. Call the [ArchivedKeyHash](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyarchivedkeyhash-get_archivedkeyhash) property to retrieve the hash.

## See also

[ArchivePrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-get_archiveprivatekey)

[ICertPropertyArchivedKeyHash](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyarchivedkeyhash)

[KeyArchivalCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-get_keyarchivalcertificate)