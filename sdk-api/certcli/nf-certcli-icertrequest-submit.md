# ICertRequest::Submit

## Description

The **Submit** method submits a request to the Certificate Services server.

If the resulting disposition status is CR_DISP_ISSUED, you can retrieve the issued certificate by calling
the [ICertRequest3::GetCertificate](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-getcertificate) method.

## Parameters

### `Flags` [in]

Specifies the request format, type of request, and whether the request is encrypted. One of the following format attribute flags can be used to specify how the request is encoded.

| Value | Meaning |
| --- | --- |
| **CR_IN_BASE64** | Unicode BASE64 format without begin/end. |
| **CR_IN_BASE64HEADER** | Unicode BASE64 format with begin/end. |
| **CR_IN_BINARY** | Binary format. |
| **CR_IN_ENCODEANY** | Try all of the CR_IN_BASE64HEADER, CR_IN_BASE64, or CR_IN_BINARY formats. |

One of the following format value flags can be used to specify the type of the request.

| Value | Meaning |
| --- | --- |
| **CR_IN_RETURNCHALLENGE** | Return a challenge that can be submitted to a CA. The challenge is a [Certificate Management over CMS](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CMC) full request. When this flag is turned on, calling the [GetFullResponseProperty](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest2-getfullresponseproperty) method with the FR_PROP_FULLRESPONSE flag returns a CMC response that contains key attestation challenge. |
| **CR_IN_CHALLENGERESPONSE** | The call is a response to a challenge. The RequestId must be passed in the *strAttributes* parameter and the response to the challenge must be passed in the *strRequest* parameter. This flag should be turned on when an application needs to send back the decrypted challenge to the CA. You can then call the [GetFullResponseProperty](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest2-getfullresponseproperty) method to get the issued end entity certificate. |
| **CR_IN_CMC** | A [Certificate Management over CMS](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CMC) request. |
| **CR_IN_FORMATANY** | Try all of the CR_IN_CMC, CR_IN_KEYGEN, CR_IN_PKCS7, or CR_IN_PKCS10 formats. |
| **CR_IN_KEYGEN** | Keygen request (Netscape format). |
| **CR_IN_PKCS7** | [PKCS #7](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) request (renewal or registration agent). |
| **CR_IN_PKCS10** | PKCS #10 request. |
| **CR_IN_RPC** | Transmit the messages using RPC instead of DCOM. |
| **CR_IN_FULLRESPONSE** | Return a full CMC response. |
| **CR_IN_CRLS** | Include the current certificate revocation lists. |
| **CR_IN_MACHINE** | Use the context of the key service computer. |
| **CR_IN_ROBO** | Indicates that the message is being requested on behalf of another sender.<br><br>If the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) is not configured for "renew on behalf of", then the CA rejects the request.<br><br>For more information about enabling "renew on behalf of" on the CA, see [Configuring the Certificate Enrollment Web Service for Renewal Only Mode](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/dd759245(v=ws.11)).<br><br>The request must be a renewal request and the signing certificate must be using the same template as the request.<br><br>In addition, the request will succeed only when one of the following conditions is true:<br><br>* The signing certificate must have been issued by the same CA<br>* The signing certificate's SAN2 extension has the UPN of the subject<br>* The signing certificate's Subject Name has the FQDN_1779 of the subject<br><br>**Windows Server 2008 and Windows Server 2003:** This flag is not supported. |
| **CR_IN_CLIENTIDNONE** | Do not include in the request data that identifies the client.<br><br>**Windows Server 2008 and Windows Server 2003:** This flag is not supported. |
| **CR_IN_CONNECTONLY** | Specifies that the DCOM connection with the server is established, but the request is not submitted. |

### `strRequest` [in]

A pointer to the string that contains the [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). If CR_IN_BASE64 or CR_IN_BASE64HEADER was specified in *Flags*, *strRequest* must be a Unicode string.

### `strAttributes` [in]

A pointer to the string that contains optional extra [attributes](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) for the request. Each attribute is a name-value string pair. The colon character separates the name and value, and a newline character separates multiple name-value pairs, for example:

