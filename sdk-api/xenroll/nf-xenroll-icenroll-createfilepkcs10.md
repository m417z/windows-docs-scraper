# ICEnroll::createFilePKCS10

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **createFilePKCS10** method creates a base64-encoded PKCS #10 [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) and saves it in a file. This method was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This method differs from
the [createPKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createpkcs10) method only in saving the base64-encoded PKCS #10 [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (in **BSTR** form) to the file specified by the *wszPKCS10FileName* parameter.

## Parameters

### `DNName` [in]

The distinguished name (DN) of the entity for which the request is being made. *DNName* must follow the [X.500](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) naming convention. For example "CN=User, O=Microsoft". If a two-letter prefix does not exist, an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) may be provided instead.

### `Usage` [in]

An [OID](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) that describes the purpose of the certificate being generated, for example, individual or commercial Authenticode certificate, or client authentication. You can also specify multiple OIDs separated by a comma.

The OID is passed through to the PKCS #10 request. The control does not examine the OID.

### `wszPKCS10FileName` [in]

The name of the file in which the base64-encoded PKCS #10 (in **BSTR** form) is saved. The contents of this file may be submitted to a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) for processing.

## Return value

### VB

The return value is an **HRESULT**. A value of **S_OK** indicates success.

If the method fails, the return value is an **HRESULT** indicating the error. For a list of common error codes, see
[Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

By default, the Microsoft Base Cryptographic Provider is used, and a unique signature key is created.

When this method is called from script, the method displays a user interface that asks whether the user will allow creation of a certificate request and whether the user will allow a write operation to the file system.

#### Examples

```cpp
BSTR bstrDN = NULL;
BSTR bstrOID = NULL;
BSTR bstrFileName = NULL;
ICEnroll4 * pEnroll = NULL;
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
                       (void **)&pEnroll);
if (FAILED(hr))
{
    printf("Failed CoCreateInstance - pEnroll [%x]\n", hr);
    goto error;
}

// Generate the DN for the cert request.
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

// Generate the OID. For example, "1.3.6.1.4.1.311.2.1.21"
bstrOID = SysAllocString(TEXT("<OIDHERE>"));
if (NULL == bstrOID)
{
    printf("Memory allocation failed for bstrOID.\n");
    goto error;
}

// Specify the file name, for example, "myPKCS10.req"
bstrFileName = SysAllocString(TEXT("<FILENAMEHERE>"));
if (NULL == bstrFileName)
{
    printf("Memory allocation failed for bstrFileName.\n");
    goto error;
}

// Create the PKCS10 (stored in a file).
hr = pEnroll->createFilePKCS10( bstrDN, bstrOID, bstrFileName );
if (FAILED(hr))
{
   printf("Failed createFilePKCS10 - %x\n", hr);
   goto error;
}
else
    printf("Successfully created file containing PKCS10\n");

error:
// Clean up resources and so on.

if ( bstrFileName )
    SysFreeString( bstrFileName );

if ( bstrDN )
    SysFreeString( bstrDN );

if ( bstrOID )
    SysFreeString( bstrOID );

if ( pEnroll )
       pEnroll->Release();

CoUninitialize();

```