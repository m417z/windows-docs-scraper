# ICertRequest::RetrievePending

## Description

The **RetrievePending** method retrieves a certificate's disposition status from an earlier request that may have previously returned CR_DISP_INCOMPLETE or CR_DISP_UNDER_SUBMISSION.

If the resulting disposition status is CR_DISP_ISSUED, you can retrieve the issued certificate by calling
[ICertRequest3::GetCertificate](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-getcertificate). If a disposition other than CR_DISP_ISSUED is returned, call
[ICertRequest3::GetLastStatus](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-getlaststatus),
[ICertRequest3::GetDispositionMessage](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-getdispositionmessage), or both methods for more information.

## Parameters

### `RequestId` [in]

The ID of the request that had previously returned CR_DISP_INCOMPLETE or CR_DISP_UNDER_SUBMISSION.

### `strConfig` [in]

Represents a valid configuration string for the Certificate Services server. The string can be either an HTTPS URL for an enrollment server or in the form *ComputerName***\\***CAName*, where *ComputerName* is the network name of the server, and *CAName* is the common name of the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** An HTTPS URL is not supported as an input.

### `pDisposition` [out, retval]

A pointer to the request's disposition value.

## Return value

### C++

If the method succeeds, the method returns S_OK.

Upon successful completion of this function, **pDisposition* is set to one of the values in the following table.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value specifies the disposition of the request. The disposition is one of the following values.

| Return code | Description |
| --- | --- |
| **CR_DISP_INCOMPLETE** | Request did not complete |
| **CR_DISP_ERROR** | Request failed |
| **CR_DISP_DENIED** | Request denied |
| **CR_DISP_ISSUED** | Certificate issued |
| **CR_DISP_ISSUED_OUT_OF_BAND** | Certificate issued separately |
| **CR_DISP_UNDER_SUBMISSION** | Request taken under submission |

## Remarks

A successful call to this method generates an EXITEVENT_CERTRETRIEVEPENDING event. An active exit module will receive notification of this event (by means of a call to
[ICertExit3::Notify](https://learn.microsoft.com/windows/desktop/api/certexit/nf-certexit-icertexit-notify)) if the exit module specified this event when calling
[ICertExit3::Initialize](https://learn.microsoft.com/windows/desktop/api/certexit/nf-certexit-icertexit-initialize).

#### Examples

```cpp
BSTR    bstrCA = NULL;
long    nReqID, nDisp;

// In this example, the request ID is hard-coded.
nReqID = 1234;

// Note use of two '\' in C++ to produce one '\'.
bstrCA = SysAllocString(L"server01\\myCAName");

// pCertRequest is previously instantiated ICertRequest
// object pointer. Retrieve the status for the specified request.
hr = pCertRequest->RetrievePending( nReqID, bstrCA, &nDisp );
if (FAILED(hr))
{
    printf("Failed RetrievePending [%x]\n", hr);
    goto error;
}
else
{
    // Use the disposition value as needed...
}
// Free BSTR resource.
if ( NULL != bstrCA )
    SysFreeString( bstrCA );
```

## See also

[CCertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)

[ICertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICertRequest2](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest2)

[ICertRequest3](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest3)