|  |  |
| --- | --- |
| **C++** | "AttributeName1:AttributeValue1\nAttributeName2:AttributeValue2" |
| **VB** | "AttributeName1:AttributeValue1" & vbNewLine & "AttributeName2:AttributeValue2" |

When Certificate Services server parses attribute names, it ignores spaces, hyphens (minus signs), and case. For example, "AttributeName1", "Attribute Name1", and "Attribute-name1" are all equivalent. For attribute values, Certificate Services server ignores leading and trailing white space.

### `strConfig` [in]

Represents a valid configuration string for the Certificate Services server. The string can be either an HTTPS URL for an enrollment server or in the form *ComputerName***\\***CAName*, where *ComputerName* is the network name of the server, and *CAName* is the common name of the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** An HTTPS URL is not supported as an input.

### `pDisposition` [out, retval]

A pointer to the request's disposition value.

## Return value

### C++

If the method succeeds, the method returns S_OK.

 Upon successful completion of this function, **pDisposition* is set to one of the values in the following table.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value specifies the disposition of the request. The disposition is one of the following values.

| Return code | Description |
| --- | --- |
| **CR_DISP_DENIED** | Request denied |
| **CR_DISP_ERROR** | Request failed |
| **CR_DISP_INCOMPLETE** | Request did not complete |
| **CR_DISP_ISSUED** | Certificate issued |
| **CR_DISP_ISSUED_OUT_OF_BAND** | Certificate issued separately |
| **CR_DISP_UNDER_SUBMISSION** | Request taken under submission |

## Remarks

If you read a BASE64 format request from a file, ensure that the file is in Unicode, or convert it from ASCII to Unicode before submitting the request with this method.

#### Examples

```cpp
    //  The pointer to the interface object.
    ICertRequest * pCertRequest = NULL;

    //  The variable for the computer\CAName.
    BSTR         bstrCA = NULL;

    //  The variable for the request.
    BSTR         bstrRequest = NULL;

    //  The variable for the attributes.
    BSTR         bstrAttribs = NULL;

    //  The variable for the disposition code.
    long        nDisp;

    HRESULT     hr;

    //  Initialize COM.
    hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

    //  Check status.
    if (FAILED(hr))
    {
        printf("Failed CoInitializeEx [%x]\n", hr);
        goto error;
    }

    //  Instantiate the CertConfig object.
    hr = CoCreateInstance(CLSID_CCertRequest,
                          NULL,
                          CLSCTX_INPROC_SERVER,
                          IID_ICertRequest,
                          (void **)&pCertRequest);
    if (FAILED(hr))
    {
        printf("Failed CoCreateInstance pCertRequest [%x]\n", hr);
        goto error;
    }

    //  Specify the certification authority.
    //  Note: In C++, produce one backslash (\) by using two.
    bstrCA = SysAllocString(L"server01\\myCAName");

    //  Create the request (not shown), and assign it to bstrRequest,
    //  for example, use ICEnroll::createPKCS10.

    //  Generate the attributes. In this case, no attributes
    //  are specified.
    bstrAttribs = SysAllocString(L"");

    //  Submit the request.
    hr = pCertRequest->Submit(CR_IN_BASE64 | CR_IN_PKCS10,
                              bstrRequest,
                              bstrAttribs,
                              bstrCA,
                              &nDisp );
    if (FAILED(hr))
    {
        printf("Failed Submit [%x]\n", hr);
        goto error;
    }
    else
    {
        //  Use the disposition value as needed.
    }

    //  Done processing.

error:

    //  Free BSTR values.
    if (NULL != bstrCA)
        SysFreeString(bstrCA);

    if (NULL != bstrRequest)
        SysFreeString(bstrRequest);

    if (NULL != bstrAttribs)
        SysFreeString(bstrAttribs);

    //  Clean up object resources.
    if (NULL != pCertRequest)
        pCertRequest->Release();

    //  Free COM resources.
    CoUninitialize();

```

## See also

[CCertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICEnroll::createPKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createpkcs10)

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)

[ICertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICertRequest2](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest2)

[ICertRequest3](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest3)