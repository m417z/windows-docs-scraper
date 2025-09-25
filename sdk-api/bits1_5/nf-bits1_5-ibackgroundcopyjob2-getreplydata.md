# IBackgroundCopyJob2::GetReplyData

## Description

Retrieves an in-memory copy of the reply data from the server application. Call this method only if the job's type is BG_JOB_TYPE_UPLOAD_REPLY and its state is BG_JOB_STATE_TRANSFERRED.

## Parameters

### `ppBuffer` [in, out]

Buffer to contain the reply data. The method sets *ppBuffer* to **NULL** if the server application did not return a reply. Call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *ppBuffer* when done.

### `pLength` [out]

Size, in bytes, of the reply data in *ppBuffer*.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully retrieved the reply data. |
| **BG_E_TOO_LARGE** | The reply data exceeds the maximum 1 MB buffer size. The *ppBuffer* parameter is set to **NULL**, and *pSize* contains the size of the reply data. |
| **BG_E_INVALID_STATE** | To retrieve the reply data, the state of the job must be **BG_JOB_STATE_TRANSFERRED**. |
| **E_NOTIMPL** | This method is not implemented for jobs of type **BG_JOB_TYPE_DOWNLOAD** or **BG_JOB_TYPE_UPLOAD**. |

## Remarks

The
**GetReplyData** method lets you read the reply data before or after you call the
[IBackgroundCopyJob::Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) method. However, to read the reply data from the reply file, you must first call the
**Complete** method; the file is not available to the client until you call the
**Complete** method.

The
**GetReplyData** method returns **BG_E_TOO_LARGE** if the reply data exceeds 1 MB (*pSize* contains the size of the reply data). To retrieve the reply if it exceeds 1 MB, call the
[IBackgroundCopyJob2::GetReplyFileName](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-getreplyfilename) method to retrieve the file name. Then, open the file and read the reply data directly.

#### Examples

For an example that uses the
**GetReplyData** method, see
[Retrieving the Reply From an Upload-Reply Job](https://learn.microsoft.com/windows/desktop/Bits/retrieving-the-reply-from-an-upload-reply-job).

## See also

[IBackgroundCopyJob2::GetReplyFileName](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-getreplyfilename)

[IBackgroundCopyJob2::SetReplyFileName](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setreplyfilename)