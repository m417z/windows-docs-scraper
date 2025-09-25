# ICertAdmin::ResubmitRequest

## Description

The **ResubmitRequest** method submits the specified [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to the
[policy module](https://learn.microsoft.com/windows/desktop/SecCrypto/policy-modules) for the specified [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This method was first introduced in the [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin) interface.

For this method to succeed, the certificate request must be pending.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the network name of the Certificate Services server and CANAME is the common name of the certification authority, as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Important** **ResubmitRequest** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `RequestId` [in]

Specifies the ID of the request to resubmit.

### `pDisposition` [out, retval]

A pointer to the disposition of the request.

## Return value

### C++

If the method succeeds and the *pDisposition* parameter is set to one of the following values that specify the disposition of the request, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value specifies the disposition of the request. This value is one of the following values.

| Return code | Description |
| --- | --- |
| **CR_DISP_INCOMPLETE** | The request was not completed. |
| **CR_DISP_ERROR** | The request failed. |
| **CR_DISP_DENIED** | The request was denied. |
| **CR_DISP_ISSUED** | The certificate was issued. |
| **CR_DISP_ISSUED_OUT_OF_BAND** | The certificate was issued separately. |
| **CR_DISP_UNDER_SUBMISSION** | The request was taken under submission. |

## Remarks

Administration tasks use DCOM. Code that calls this interface method as defined in an earlier version of Certadm.h will run on Windows-based servers as long as the client and the server are both running the same Windows operating system.

#### Examples

```cpp
#include <windows.h>
#include <stdio.h>
#include <Certadm.h>

    long nDisp;  // disposition value
    long nReqID = <REQUESTIDHERE>;
    BSTR bstrCA = NULL;

    bstrCA = SysAllocString(L"<COMPUTERNAMEHERE>\\<CANAMEHERE>");
    if (NULL == bstrCA)
    {
        printf("Memory allocation failed\n");
        goto error;
    }

    //  pCertAdmin is a previously instantiated ICertAdmin object.
    hr = pCertAdmin->ResubmitRequest(bstrCA, nReqID, &nDisp);
    if (FAILED(hr))
    {
        printf("Failed ResubmitRequest [%x]\n", hr);
        goto error;
    }
    else
        printf("ResubmitRequest disposition is %d\n", nDisp);

error:
    //  Free resources.
    if (bstrCA)
        SysFreeString(bstrCA);

```

## See also

[CCertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)

[ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin)

[ICertAdmin2](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)

[ICertRequest::Submit](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-submit)