# ICertRequest2::GetIssuedCertificate

## Description

The **GetIssuedCertificate** method retrieves a certificate's disposition by specifying either the request ID or the certificate serial number.

This method is effectively the same as calling [ICertRequest3::RetrievePending](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-retrievepending), with the additional capability of specifying a serial number for the certificate in question.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the Certificate Services server. The string can be either an HTTPS URL for an enrollment server or in the form *ComputerName***\\***CAName*, where *ComputerName* is the network name of the server, and *CAName* is the common name of the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** An HTTPS URL is not supported as an input.

### `RequestId` [in]

A **LONG** value that represents the [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) ID in the Certificates Services database. Use –1 for this value if the serial number (passed in as *strSerialNumber*) is to be used instead of the request ID.

### `strSerialNumber` [in]

A **BSTR** value that represents the certificate serial number, as issued by the CA. For *strSerialNumber* to be used, you must specify a value of –1 for *RequestId*.

### `pDisposition` [out, retval]

A pointer to a **LONG** value that represents the certificate's disposition. The disposition is one of the following values.

| Value | Meaning |
| --- | --- |
| **CR_DISP_DENIED** | Request denied. |
| **CR_DISP_ERROR** | Request failed. |
| **CR_DISP_INCOMPLETE** | Request did not complete. |
| **CR_DISP_ISSUED** | Certificate issued. |
| **CR_DISP_ISSUED_OUT_OF_BAND** | Certificate issued separately. |
| **CR_DISP_UNDER_SUBMISSION** | Request taken under submission. |

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a **Long** that represents the certificate's disposition.