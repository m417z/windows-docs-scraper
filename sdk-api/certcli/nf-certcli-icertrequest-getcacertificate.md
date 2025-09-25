# ICertRequest::GetCACertificate

## Description

The **GetCACertificate** method returns the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) certificate for the Certificate Services server.

## Parameters

### `fExchangeCertificate` [in]

A Boolean value that specifies which CA certificate to return. If *fExchangeCertificate* is set to **false**, the [signature certificate](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the CA will be returned. The Signature certificate of the CA can be used to verify signatures on certificates issued by the CA.

**Windows Server 2003:** If *fExchangeCertificate* is set to **true**, the Exchange certificate of the CA will be returned. The Exchange certificate of the CA can be used to encrypt requests sent to the CA.

Beginning with Windows 7 and Windows Server 2008 R2, this parameter is ignored during https:// enrollment and the function, if successful, always returns the CA exchange certificate. To retrieve the CA signing certificate for an enrollment web service, use the [Property](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificatetemplate-get_property) method on the [ICertificationAuthority](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertificationauthority) interface with the CAPropCertificate [EnrollmentCAProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-enrollmentcaproperty) enumeration value.

Note that **TRUE** is defined (in a Microsoft header file) for C/C++ programmers as one, while Visual Basic defines the **True** keyword as negative one. As a result, Visual Basic developers must use one (instead of **True**) to set this parameter to **TRUE**. However, to set this parameter to **FALSE**, Visual Basic developers can use zero or **False**.

### `strConfig` [in]

Represents a valid configuration string for the Certificate Services server. The string can be either an HTTPS URL for an enrollment server or in the form *ComputerName***\\***CAName*, where *ComputerName* is the network name of the server, and *CAName* is the common name of the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** An HTTPS URL is not supported as an input.

### `Flags` [in]

The following flags can be used to specify the format of the returned certificate.

| Value | Meaning |
| --- | --- |
| **CR_OUT_BASE64HEADER** | BASE64 format with begin/end. |
| **CR_OUT_BASE64** | BASE64 format without begin/end. |
| **CR_OUT_BINARY** | Binary format. |

The following flag can be combined with the format flag to specify that the complete certificate chain should be included with the requested CA certificate. Otherwise, just the requested CA certificate (in [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) format) is returned.

| Value | Meaning |
| --- | --- |
| **CR_OUT_CHAIN** | Include complete certificate chain in a PKCS #7. |

### `pstrCertificate` [out, retval]

A pointer to the **BSTR** that contains the CA certificate for the Certificate Services server, in the specified format.

## Return value

### C++

If the method succeeds, the method returns S_OK.

Upon successful completion of this method, **pstrCertificate* is set to the **BSTR** that contains the CA certificate. To use this method, create a variable of **BSTR** type, set the variable equal to **NULL**, and pass the address of this variable as *pstrCertificate*.

 When you have finished using **pstrCertificate*, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The CA certificate for the Certificate Services server, in the specified format.

## Remarks

Administration tasks use DCOM. Code that calls this interface method as defined in an earlier version of Certadm.h will run on Windows-based servers as long as the client and the server are both running the same Windows operating system.

## See also

[CCertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICertRequest2](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest2)

[ICertRequest3](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest3)