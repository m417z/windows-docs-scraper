# IBackgroundCopyJob3::AddFileWithRanges

## Description

Adds a file to a download job and specifies the ranges of the file you want to download.

## Parameters

### `RemoteUrl` [in]

Null-terminated string that contains the name of the file on the server. For information on specifying the remote name, see the **RemoteName** member and Remarks section of the [BG_FILE_INFO](https://learn.microsoft.com/windows/desktop/api/bits/ns-bits-bg_file_info) structure.

Starting with BITS 3.0, the SMB protocol is not supported for ranges.

**BITS 2.5 and 2.0:** BITS supports the SMB protocol for ranges.

### `LocalName` [in]

Null-terminated string that contains the name of the file on the client. For information on specifying the local name, see the **LocalName** member and Remarks section of the [BG_FILE_INFO](https://learn.microsoft.com/windows/desktop/api/bits/ns-bits-bg_file_info) structure.

### `RangeCount` [in]

Number of elements in *Ranges*.

### `Ranges` [in]

Array of one or more [BG_FILE_RANGE](https://learn.microsoft.com/windows/desktop/api/bits2_0/ns-bits2_0-bg_file_range) structures that specify the ranges to download. Do not specify duplicate or overlapping ranges.

## Return value

This method returns the following return values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Success |
| **E_INVALIDARG** | You can receive this error for one of the following reasons:<br><br>* The *RangeCount* parameter is zero; you must specify one or more ranges.<br>* The local or remote file name is not valid.<br>* The remote file name uses an unsupported protocol.<br>* The local file name was specified using a relative path. |
| **E_NOTIMPL** | You cannot call this method for upload or upload-reply jobs; only call this method for download jobs. |
| **E_ACCESSDENIED** | User does not have permission to write to the specified directory on the client. |
| **BG_E_INVALID_RANGE** | One of the ranges is invalid. For example, InitialOffset is set to **BG_LENGTH_TO_EOF**. |
| **BG_E_OVERLAPPING_RANGES** | You cannot specify duplicate or overlapping ranges. <br><br>**Note** The ranges are sorted by the offset of the value, not the length. If ranges are entered that have the same offset, but are in reverse order, then this error will be returned. For example, if 100.5 and 100.0 are entered in that order, then you will not be able to add the file to the job. |
| **BG_E_TOO_MANY_RANGES_IN_FILE** | The MaxRangesPerFile Group Policy setting determines how many ranges you can specify for a file. Adding these ranges exceeds the MaxRangesPerFile limit. |
| **BG_E_INVALID_STATE** | The state of the job cannot be **BG_JOB_STATE_CANCELLED** or **BG_JOB_STATE_ACKNOWLEDGED**. |

## Remarks

The ranges are written to the *LocalName* file in the order given. For example, if *Ranges* identifies bytes 100-199, 900-999, and 400-499 of the remote file, the local file will be 300 bytes long. Bytes 0-99 of the local file will contain bytes 100-199 of the remote file, bytes 100-199 of the local file will contain bytes 900-999 of the remote file, and bytes 200-299 of the local file will contain bytes 400-499 of the remote file.

The following table identifies possible error codes that can occur after you resume the job. These errors place the job in the BG_JOB_STATE_ERROR state.

| Error code | Description |
| --- | --- |
| BG_E_INVALID_SERVER_RESPONSE | BITS does not support servers that consolidate duplicate or overlapping ranges. |
| BG_E_INVALID_RANGE | One of the ranges is outside the boundaries of the remote file. |
| BG_E_INSUFFICIENT_RANGE_SUPPORT | The server does not support ranges. |

BITS guarantees that the version of a file (based on file size and date, not content) that it transfers will be consistent; however, it does not guarantee that a set of files will be consistent. For example, if BITS is in the middle of downloading the second of two files in the job at the time that the files are updated on the server, BITS restarts the download of the second file; however, the first file is not downloaded again.

By default, a user can add up to 500 ranges for a file. This limit does not apply to administrators or service accounts. To change the default, set the **MaxRangesPerFile** group policy.

**Prior to Windows Vista:** There is no limit on the number of files that a user can add to a job.

For better performance on Windows BranchCache-enabled file transfers, it is recommended that you set the range length to at least 400 bytes.

#### Examples

The following example shows how to call the **AddFileWithRanges** method to specify the ranges of a file to download. The example assumes the [IBackgroundCopyJob](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob) variable, *pJob*, is valid.

```cpp
    IBackgroundCopyJob *pJob;
    IBackgroundCopyJob3 *pJob3 = NULL;
    DWORD dwRangeCount = 3;                  //Number of elements in Ranges.
    BG_FILE_RANGE Ranges[] = {24, 17,        //Array of ranges to download (offset and length).
                              111, BG_LENGTH_TO_EOF,
                              83, 7
                             };

    //Need to query the IBackgroundCopyJob interface for an IBackgroundCopyJob3
    //interface pointer. The IBackgroundCopyJob3 interface contains the AddFileWithRanges method.
    hr = pJob->QueryInterface(__uuidof( IBackgroundCopyJob3 ), (void**)&pJob3;);
    if (S_OK == hr)
    {
         pJob->Release(); //No longer need the IBackgoundCopyJob interface pointer.

         //Add a file to the job and specify the ranges from the file to download.
         hr = pJob3->AddFileWithRanges(L"<REMOTENAMEGOESHERE>", L"<LOCALNAMEGOESHERE>",
                                       dwRangeCount, Ranges);
         if (FAILED(hr))
         {
              //Handle error.
              //Returns E_NOTIMPL if not a download job.
              //Returns E_INVALIDARG if dwRangeCount is zero or the remote or local name is invalid.
              //Returns BG_E_INVALID_RANGE if one of the ranges is invalid.
              //Returns BG_E_OVERLAPPING_RANGES if you specify overlapping or duplicate ranges.
         }

          pJob3->Release(); //Release the interface if you are done with it.
     }
    else
    {
         //Handle error. QueryInterface will return E_NOINTERFACE if the version of BITS
         //running on the computer is less than BITS 2.0.
    }
```

## See also

[BG_FILE_RANGE](https://learn.microsoft.com/windows/desktop/api/bits2_0/ns-bits2_0-bg_file_range)

[IBackgroundCopyFile2::GetFileRanges](https://learn.microsoft.com/windows/desktop/api/bits2_0/nf-bits2_0-ibackgroundcopyfile2-getfileranges)

[IBackgroundCopyJob3](https://learn.microsoft.com/windows/desktop/api/bits2_0/nn-bits2_0-ibackgroundcopyjob3)

[IBackgroundCopyJob::AddFile](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-addfile)