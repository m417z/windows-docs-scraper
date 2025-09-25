# ICEnroll::createPKCS10

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **createPKCS10** method creates a base64-encoded PKCS #10 [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This method was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

 This base64-encoded PKCS #10 certificate request (in **BSTR** form) can be submitted to a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to request that a certificate be issued to the person or entity whose information it contains.

## Parameters

### `DNName` [in]

The distinguished name (DN) of the entity for which the request is being made. In this parameter, the DN name must follow the [X.500](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) naming convention. For example "CN=User, O=Microsoft". If a two-letter prefix does not exist, an [OID](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) may be provided instead.

### `Usage` [in]

An [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) that describes the purpose of the certificate being generated. For example, Individual or Commercial Authenticode certificate, or Client Authentication. You can also specify multiple OIDs separated by a comma.

The OID is passed through to the PKCS #10 request. For general extensibility and ease of understanding, the control does not attempt to understand specific-purpose OIDs. Therefore if you specify a Client Authentication OID, the generated key will still be a signature key, not an [exchange key](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly).

### `pPKCS10` [in]

The returned base64-encoded PKCS10 certificate request.

## Return value

### C++

The return value is an **HRESULT**. A value of **S_OK** indicates success. Upon successful completion of this function, *pPKCS10* will contain a base64-encoded PKCS #10 request (in **BSTR** form). The format is such that it can be directly posted to a web server for processing.

### VB

The returned base64-encoded PKCS10 certificate request.

## Remarks

By default, the Microsoft Base Cryptographic Provider is used, PROV_RSA_FULL is the provider type, a signature key is created, and a unique new key set is created.

When this method is called from script, the method displays a user interface that asks whether the user will allow creation of a certificate request.

#### Examples

```cpp
BSTR bstrDN = NULL;
BSTR bstrReq = NULL;
BSTR bstrOID = NULL;
ICEnroll4 * pEnroll = NULL;
HRESULT hr;

// initialize COM
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
                       (void **)&pEnroll);
if (FAILED(hr))
{
    printf("Failed CoCreateInstance - pEnroll [%x]\n", hr);
    goto error;
}
// generate the DN for the cert request
bstrDN = SysAllocString( TEXT("CN=Your Name")   // common name
                         TEXT(",OU=Your Unit")  // org unit
                         TEXT(",O=Your Org")    // organization
                         TEXT(",L=Your City")   // locality
                         TEXT(",S=Your State")  // state
                         TEXT(",C=Your Country") );  // country/region
if (NULL == bstrDN)
{
    printf("Memory allocation failed for bstrDN.\n");
    goto error;
}

// generate the OID, for example, "1.3.6.1.4.1.311.2.1.21".
bstrOID = SysAllocString(TEXT("<OIDHERE>"));
if (NULL == bstrOID)
{
    printf("Memory allocation failed for bstrOID.\n");
    goto error;
}

// create the PKCS10
hr = pEnroll->createPKCS10( bstrDN, bstrOID, &bstrReq );
if (FAILED(hr))
{
    printf("Failed createPKCS10 - %x\n", hr);
    goto error;
}
else
    // do something with the PKCS10 (bstrReq);

error:

//clean up resources, and so on
if ( bstrDN )
    SysFreeString( bstrDN );
if ( bstrOID )
    SysFreeString( bstrOID );
if ( bstrReq )
    SysFreeString( bstrReq );
if ( pEnroll )
    pEnroll->Release();

CoUninitialize();

```