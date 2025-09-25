# IBackgroundCopyJobHttpOptions::SetCustomHeaders

## Description

Specifies one or more custom HTTP headers to include in HTTP requests.

## Parameters

### `RequestHeaders` [in]

Null-terminated string that contains the custom headers to append to the HTTP request. Each header must be terminated by a carriage return and line feed (CR/LF) character. The string is limited to 16,384 characters, including the null terminator.

To remove the custom headers from the job, set the *RequestHeaders* parameter to **NULL**.

## Return value

The following table lists some of the possible return values.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Success. |
| **BG_E_STRING_TOO_LONG** | The length of the custom headers is more than 16 KB. |
| **BG_E_INVALID_STATE** | The state of the job cannot be BG_JOB_STATE_CANCELLED or BG_JOB_STATE_ACKNOWLEDGED. |

## Remarks

The custom headers are applicable only to remote files that use the HTTP or HTTPS protocol. You can specify custom headers for all job types.

Only the job owner can specify custom headers. If the job changes ownership, BITS removes the headers from the job.

Note that if multiple HTTP requests are sent, the headers are sent with each request.

An ISAPI that processes the custom header can return an HTTP error if the header is not valid. For details on how BITS handles the error, see [Handling Server Application Errors](https://learn.microsoft.com/windows/desktop/Bits/handling-server-application-errors).

#### Examples

The following example shows how to specify custom headers for a job. The example assumes that pJob points to a valid job.

```cpp
// Custom headers to include in job.
#define HEADERS L"MyHeader_1: Header One Value\r\n" \
    L"MyHeader_2: Header Two Value\r\n" \
    L"MyHeader_3: Header Three Value\r\n"

  HRESULT hr = S_OK;
  IBackgroundCopyJob* pJob = NULL;
  IBackgroundCopyJobHttpOptions* pHttpOptions = NULL;

  hr = pJob->QueryInterface(__uuidof(IBackgroundCopyJobHttpOptions), (void**)&pHttpOptions);
  pJob->Release();
  if (FAILED(hr))
  {
    wprintf(L"pJob->QueryInterface failed with 0x%x.\n", hr);
    goto cleanup;
  }

  hr = pHttpOptions->SetCustomHeaders(HEADERS);
  if (FAILED(hr))
  {
    wprintf(L"pHttpOptions->SetCustomHeaders failed with 0x%x.\n", hr);
    goto cleanup;
  }

cleanup:

  if (pHttpOptions)
  {
    hr = pHttpOptions->Release();
  }

```

## See also

[IBackgroundCopyJobHttpOptions](https://learn.microsoft.com/windows/desktop/api/bits2_5/nn-bits2_5-ibackgroundcopyjobhttpoptions)

[IBackgroundCopyJobHttpOptions::GetCustomHeaders](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-getcustomheaders)