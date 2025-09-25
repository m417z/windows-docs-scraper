# ICertRequest2::GetFullResponseProperty

## Description

The **GetFullResponseProperty** method retrieves the cached response data returned by the server.

## Parameters

### `PropId` [in]

The data to be retrieved. If the property is indexed, use *PropIndex* to specify the index.
This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **FR_PROP_NONE**<br><br>0 | No data. |
| **FR_PROP_FULLRESPONSE**<br><br>1 | All the cached data is retrieved (binary data). |
| **FR_PROP_STATUSINFOCOUNT**<br><br>2 | The number of responses in cache data (long, indexed property). |
| **FR_PROP_BODYPARTSTRING**<br><br>3 | Hierarchy data (string, indexed property). |
| **FR_PROP_STATUS**<br><br>4 | The request status value (long, indexed property). |
| **FR_PROP_STATUSSTRING**<br><br>5 | The request status string (string, indexed property). |
| **FR_PROP_OTHERINFOCHOICE**<br><br>6 | Choice for other information (long, indexed property). This can be one of the following values.<br><br>* CMC_OTHER_INFO_NO_CHOICE<br>* CMC_OTHER_INFO_FAIL_CHOICE<br>* CMC_OTHER_INFO_PEND_CHOICE |
| **FR_PROP_FAILINFO**<br><br>7 | The request failure information (long, indexed property). |
| **FR_PROP_PENDINFOTOKEN**<br><br>8 | The request pending token (binary, indexed property). |
| **FR_PROP_PENDINFOTIME**<br><br>9 | The request pending date (**DATE**, indexed property). |
| **FR_PROP_ISSUEDCERTIFICATEHASH**<br><br>10 | The hash of the issued certificate is retrieved (binary, indexed property). |
| **FR_PROP_ISSUEDCERTIFICATE**<br><br>11 | The issued certificate is retrieved (binary, indexed property). |
| **FR_PROP_ISSUEDCERTIFICATECHAIN**<br><br>12 | The issued certificate (binary, indexed property). |
| **FR_PROP_ISSUEDCERTIFICATECRLCHAIN**<br><br>13 | The issued certificate chain (binary, indexed property). |
| **FR_PROP_ENCRYPTEDKEYHASH**<br><br>14 | The encrypted key hash (binary, indexed property). |
| **FR_PROP_FULLRESPONSENOPKCS7**<br><br>15 | All the cached data is retrieved except for the PKCS #7 (binary). |
| **FR_PROP_CAEXCHANGECERTIFICATEHASH**<br><br>16 | The CA exchange certificate hash. |
| **FR_PROP_CAEXCHANGECERTIFICATE**<br><br>17 | The CA exchange certificate. |
| **FR_PROP_CAEXCHANGECERTIFICATECHAIN**<br><br>18 | The CA exchange certificate chain. |
| **FR_PROP_CAEXCHANGECERTIFICATECRLCHAIN**<br><br>19 | The CA exchange certificate CLR chain. |
| **FR_PROP_ATTESTATIONCHALLENGE**<br><br>20 | The key attestation challenge response |
| **FR_PROP_ATTESTATIONPROVIDERNAME**<br><br>21 | The name of the key storage provider for key attestation. |

### `PropIndex` [in]

The zero-based index when *PropId* is an indexed property. If *PropId* is not an indexed property, then *PropIndex* must be zero.

### `PropType` [in]

The type of data returned in *pvarPropertyValue*. The property type here must match the type of data specified by the *PropId* parameter.

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PROPTYPE_LONG**<br><br>1 | Signed long data. |
| **PROPTYPE_DATE**<br><br>2 | Date data (includes date and time). |
| **PROPTYPE_BINARY**<br><br>3 | Binary data. |
| **PROPTYPE_STRING**<br><br>4 | String data. |

### `Flags` [in]

The format of the data returned in *pvarPropertyValue*. The flag set here must match the type of data specified by the *PropId* parameter.

For more information, see Remarks.
This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CR_OUT_BASE64HEADER**<br><br>0 | BASE64 format with begin/end header. |
| **CR_OUT_BASE64**<br><br>1 | BASE64 format without begin/end header. |
| **CR_OUT_BINARY**<br><br>2 | Binary format. |

### `pvarPropertyValue` [out]

The data returned.

## Return value

### C++

If the method succeeds, the method returns S_OK and *pvarPropertyValue* contains the returned data.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a **Variant** that contains the returned data.

## Remarks

The following *PropId* values return binary data, which means that the *Flags* parameter must set to CR_OUT_BINARY:

* FR_PROP_FULLRESPONSE
* FR_PROP_ISSUEDCERTIFICATEHASH
* FR_PROP_ISSUEDCERTIFICATE
* FR_PROP_ISSUEDCERTIFICATECHAIN
* FR_PROP_ISSUEDCERTIFICATECRLCHAIN
* FR_PROP_ENCRYPTEDKYEHASH
* FR_PROP_FULLRESPONSENOPKCS7

This method is called after the [ICertRequest3::Submit](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-submit) or [ICertRequest3::RetrievePending](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-retrievepending) methods have been called. These methods populate the cached data that is returned by **GetFullResponseProperty**.

After the **ICertRequest3::GetFullResponseProperty** method returns its data, the following methods can be called:

* [ICEnroll4::AcceptResponse](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll4-acceptresponse) can be called to install the returned certificate.
* [ICEnroll4::GetCertFromResponse](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll4-getcertfromresponse) can be called to parse the certificate from the response.