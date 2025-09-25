# IBackgroundCopyJob2::GetReplyFileName

## Description

Retrieves the name of the file that contains the reply data from the server application. Call this method only if the job type is BG_JOB_TYPE_UPLOAD_REPLY.

## Parameters

### `pReplyFileName` [out]

Null-terminated string that contains the full path to the reply file. Call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *pReplyFileName* when done.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully retrieved the name of the file that contains the reply data. |
| **E_NOTIMPL** | This method is not implemented for jobs of type **BG_JOB_TYPE_DOWNLOAD** or **BG_JOB_TYPE_UPLOAD**. |

## Remarks

To specify a reply file name, call the
[IBackgroundCopyJob2::SetReplyFileName](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setreplyfilename) method. If you did not specify a name, the
**GetReplyFileName** method returns the name that BITS generated for you. If you did not specify a name and you called this method before adding a file to the job, *pReplyFileName* is set to **NULL**.

You must call the
[IBackgroundCopyJob::Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) method before opening and reading the reply file; the reply file is not available to the client until you call the
**Complete** method.

The file is empty if the server application did not provide a reply.

#### Examples

For an example that uses the
**GetReplyFileName** method, see
[Retrieving the Reply From an Upload-Reply Job](https://learn.microsoft.com/windows/desktop/Bits/retrieving-the-reply-from-an-upload-reply-job).

## See also

[IBackgroundCopyJob2::GetReplyData](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-getreplydata)

[IBackgroundCopyJob2::SetReplyFileName](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setreplyfilename)