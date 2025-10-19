# IX509Enrollment::CreatePFX

## Description

The **CreatePFX** method creates a Personal Information Exchange (PFX) message. The message is contained in a byte array that is encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) as defined by the [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) standard. The DER-encoded byte array is represented by a string that is either a pure binary sequence or is Unicode encoded.

## Parameters

### `strPassword` [in]

A **BSTR** variable that contains a password for the PFX message. This can be **NULL** to indicate that no password is used. When you have finished using the password, clear it from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about protecting the password, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `ExportOptions` [in]

A [PFXExportOptions](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-pfxexportoptions) enumeration value that specifies how much of the certificate chain is exported. You can export the certificate only, the certificate chain without the root, or the entire chain.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the DER-encoded message. The default value is **XCN_CRYPT_STRING_BASE64**.

### `pValue` [out]

Pointer to a **BSTR** variable that contains the DER-encoded PFX message.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The certificate cannot be found. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | No certificate chain can be found. |
| **OLE_E_BLANK** | The enrollment object has not been initialized. |

## Remarks

The PFX format is also known as PKCS #12. The **CreatePFX** method:

* Opens the certificate store in memory for the default provider.
* Adds the installed certificate to the store or builds the certificate chain adds a link to it.
* Exports the certificate and the private key to a PFX message depending on the export options specified.
* Encodes the exported message by using DER.

Before calling this method, you must initialize the [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment) object by calling one of the following methods.

* [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-initialize)
* [InitializeFromRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-initializefromrequest)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-initializefromtemplatename)

Further, you must return successfully from the [Enroll](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-enroll) method.

## See also

[IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment)