# ICEnroll4::createRequest

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **createRequest** method creates a PKCS #10, [PKCS #7](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly), or full [Certificate Management over CMS](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CMC) format [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) and stores it in a string. This method was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

## Parameters

### `Flags` [in]

A value that specifies the type of certificate request to create. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **XECR_CMC** | Full CMC |
| **XECR_PKCS10_V1_5** | PKCS 10 |
| **XECR_PKCS10_V2_0** | PKCS 10 version 2 |
| **XECR_PKCS7** | PKCS 7 |

### `strDNName` [in]

This parameter can be **NULL**; otherwise, this parameter specifies the distinguished name (DN) of the entity for which the request is being made. The DN name must follow the [X.500](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) naming convention, for example "CN=User, O=Microsoft". If a two-letter prefix does not exist, an OID may be provided instead.

### `Usage` [in]

An [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) that describes the purpose of the certificate being generated, for example, individual or commercial Authenticode certificate, or client authentication. You can also specify multiple OIDs separated by a comma.

### `pstrRequest` [out]

A pointer to a **BSTR** (BASE64_HEADER format) that receives the request. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see
[Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a **String** (BASE64_HEADER format) that contains the request.

## Remarks

When this method is called from script, the method displays a user interface that asks whether the user will allow creation of a certificate request. If a .pvk or .spc file was specified, the method displays a user interface that asks whether the user will allow a write operation to the file system.

#### Examples

```cpp
BSTR bstrDN = NULL;
BSTR bstrReq = NULL;
ICEnroll4 * pEnroll4 = NULL;
HRESULT hr;

hr = CoInitializeEx( NULL, COINIT_APARTMENTTHREADED );
if (FAILED(hr))
{
    printf("Failed CoInitializeEx - %x\n", hr);
    goto error;
}

hr = CoCreateInstance( __uuidof(CEnroll),
                       NULL,
                       CLSCTX_INPROC_SERVER,
                       __uuidof(ICEnroll4),
                       (void **)&pEnroll4);
if (FAILED(hr))
{
    printf("Failed CoCreateInstance - pEnroll4 [%x]\n", hr);
    goto error;
}

// generate the DN for the cert request
bstrDN = SysAllocString( TEXT("CN=Your Name")   // common name
                         TEXT(",OU=Your Unit")  // org unit
                         TEXT(",O=Your Org")    // organization
                         TEXT(",L=Your City")   // locality
                         TEXT(",S=Your State")  // state
                         TEXT(",C=Your Country") );  // country/region

// create the CMC request
hr = pEnroll4->createRequest( XECR_CMC,
                              bstrDN,
                              NULL,
                              &bstrReq );
if (FAILED(hr))
{
        printf("Failed createRequest - pEnroll4 [%x]\n", hr);
        goto error;
}
else
    // do something with the CMC (bstrReq);

error:

//clean up resources, and so on
if ( bstrDN )
    SysFreeString( bstrDN );
if ( bstrReq )
    SysFreeString( bstrReq );
if ( pEnroll4 )
    pEnroll4->Release();

CoUninitialize();

```