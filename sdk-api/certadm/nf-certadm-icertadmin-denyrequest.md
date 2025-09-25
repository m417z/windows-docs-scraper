# ICertAdmin::DenyRequest

## Description

The **DenyRequest** method denies a specified [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that is pending. This method was first defined in the [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin) interface.

For this method to succeed, the certificate request must be pending.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) in the form COMPUTERNAME\CANAME where COMPUTERNAME is the network name of the Certificate Services server and CANAME is the common name of the certification authority as entered during Certificate Services setup. For information about the configuration string, see [ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Important** **DenyRequest** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `RequestId` [in]

Specifies the ID of the pending request to be denied.

## Remarks

Administration tasks use DCOM. Code that calls this interface method as defined in an earlier version of Certadm.h will run on Windows-based servers as long as the client and the server are both running the same Windows operating system.

#### Examples

The following example declares the necessary variables, initializes COM, and creates an instance of the CertAdmin class. It then calls DenyRequest and prints success or failure to the screen. Finally, it frees resources.

```cpp
//  Pointer to an interface object.
ICertAdmin * pCertAdmin = NULL;

    BSTR       bstrCA = NULL;  // variable for machine\CAName
    long       nReqID;         // variable for Request ID
    HRESULT    hr;

    //  Initialize COM.
    hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if (FAILED(hr))
    {
        printf("Failed CoInitializeEx [%x]\n", hr);
        goto error;
    }

    //  Create the CertAdmin object
    //  and get a pointer to its ICertAdmin interface.
    hr = CoCreateInstance( CLSID_CCertAdmin,
                           NULL,
                           CLSCTX_INPROC_SERVER,
                           IID_ICertAdmin,
                           (void **)&pCertAdmin);
    if (FAILED(hr))
    {
        printf("Failed CoCreateInstance pCertAdmin [%x]\n", hr);
        goto error;
    }

    //  Note the use of two '\' in C++ to produce one '\'.
    bstrCA = SysAllocString(L"<COMPUTERNAMEHERE>\\<CANAMEHERE>");
    if (NULL == bstrCA)
    {
        printf("Failed to allocate memory for bstrCA\n");
        goto error;
    }

    //  nReqID is RequestID to be denied.
    nReqID = <REQUESTIDHERE>;

    //  Deny the request.
    hr = pCertAdmin->DenyRequest( bstrCA, nReqID );
    if (FAILED(hr))
    {
        printf("Failed DenyRequest %ws %d [%x]\n",
               bstrCA, nReqID, hr);
        goto error;
    }
    else
        printf("Denied request %ws %d\n",
                bstrCA, nReqID );

    //  Done processing.

error:

    //  Free BSTR values.
    if (NULL != bstrCA)
        SysFreeString(bstrCA);

    //  Clean up object resources.
    if (NULL != pCertAdmin)
        pCertAdmin->Release();

    //  Free COM resources.
    CoUninitialize();
```

## See also

[CCertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)

[ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin)

**ICertAdmin2**

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)