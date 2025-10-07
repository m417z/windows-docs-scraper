# CAPICOM\_ERROR\_CODE enumeration

The **CAPICOM\_ERROR\_CODE** enumeration type defines error codes that are returned by CAPICOM.

> [!Note]
> Visual Basic Scripting Edition errors return an **Err.number** value greater than zero. For those errors, **Err.Description** values provide information about the cause of the error. In addition to Visual Basic Scripting Edition errors, CAPICOM errors return the codes defined by **CAPICOM\_ERROR\_CODE**.

## Members

| Member | Description | Value |
|--------|-------------|-------|
| **CAPICOM_E_ENCODE_INVALID_TYPE** | An encoding type that is not valid was used.<br> The following list shows the valid encoding types:

* CAPICOM_ENCODE_ANY
* CAPICOM_ENCODE_BASE64
* CAPICOM_ENCODE_BINARY

\
 | 0x80880100 |
| **CAPICOM_E_EKU_INVALID_OID** | The [**OID**](https://learn.microsoft.com/windows/win32/seccrypto/eku-oid) property of the [**EKU**](https://learn.microsoft.com/windows/win32/seccrypto/eku) object cannot be set because the [**Name**](https://learn.microsoft.com/windows/win32/seccrypto/eku-name) property is not set to CAPICOM_EKU_OTHER.<br> Set the [**Name**](https://learn.microsoft.com/windows/win32/seccrypto/eku-name) property to CAPICOM_EKU_OTHER before setting the [**OID**](https://learn.microsoft.com/windows/win32/seccrypto/eku-oid) property.<br> | 0x80880200 |
| **CAPICOM_E_EKU_OID_NOT_INITIALIZED** | The [**OID**](https://learn.microsoft.com/windows/win32/seccrypto/eku-oid) property of the [**EKU**](https://learn.microsoft.com/windows/win32/seccrypto/eku) object has not been initialized. <br> Either set the [**Name**](https://learn.microsoft.com/windows/win32/seccrypto/eku-name) property to anything other than CAPICOM_EKU_OTHER, or set the **Name** property to CAPICOM_EKU_OTHER and the [**OID**](https://learn.microsoft.com/windows/win32/seccrypto/eku-oid) property to a value.<br> | 0x80880201 |
| **CAPICOM_E_CERTIFICATE_NOT_INITIALIZED** | The [**Certificate**](https://learn.microsoft.com/windows/win32/seccrypto/certificate) object has not been initialized.<br> Usually, this error code is returned when a [**Certificate**](https://learn.microsoft.com/windows/win32/seccrypto/certificate) object is instantiated but not associated with a digital certificate. To associate the object with a digital certificate, either assign it to an existing **Certificate** object or call the [**Import**](https://learn.microsoft.com/windows/win32/seccrypto/certificate-import) method.<br> | 0x80880210 |
| **CAPICOM_E_CERTIFICATE_NO_PRIVATE_KEY** | The [**Certificate**](https://learn.microsoft.com/windows/win32/seccrypto/certificate) object does not have an associated private key.<br> This error code is returned when an attempt is made to sign data using the signer's private key, but the [**Certificate**](https://learn.microsoft.com/windows/win32/seccrypto/certificate) object that is associated with the [**Signer**](https://learn.microsoft.com/windows/win32/seccrypto/signer) object cannot be used for the signing operation.<br> | 0x80880211 |
| **CAPICOM_E_CHAIN_NOT_BUILT** | The [**Chain**](https://learn.microsoft.com/windows/win32/seccrypto/chain) object has not been initialized. <br> To initialize the [**Chain**](https://learn.microsoft.com/windows/win32/seccrypto/chain) object, call the [**Build**](https://learn.microsoft.com/windows/win32/seccrypto/chain-build) method.<br> | 0x80880220 |
| **CAPICOM_E_STORE_NOT_OPENED** | The [**Store**](https://learn.microsoft.com/windows/win32/seccrypto/store) object has not been initialized. <br> To initialize the [**Store**](https://learn.microsoft.com/windows/win32/seccrypto/store) object, call the [**Open**](https://learn.microsoft.com/windows/win32/seccrypto/store-open) method.<br> | 0x80880230 |
| **CAPICOM_E_STORE_EMPTY** | The [**Store**](https://learn.microsoft.com/windows/win32/seccrypto/store) object does not contain any [**Certificate**](https://learn.microsoft.com/windows/win32/seccrypto/certificate) objects.<br> | 0x80880231 |
| **CAPICOM_E_STORE_INVALID_OPEN_MODE** | The *OpenMode* parameter of the [**Store.Open**](https://learn.microsoft.com/windows/win32/seccrypto/store-open) method does not contain a valid value of CAPICOM_STORE_OPEN_MODE.<br> The following list shows the valid values of CAPICOM_STORE_OPEN_MODE:

* CAPICOM_STORE_OPEN_READ_ONLY
* CAPICOM_STORE_OPEN_READ_WRITE
* CAPICOM_STORE_OPEN_MAXIMUM_ALLOWED
* CAPICOM_STORE_OPEN_EXISTING_ONLY
* CAPICOM_STORE_OPEN_INCLUDE_ARCHIVED

\
 | 0x80880232 |
| **CAPICOM_E_STORE_INVALID_SAVE_AS_TYPE** | The *SaveAs* value passed to the [**Export**](https://learn.microsoft.com/windows/win32/seccrypto/store-export) method of the [**Store**](https://learn.microsoft.com/windows/win32/seccrypto/store) object was not valid. <br> The following list shows the valid *SaveAs* values:

* CAPICOM_STORE_SAVE_AS_SERIALIZED
* CAPICOM_STORE_SAVE_AS_PKCS7

\
 | 0x80880233 |
| **CAPICOM_E_ATTRIBUTE_NAME_NOT_INITIALIZED** | The [**Name**](https://learn.microsoft.com/windows/win32/seccrypto/attribute-name) property of the [**Attribute**](https://learn.microsoft.com/windows/win32/seccrypto/attribute) object has not been initialized. <br> Set the [**Name**](https://learn.microsoft.com/windows/win32/seccrypto/attribute-name) property.<br> | 0x80880240 |
| **CAPICOM_E_ATTRIBUTE_VALUE_NOT_INITIALIZED** | The [**Value**](https://learn.microsoft.com/windows/win32/seccrypto/attribute-value) property of the [**Attribute**](https://learn.microsoft.com/windows/win32/seccrypto/attribute) object has not been initialized. <br> Set the [**Value**](https://learn.microsoft.com/windows/win32/seccrypto/attribute-value) property.<br> | 0x80880241 |
| **CAPICOM_E_ATTRIBUTE_INVALID_NAME** | The [**Name**](https://learn.microsoft.com/windows/win32/seccrypto/attribute-name) property of the [**Attribute**](https://learn.microsoft.com/windows/win32/seccrypto/attribute) object is not valid. <br> The following list shows the valid attribute names:

* CAPICOM_AUTHENTICATED_ATTRIBUTE_SIGNING_TIME
* CAPICOM_AUTHENTICATED_ATTRIBUTE_DOCUMENT_NAME
* CAPICOM_AUTHENTICATED_ATTRIBUTE_DOCUMENT_DESCRIPTION

\
 | 0x80880242 |
| **CAPICOM_E_ATTRIBUTE_INVALID_VALUE** | The [**Value**](https://learn.microsoft.com/windows/win32/seccrypto/attribute-value) property of the [**Attribute**](https://learn.microsoft.com/windows/win32/seccrypto/attribute) object is not valid because the data type does not match the data type indicated by the **Name** property. <br> For example, if the [**Name**](https://learn.microsoft.com/windows/win32/seccrypto/attribute-value) property is set to CAPICOM_AUTHENTICATED_ATTRIBUTE_SIGNING_TIME, the data type must be **DATE**.<br> | 0x80880243 |
| **CAPICOM_E_SIGNER_NOT_INITIALIZED** | The [**Signer**](https://learn.microsoft.com/windows/win32/seccrypto/signer) object has not been initialized. <br> To initialize the [**Signer**](https://learn.microsoft.com/windows/win32/seccrypto/signer) object, set the [**Certificate**](https://learn.microsoft.com/windows/win32/seccrypto/signer-certificate) property.<br> | 0x80880250 |
| **CAPICOM_E_SIGNER_NOT_FOUND** | The signer cannot be found in the [**SignedData**](https://learn.microsoft.com/windows/win32/seccrypto/signeddata) object. <br> Usually, this does not happen with a [**SignedData**](https://learn.microsoft.com/windows/win32/seccrypto/signeddata) object that was created by CAPICOM; however, if the **SignedData** object was created by a third-party product, the signer's certificate may not be included in the PKCS #7 structure.<br> | 0x80880251 |
| **CAPICOM_E_SIGNER_NO_CHAIN** | A [**Chain**](https://learn.microsoft.com/windows/win32/seccrypto/chain) object cannot be found in the [**Signer**](https://learn.microsoft.com/windows/win32/seccrypto/signer) object.<br> | 0x80880252 // v2.0 |
| **CAPICOM_E_SIGNER_INVALID_USAGE** | An attempt is made to use the signer in a way that is not valid.<br> | 0x80880253 //v2.0 |
| **CAPICOM_E_SIGN_NOT_INITIALIZED** | The [**SignedData**](https://learn.microsoft.com/windows/win32/seccrypto/signeddata) object has not been initialized. <br> To initialize the [**SignedData**](https://learn.microsoft.com/windows/win32/seccrypto/signeddata) object, set the [**Content**](https://learn.microsoft.com/windows/win32/seccrypto/signeddata-content) property or call the [**Verify**](https://learn.microsoft.com/windows/win32/seccrypto/signeddata-verify) method.<br> | 0x80880260 |
| **CAPICOM_E_SIGN_INVALID_TYPE** | The [**SignedData**](https://learn.microsoft.com/windows/win32/seccrypto/signeddata) object contains a type that is not valid. <br> Usually, this happens when an attempt is made to verify an enveloped message with a [**SignedData**](https://learn.microsoft.com/windows/win32/seccrypto/signeddata) object or vice versa.<br> | 0x80880261 |
| **CAPICOM_E_SIGN_NOT_SIGNED** | The [**SignedData**](https://learn.microsoft.com/windows/win32/seccrypto/signeddata) object has not been signed. <br> To sign the [**SignedData**](https://learn.microsoft.com/windows/win32/seccrypto/signeddata) object, call the [**Sign**](https://learn.microsoft.com/windows/win32/seccrypto/signeddata-sign) method.<br> | 0x80880262 |
| **CAPICOM_E_INVALID_ALGORITHM** | The algorithm value for the [**Name**](https://learn.microsoft.com/windows/win32/seccrypto/algorithm-name) property of the [**Algorithm**](https://learn.microsoft.com/windows/win32/seccrypto/algorithm) object is not valid. <br> The following list shows the valid algorithm values for the [**Name**](https://learn.microsoft.com/windows/win32/seccrypto/algorithm-name) property:

* CAPICOM_ENCRYPTION_ALGORITHM_RC2
* CAPICOM_ENCRYPTION_ALGORITHM_RC4
* CAPICOM_ENCRYPTION_ALGORITHM_DES
* CAPICOM_ENCRYPTION_ALGORITHM_3DES

\
 | 0x80880270 |
| **CAPICOM_E_INVALID_KEY_LENGTH** | The key length value for the [**KeyLength**](https://learn.microsoft.com/windows/win32/seccrypto/algorithm-keylength) property of the [**Algorithm**](https://learn.microsoft.com/windows/win32/seccrypto/algorithm) object is not valid. <br> The following list shows the valid key length values for the [**KeyLength**](https://learn.microsoft.com/windows/win32/seccrypto/algorithm-keylength) property:

* CAPICOM_ENCRYPTION_KEY_LENGTH_MAXIMUM
* CAPICOM_ENCRYPTION_KEY_LENGTH_40_BITS
* CAPICOM_ENCRYPTION_KEY_LENGTH_56_BITS
* CAPICOM_ENCRYPTION_KEY_LENGTH_128_BITS

\
 | 0x80880271 |
| **CAPICOM_E_ENVELOP_NOT_INITIALIZED** | The [**EnvelopedData**](https://learn.microsoft.com/windows/win32/seccrypto/envelopeddata) object has not been initialized. <br> To initialize the [**EnvelopedData**](https://learn.microsoft.com/windows/win32/seccrypto/envelopeddata) object, either set the [**Content**](https://learn.microsoft.com/windows/win32/seccrypto/envelopeddata-content) property or call the [**Decrypt**](https://learn.microsoft.com/windows/win32/seccrypto/envelopeddata-decrypt) method.<br> | 0x80880280 |
| **CAPICOM_E_ENVELOP_INVALID_TYPE** | The [**EnvelopedData**](https://learn.microsoft.com/windows/win32/seccrypto/envelopeddata) object contains a type that is not valid. <br> Usually, this happens when an attempt is made to verify a signed message with an [**EnvelopedData**](https://learn.microsoft.com/windows/win32/seccrypto/envelopeddata) object or vice versa.<br> | 0x80880281 |
| **CAPICOM_E_ENVELOP_NO_RECIPIENT** | There is no recipient specified in the [**EnvelopedData**](https://learn.microsoft.com/windows/win32/seccrypto/envelopeddata) object when the [**Encrypt**](https://learn.microsoft.com/windows/win32/seccrypto/envelopeddata-encrypt) method of an **EnvelopedData** object is called. <br> To add a recipient, call the [**Recipients.Add**](https://learn.microsoft.com/windows/win32/seccrypto/recipients-add) method.<br> | 0x80880282 |
| **CAPICOM_E_ENVELOP_RECIPIENT_NOT_FOUND** | The recipient cannot be found in the [**EnvelopedData**](https://learn.microsoft.com/windows/win32/seccrypto/envelopeddata) object. <br> Usually, this does not happen with an [**EnvelopedData**](https://learn.microsoft.com/windows/win32/seccrypto/envelopeddata) object that was created by CAPICOM; however, if the **EnvelopedData** object was created by a third-party product, the recipient's certificate may not be included in the PKCS #7 structure.<br> | 0x80880283 |
| **CAPICOM_E_ENCRYPT_NOT_INITIALIZED** | The [**EncryptedData**](https://learn.microsoft.com/windows/win32/seccrypto/encrypteddata) object has not been initialized. <br> To initialize the [**EncryptedData**](https://learn.microsoft.com/windows/win32/seccrypto/encrypteddata) object, either set the [**Content**](https://learn.microsoft.com/windows/win32/seccrypto/encrypteddata-content) property or call the [**Decrypt**](https://learn.microsoft.com/windows/win32/seccrypto/encrypteddata-decrypt) method.<br> | 0x80880290 |
| **CAPICOM_E_ENCRYPT_INVALID_TYPE** | The [**EncryptedData**](https://learn.microsoft.com/windows/win32/seccrypto/encrypteddata) object is not a valid type. <br> Usually, this means the data is corrupted.<br> | 0x80880291 |
| **CAPICOM_E_ENCRYPT_NO_SECRET** | The secret of an [**EncryptedData**](https://learn.microsoft.com/windows/win32/seccrypto/encrypteddata) object has not been initialized. <br> To initialize the secret of an [**EncryptedData**](https://learn.microsoft.com/windows/win32/seccrypto/encrypteddata) object, call the [**SetSecret**](https://learn.microsoft.com/windows/win32/seccrypto/encrypteddata-setsecret) method.<br> | 0x80880292 |
| **CAPICOM_E_PRIVATE_KEY_NOT_INITIALIZED** | The [**PrivateKey**](https://learn.microsoft.com/windows/win32/seccrypto/privatekey) object has not been initialized.<br> | 0x80880300 // v2.0 |
| **CAPICOM_E_PRIVATE_KEY_NOT_EXPORTABLE** | The [**PrivateKey**](https://learn.microsoft.com/windows/win32/seccrypto/privatekey) object cannot be exported.<br> | 0x80880301 // v2.0 |
| **CAPICOM_E_ENCODE_NOT_INITIALIZED** | The [**EncodedData**](https://learn.microsoft.com/windows/win32/seccrypto/encodeddata) object has not been initialized.<br> | 0x80880320 // v2.0 |
| **CAPICOM_E_EXTENSION_NOT_INITIALIZED** | The [**Extension**](https://learn.microsoft.com/windows/win32/seccrypto/extension) object has not been initialized.<br> | 0x80880330 // v2.0 |
| **CAPICOM_E_PROPERTY_NOT_INITIALIZED** | The [**PropID**](https://learn.microsoft.com/windows/win32/seccrypto/extendedproperty-propid) property of the [**ExtendedProperty**](https://learn.microsoft.com/windows/win32/seccrypto/extendedproperty) object has not been initialized.<br> | 0x80880340 // v2.0 |
| **CAPICOM_E_FIND_INVALID_TYPE** | The *FindType* parameter of the [**Certificates.Find**](https://learn.microsoft.com/windows/win32/seccrypto/certificates-find) method is not a value of the [**CAPICOM_CERTIFICATE_FIND_TYPE**](https://learn.microsoft.com/windows/win32/seccrypto/capicom-certificate-find-type) enumeration.<br> | 0x80880350 // v2.0 |
| **CAPICOM_E_FIND_INVALID_PREDEFINED_POLICY** | The specified predefined policy for the find operation is not valid.<br> | 0x80880351 // v2.0 |
| **CAPICOM_E_CODE_NOT_INITIALIZED** | The [**SignedCode**](https://learn.microsoft.com/windows/win32/seccrypto/signedcode) object has not been initialized.<br> | 0x80880360 // v2.0 |
| **CAPICOM_E_CODE_NOT_SIGNED** | The [**SignedCode**](https://learn.microsoft.com/windows/win32/seccrypto/signedcode) object has not been signed.<br> To sign the [**SignedCode**](https://learn.microsoft.com/windows/win32/seccrypto/signedcode) object, call the [**Sign**](https://learn.microsoft.com/windows/win32/seccrypto/signedcode-sign) method.<br> | 0x80880361 // v2.0 |
| **CAPICOM_E_CODE_DESCRIPTION_NOT_INITIALIZED** | The [**Description**](https://learn.microsoft.com/windows/win32/seccrypto/signedcode-description) property of the [**SignedCode**](https://learn.microsoft.com/windows/win32/seccrypto/signedcode) object has not been initialized.<br> | 0x80880362 // v2.0 |
| **CAPICOM_E_CODE_DESCRIPTION_URL_NOT_INITIALIZED** | The [**DescriptionURL**](https://learn.microsoft.com/windows/win32/seccrypto/signedcode-descriptionurl) property of the [**SignedCode**](https://learn.microsoft.com/windows/win32/seccrypto/signedcode) object has not been initialized.<br> | 0x80880363 // v2.0 |
| **CAPICOM_E_CODE_INVALID_TIMESTAMP_URL** | The *URL* parameter of the [**SignedCode.Timestamp**](https://learn.microsoft.com/windows/win32/seccrypto/signedcode-timestamp) method is not valid.<br> | 0x80880364 // v2.0 |
| **CAPICOM_E_HASH_NO_DATA** | The [**HashedData**](https://learn.microsoft.com/windows/win32/seccrypto/hasheddata) object does not contain any data.<br> | 0x80880370 // v2.0 |
| **CAPICOM_E_INVALID_CONVERT_TYPE** | The convert type is not valid.<br> | 0x80880380 // v2.0 |
| **CAPICOM_E_NOT_SUPPORTED** | The requested operation is not supported in the current platform. <br> | 0x80880900 |
| **CAPICOM_E_UI_DISABLED** | When signing, the [**Certificate**](https://learn.microsoft.com/windows/win32/seccrypto/signer-certificate) property of the [**Signer**](https://learn.microsoft.com/windows/win32/seccrypto/signer) object has not been set, but the prompt for the user certificate has been disabled. <br> Either enable the prompt by setting the [**EnablePromptForCertificateUI**](https://learn.microsoft.com/windows/win32/seccrypto/settings-enablepromptforcertificateui) property of the [**Settings**](https://learn.microsoft.com/windows/win32/seccrypto/settings) object, or set the [**Certificate**](https://learn.microsoft.com/windows/win32/seccrypto/signer-certificate) property of the [**Signer**](https://learn.microsoft.com/windows/win32/seccrypto/signer) object.<br> | 0x80880901 |
| **CAPICOM_E_CANCELLED** | The operation has been canceled by the user. <br> This happens when the user is prompted for permission to carry out a certain operation, such as accessing the private key, and the user cancels the operation.<br> | 0x80880902 |
| **CAPICOM_E_NOT_ALLOWED** | The attempted operation is not allowed.<br> For example, changing the [**PropID**](https://learn.microsoft.com/windows/win32/seccrypto/extendedproperty-propid) property of an [**ExtendedProperty**](https://learn.microsoft.com/windows/win32/seccrypto/extendedproperty) object is not allowed if the object is attached to a certificate.<br> | 0x80880903 // v2.0 |
| **CAPICOM_E_OUT_OF_RESOURCE** | CAPICOM has run out of a resource.<br> | 0x80880904 // v2.0 |
| **CAPICOM_E_INTERNAL** | An internal error has occurred. <br> Contact Microsoft Technical Support for assistance.<br> | 0x80880911 |
| **CAPICOM_E_UNKNOWN** | An unknown error has occurred. <br> Collect as much information as possible, and contact your vendor.<br> | 0x80880999 |

## Requirements

| Requirement | Value |
|----------------------------|--------------------------------------------------------------------------------------|
| Redistributable<br> | CAPICOM 2.0 or later on Windows Server 2003 and Windows XP<br> |
| Header<br> | Capicom.h |

