# ICertRequest::GetLastStatus

## Description

The **GetLastStatus** method gets the last return code for this request. This returns the error code information, rather than the disposition of the request.

## Parameters

### `pStatus` [out]

A pointer to the request's status code.

## Return value

### C++

If the method succeeds, the method returns S_OK.

Upon successful completion of this function, **pStatus* is set to the result code of the latest call to [ICertRequest3::Submit](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-submit), [ICertRequest3::RetrievePending](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-retrievepending), or [ICertRequest3::GetCACertificate](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-getcacertificate).

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the result code of the latest call to [CCertRequest3.Submit](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-submit), [CCertRequest3.RetrievePending](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-retrievepending) or [CCertRequest3.GetCACertificate](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-getcacertificate).

## Remarks

The value retrieved by **GetLastStatus** depends on the most recent call to
[ICertRequest3::Submit](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-submit),
[ICertRequest3::RetrievePending](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-retrievepending), or
[ICertRequest3::GetCACertificate](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-getcacertificate). If a call to one of these methods fails on the server, call **GetLastStatus** to retrieve the error number. Some server failures (such as denied requests) return S_OK and a disposition other than CR_DISP_ISSUED from the method call, and you can use **GetLastStatus** to retrieve the specific cause of failure. If a call to one of these methods succeeds, then a subsequent call to **GetLastStatus** returns S_OK (which is zero).

Additionally, the request disposition is stored in the Certificate Services database, and can be viewed by means of the Certification Authority MMC snap-in (choose the Request Disposition column).

#### Examples

```cpp
HRESULT    hrServer, hr;
// pCertRequest is previously instantiated
// ICertRequest object pointer.
hr = pCertRequest->GetLastStatus((LONG *) &hrServer);
if (FAILED(hr))
{
    printf("Failed GetLastStatus [%x]\n", hr);
    goto error;
}
else
{
    // Use the HRESULT value as needed...
}

```

## See also

[CCertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICertRequest2](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest2)

[ICertRequest3](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest3)