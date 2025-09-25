# IBackgroundCopyJobHttpOptions::GetCustomHeaders

## Description

Retrieves the custom headers set by an earlier call to [IBackgroundCopyJobHttpOptions::SetCustomHeaders](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setcustomheaders) (that is, headers which BITS will be sending to the remote, not headers which BITS receives from the remote).

## Parameters

### `pRequestHeaders` [out]

Null-terminated string that contains the custom headers. Each header is terminated by a carriage return and line feed (CR/LF) character. To free the string when finished, call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

The following table lists some of the possible return values.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully retrieved the headers. |
| ****S_FALSE**** | The job does not specify custom headers. |
| ****E_ACCESSDENIED**** | Either you don't have permission to retrieve the custom headers, or [IBackgroundCopyJobHttpOptions3::MakeCustomHeadersWriteOnly](https://learn.microsoft.com/windows/desktop/api/bits10_3/nf-bits10_3-ibackgroundcopyjobhttpoptions3-makecustomheaderswriteonly) has been called on the job. |
| ****RPC_X_NULL_REF_POINTER**** | The *pRequestHeaders* parameter is **NULL**. |

## Remarks

Only the job owner can retrieve the custom headers. To specify the headers, call the [IBackgroundCopyJobHttpOptions::SetCustomHeaders](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setcustomheaders) method.

## See also

[IBackgroundCopyJobHttpOptions](https://learn.microsoft.com/windows/desktop/api/bits2_5/nn-bits2_5-ibackgroundcopyjobhttpoptions)

[IBackgroundCopyJobHttpOptions::SetCustomHeaders](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setcustomheaders)