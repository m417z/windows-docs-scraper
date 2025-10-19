# IBackgroundCopyJob3::ReplaceRemotePrefix

## Description

Replaces the beginning text of all remote names in the download job with the specified string.

## Parameters

### `OldPrefix` [in]

Null-terminated string that identifies the text to replace in the remote name. The text must start at the beginning of the remote name.

### `NewPrefix` [in]

Null-terminated string that contains the replacement text.

## Return value

This method returns the following return values, as well as others.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |
| **S_FALSE** | No matches found. |
| **E_INVALIDARG** | Applying *NewPrefix* creates an invalid URL or the new URL is too long (the URL cannot exceed 2,200 characters).<br><br>You can also receive this return code if the *OldPrefix* or *NewPrefix* is an empty string. |
| **E_NOTIMPL** | You cannot call this method for upload or upload-reply jobs; call this method only for download jobs. |
| **BG_E_INVALID_STATE** | The state of the job cannot be **BG_JOB_STATE_CANCELLED** or **BG_JOB_STATE_ACKNOWLEDGED**. |

## Remarks

Typically, you use this method to change the server portion of the remote name when the server is unavailable or to let roaming users connect to the closest server. This method changes all matching remote names in the job. To change the remote name of a specific file, use the [IBackgroundCopyFile2::SetRemoteName](https://learn.microsoft.com/windows/desktop/api/bits2_0/nf-bits2_0-ibackgroundcopyfile2-setremotename) method.

The **ReplaceRemotePrefix** method performs a case-sensitive search of all the remote names in the job. If the beginning text of the remote name matches the string in *OldPrefix*, BITS replaces the text with the string found in *NewPrefix*. For example, to change "http://Server/Path/File.ext" to "http://NewServerName/Path/File.ext", set *OldPrefix* to "http://Server" and *NewPrefix* to "http://NewServerName". Note that BITS does not perform locale conversions in the search.

If the time stamp or file size of the new remote name is different from the previous remote name or the new server does not support checkpoint resume (for HTTP remote names), BITS restarts the download. Otherwise, the transfer resumes from the same position on the new server. BITS does not restart already transferred files.

You can use this method to change protocols. However, the resulting URL may not be well formed. For example, changing from \\Server\Dir\File.ext to http://Server\Dir\File.ext may not resolve. Consider using the [IBackgroundCopyFile2::SetRemoteName](https://learn.microsoft.com/windows/desktop/api/bits2_0/nf-bits2_0-ibackgroundcopyfile2-setremotename) method instead.

Note that this method may not find URLs to change if you called the [IBackgroundCopyJobHttpOptions::SetSecurityFlags](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setsecurityflags) method and set the **BG_HTTP_REDIRECT_POLICY_ALLOW_REPORT** flag. This policy changes the original URL to the final, redirected URL if the URL is redirected.

#### Examples

The following example shows how to call the **ReplaceRemotePrefix** method to change the server name of a URL. The example assumes the [IBackgroundCopyJob](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob) variable, *pJob*, is valid and the job contains one or more files.

```cpp
     IBackgroundCopyJob *pJob;
     IBackgroundCopyJob3 *pJob3 = NULL;

     //Need to query the IBackgroundCopyJob interface for an IBackgroundCopyJob3
     //interface pointer. The IBackgroundCopyJob3 interface contains the ReplaceRemotePrefix method.
     hr = pJob->QueryInterface(__uuidof( IBackgroundCopyJob3 ), (void**)&pJob3;);
     if (S_OK == hr)
     {
          pJob->Release(); //No longer need the IBackgoundCopyJob interface pointer.

          //Identify the old and new remote name text. For example, "http://oldservername" and
          //"http://newservername". For SMB, specify "\\\\oldservername" and "\\\\newservername".
          hr = pJob3->ReplaceRemotePrefix(L"<OLDSERVERNAMEGOESHERE>", L"<NEWSERVERNAMEGOESHERE>");
          if (S_FALSE == hr)
          {
               wprintf(L"The job does not contain files with a remote name that matches the prefix.\n");
          }
          else if (FAILED(hr))
          {
               //Handle error.
               //Returns E_NOTIMPL if not a download job.
               //Returns E_INVALIDARG if new prefix is empty or the resulting URL is invalid.
          }

          pJob3->Release();
     }
     else
     {
          //Handle error. QueryInterface will return E_NOINTERFACE if the version of BITS
          //running on the computer is less than BITS 2.0.
     }
```

## See also

[IBackgroundCopyFile2::SetRemoteName](https://learn.microsoft.com/windows/desktop/api/bits2_0/nf-bits2_0-ibackgroundcopyfile2-setremotename)

[IBackgroundCopyJob3](https://learn.microsoft.com/windows/desktop/api/bits2_0/nn-bits2_0-ibackgroundcopyjob3)