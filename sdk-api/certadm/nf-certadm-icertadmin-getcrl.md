# ICertAdmin::GetCRL

## Description

The **GetCRL** method retrieves the current [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) for the Certificate Services [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA). This method was first defined in the [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin) interface.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the CA whose CRL you want to retrieve. This string is in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the network name of the Certificate Services server and CANAME is the common name of the CA, as entered during Certificate Services setup. For information about the configuration string name, see [ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Important** **GetCRL** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `Flags` [in]

Specifies the format of the returned CRL. This parameter can be one of the following flags.

| Value | Meaning |
| --- | --- |
| **CR_OUT_BASE64HEADER** | BASE64 format with begin/end. |
| **CR_OUT_BASE64** | BASE64 format without begin/end. |
| **CR_OUT_BINARY** | Binary format. |

### `pstrCRL` [out]

A pointer to a **BSTR** that receives the CRL.

When using this method, create a variable of **BSTR** type, set the variable to **NULL**, and pass the address of this variable in the *pbstrCRL* parameter. When you have finished using the **BSTR** variable, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an HRESULT value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *strConfig* parameter cannot be **NULL** or no CRL has been found. |

## Remarks

Administration tasks use DCOM. Code that calls this interface method as defined in an earlier version of Certadm.h will run on Windows-based servers as long as the client and the server are both running the same Windows operating system.

#### Examples

The following example declares the necessary variables, initializes COM, and creates an instance of the **CertAdmin** class. It then calls **GetCRL** and prints success or failure to the screen. Finally, it frees resources.

```cpp
    ICertAdmin * pCertAdmin = NULL;  // pointer to interface object
    BSTR bstrCA = NULL;              // variable for machine\CAName
    BSTR bstrCRL = NULL;             // variable to contain
                                     // the retrieved CRL

    HRESULT hr;

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

    //  Note the use of two backslashes (\\)
   //  in C++ to produce one backslash (\).
    bstrCA = SysAllocString(L"<COMPUTERNAMEHERE>\\<CANAMEHERE>");
    if (FAILED(hr))
    {
        printf("Failed to allocate memory for bstrCA\n");
        goto error;
    }

    //  Retrieve the CRL.
    hr = pCertAdmin->GetCRL( bstrCA, CR_OUT_BINARY, &bstrCRL );
    if (FAILED(hr))
    {
        printf("Failed GetCRL [%x]\n", hr);
        goto error;
    }
    else
        printf("CRL retrieved successfully\n");
        //  Use the CRL as needed.

    //  Done processing.

error:

    //  Free BSTR values.
    if (NULL != bstrCA)
        SysFreeString(bstrCA);

    if (NULL != bstrCRL)
        SysFreeString(bstrCRL);

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