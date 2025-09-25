# ICertView::OpenConnection

## Description

The **OpenConnection** method establishes a connection with a Certificate Services server.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the Certificate Services server. The configuration string is in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the server's network name, and CANAME is the common name of the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Upon successful completion of this method, the
[ICertView](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-icertview) object will have a connection to the Certificate Services server specified in the *strConfig* parameter.

 To close the connection, call the **Release** function.

#### Examples

```cpp
ICertView *   pCertView = NULL;
BSTR          strCertServ = NULL;
HRESULT       hr;

// Initialize COM.
hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

if (FAILED(hr))
{
    printf("Failed CoInitializeEx\n");
    goto error;
}
// Get pointer to the ICertView interface.
hr = CoCreateInstance(CLSID_CCertView,
                      NULL,
                      CLSCTX_INPROC_SERVER,
                      IID_ICertView,
                      (void **)&pCertView);
if (FAILED(hr))
{
    printf("Failed CoCreateInstance\n");
    goto error;
}
// The use of '\\' is necessary to represent a single backslash.
strCertServ = SysAllocString(TEXT("Server01\\ABCCertServ"));
// Open the connection to the Certificate Services server.
hr = pCertView->OpenConnection(strCertServ);
if (FAILED(hr))
{
    printf("Failed OpenConnection!\n");
    goto error;
}
else
    // Established successful connection; use view as appropriate.
    // ...
    // Done using objects; free resources.
error:
    if (NULL != pCertView)
        pCertView->Release();
    if (NULL != strCertServ)
        SysFreeString(strCertServ);
    // Free COM resources.
    CoUninitialize();
```

## See also

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)

[ICertView](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-icertview)

[ICertView2](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-icertview2)

[ICertView::OpenView](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-openview)