# ICertRequest::GetDispositionMessage

## Description

The **GetDispositionMessage** method gets a human-readable message that gives the current disposition of the [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

Note that the message returned here may have more detail than the returned error code. For example,
[ICertRequest3::GetLastStatus](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-getlaststatus) may return an **HRESULT**, while **GetDispositionMessage** will return a detailed reason that specifies why the request was denied.

## Parameters

### `pstrDispositionMessage` [out]

A pointer to the **BSTR** that contains the disposition message.

## Return value

### C++

If the method succeeds, the method returns S_OK.

Upon successful completion of this function, **pstrDispositionMessage* is set to the **BSTR** that contains a human-readable message that gives the current disposition of the [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). To use this method, create a variable of **BSTR** type, set the variable equal to **NULL**, and pass the address of this variable as *pstrDispositionMessage*. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a string that contains a human-readable message that gives the current disposition of the [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Remarks

An application would call this method to obtain the message retrieved from the server by means of an earlier call to
[ICertRequest3::Submit](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-submit) or
[ICertRequest3::RetrievePending](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-retrievepending). Additionally, the message is stored in the Certificate Services database and may be viewed by the Certification Authority MMC snap-in (choose the Request Disposition Message column). If the message contains localized text, it was localized on the server (based on the server's locale).

#### Examples

```cpp
#include <windows.h>
#include <stdio.h>
#include <Certcli.h>

    BSTR    bstrDispMsg = NULL;
    // pCertRequest is previously instantiated ICertRequest object
    // pointer. Retrieve the disposition message for the
    // previous request.
    hr = pCertRequest->GetDispositionMessage(&bstrDispMsg);
    if (FAILED(hr))
    {
        printf("Failed GetDispositionMessage [%x]\n", hr);
        goto error;
    }
    else
    {
        // Use the disposition message as needed...
    }

    // Done processing.

error:

    // Free BSTR values.
    if (NULL != bstrCA)
        SysFreeString(bstrCA);

    if (NULL != bstrDispMsg)
        SysFreeString(bstrDispMsg);

```

## See also

[CCertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICertRequest2](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest2)

[ICertRequest3](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest3)