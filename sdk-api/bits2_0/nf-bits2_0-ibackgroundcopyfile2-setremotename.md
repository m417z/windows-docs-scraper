# IBackgroundCopyFile2::SetRemoteName

## Description

Changes the remote name to a new URL in a download job.

## Parameters

### `Val` [in]

Null-terminated string that contains the name of the file on the server. For information on specifying the remote name, see the **RemoteName** member and Remarks section of the [BG_FILE_INFO](https://learn.microsoft.com/windows/desktop/api/bits/ns-bits-bg_file_info) structure.

## Return value

This method returns the following return values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Success |
| **E_INVALIDARG** | The new remote name is an invalid URL or the new URL is too long (the URL cannot exceed 2,200 characters). |
| **E_NOTIMPL** | You cannot call this method for upload or upload-reply jobs; only call this method for download jobs. |
| **BG_E_INVALID_STATE** | The state of the job cannot be **BG_JOB_STATE_CANCELLED** or **BG_JOB_STATE_ACKNOWLEDGED**. |

## Remarks

 Typically, you call this method if you want to change the protocol used to transfer the file (for example, from SMB to HTTP) or if you want to change the file name or path.

This method does not serialize when it returns. To serialize the change, [suspend](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-suspend) the job, call this method (if changing multiple files in the job, use a loop), and [resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume) the job. Calling the **IBackgroundCopyJob::Resume** method serializes the change.

If the time stamp or file size of the new remote name is different from the previous remote name or the new server does not support checkpoint resume (for HTTP remote names), BITS restarts the download. Otherwise, the transfer resumes from the same position on the new server. BITS does not restart already transferred files.

If the remote name identifies a server message block (SMB) path, the following table identifies possible error codes that can occur after you resume the job. These errors place the job in the **BG_JOB_STATE_ERROR** state.

| Error code | Description |
| --- | --- |
| `HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND)` | The directory was not found. |
| `HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)` | The file was not found. |
| `HRESULT_FROM_WIN32(ERROR_ACCESS_DENIED)` | The user does not have access to the file specified in *Val*. |

#### Examples

The following example shows how to call the **SetRemoteName** method to change the remote name of a file. The example assumes the [IBackgroundCopyJob](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob) variable, pJob, is valid and the job contains one or more files.

```cpp
     IBackgroundCopyJob *pJob;
     IEnumBackgroundCopyFiles* pFiles = NULL;
     IBackgroundCopyFile* pFile = NULL;
     IBackgroundCopyFile2* pFile2 = NULL;
     WCHAR* pRemoteFileName = NULL;
     ULONG cFileCount = 0;

     hr = pJob->Suspend();
     hr = pJob->EnumFiles(&pFiles);
     if (SUCCEEDED(hr))
     {
          //Get the count of files in the job.
          hr = pFiles->GetCount(&cFileCount);

          //Enumerate the files in the job.
          for (ULONG idx=0; idx<cFileCount; idx++)
          {
               hr = pFiles->Next(1, &pFile, NULL);
               if (S_OK == hr)
               {
                    //Get the local name of the file.
                    hr = pFile->GetRemoteName(&pRemoteFileName);
                    if (SUCCEEDED(hr))
                    {
                         //Determine if you want to replace the remote name of this file.
                         if (<CONDITIONGOESHERE>)
                         {
                              //Need to query the IBackgroundCopyFile interface for an IBackgroundCopyFile2
                              //interface pointer. The IBackgroundCopyFile2 interface contains the SetRemoteName method.
                              hr = pFile->QueryInterface(__uuidof(IBackgroundCopyFile2), (void**)&pFile2);
                              if (S_OK == hr)
                              {
                                   hr = pFile2->SetRemoteName(L"<NEWURLGOESHERE>");
                                   if (FAILED(hr))
                                   {
                                        //Handle error.
                                        //Returns E_NOTIMPL if not a download job.
                                        //Returns E_INVALIDARG if invalid URL.
                                   }
                              }
                              else
                              {
                                   //handle error. QueryInterface will return E_NOINTERFACE if the version of BITS
                                   //running on the computer is less than BITS 2.0.
                              }
                         }
                         CoTaskMemFree(pRemoteFileName);
                    }
                    pFile->Release();
                    pFile = NULL;
               }
               else
               {
                    //Handle error
                    break;
               }
          }

          pFiles->Release();
          pFiles = NULL;
     }

     hr = pJob->Resume(); //Force the job to serialize.

```

## See also

[IBackgroundCopyFile2](https://learn.microsoft.com/windows/desktop/api/bits2_0/nn-bits2_0-ibackgroundcopyfile2)

[IBackgroundCopyJob3::ReplaceRemotePrefix](https://learn.microsoft.com/windows/desktop/api/bits2_0/nf-bits2_0-ibackgroundcopyjob3-replaceremoteprefix)