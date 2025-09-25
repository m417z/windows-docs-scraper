# ICertRequest::GetCertificate

## Description

The **GetCertificate** method returns the certificate issued for the request as an [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) certificate, or optionally packaged in a [Public Key Cryptography Standards](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) (PKCS) #7 message that contains the complete certificate chain for the [Certificate Services](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) server.

## Parameters

### `Flags` [in]

A flag for the format and whether the complete certificate chain is included.

The format of the returned certificate
can be one of the following flags.

| Value | Meaning |
| --- | --- |
| **CR_OUT_BASE64HEADER** | BASE64 format with begin/end |
| **CR_OUT_BASE64** | BASE64 format without begin/end |
| **CR_OUT_BINARY** | Binary format |

The following flags can be combined with the format flag.

| Value | Meaning |
| --- | --- |
| **CR_OUT_CHAIN** | Include complete certificate chain in the PKCS #7.<br><br> If this flag is not specified, only the requested certificate, in [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) format, is returned. |
| **CR_OUT_CRLS** | Include [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRLs) in the PKCS #7. |

For example, to retrieve a binary certificate with complete certificate chain in C++ you would write the following.

``` syntax
hResult = pCertReq->GetCACertificate(FALSE, bstrConfig,
     CR_OUT_BINARY | CR_OUT_CHAIN, &bstrCert);
```

### `pstrCertificate` [out]

A pointer to the **BSTR** that contains the certificate, in the specified format.

When using this method, create a variable of **BSTR** type, set the variable equal to **NULL**, and then pass the address of this variable as *pstrCertificate*. When you have finished using the certificate pointed to by *pstrCertificate*, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

If the method sets **pstrCertificate* to the **BSTR** that contains the certificate for the request, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

An application would call this method to retrieve the certificate issued by means of an earlier call to
[ICertRequest3::Submit](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-submit) or
[ICertRequest3::RetrievePending](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-retrievepending).

#### Examples

The following example shows retrieving a certificate.

```cpp
#include <windows.h>
#include <stdio.h>
#include <Certcli.h>

HRESULT main()
{
    //  Pointer to interface object.
    ICertRequest * pCertRequest = NULL;

    //  Variable for COMPUTER\CANAME.
    BSTR         bstrCA = NULL;

    //  Variable for CA Certificate.
    BSTR         bstrCACert = NULL;

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

    //  Note use of two backslashes (\\) in C++
    //  to produce one backslash (\).
    bstrCA = SysAllocString(L"server01\\myCAName");

    //  Retrieve the CA certificate.
    hr = pCertRequest->GetCACertificate(FALSE,
                                        bstrCA,
                                        CR_OUT_BASE64,
                                        &bstrCACert);
    if (FAILED(hr))
    {
        printf("Failed GetCACertificate [%x]\n", hr);
        goto error;
    }
    else
    {
        //  Use CA Certificate as needed.
    }

    //  Done processing.

error:

    //  Free BSTR values.
    if (NULL != bstrCA)
        SysFreeString(bstrCA);

    if (NULL != bstrCACert)
        SysFreeString(bstrCACert);

    //  Clean up object resources.
    if (NULL != pCertRequest)
        pCertRequest->Release();

    //  Free COM resources.
    CoUninitialize();

    return hr;

}

```

## See also

[CCertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICertRequest2](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest2)

[ICertRequest3](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest3)