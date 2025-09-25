# IBackgroundCopyFile::GetLocalName

## Description

Retrieves the local name of the file.

## Parameters

### `pVal` [out]

Null-terminated string that contains the name of the file on the client. The name is fully qualified. Call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *ppName* when done.

## Return value

This method returns **S_OK** on success or one of the standard COM **HRESULT** values on error.

## Remarks

The local file name is set when you call the
[AddFile](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-addfile) or
[AddFileSet](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-addfileset) methods of the
[IBackgroundCopyJob](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob) interface.

#### Examples

The following example shows how to retrieve the local and remote file names and progress-related information from the
[IBackgroundCopyFile](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyfile) interface. The example assumes the
**IBackgroundCopyFile** interface pointer is valid.

```cpp
IBackgroundCopyFile* pFile;
HRESULT hr;
WCHAR* pszLocalFileName = NULL;
WCHAR* pszRemoteFileName = NULL;
WCHAR  szPercentComplete[4+1];
BG_FILE_PROGRESS Progress;

hr = pFile->GetLocalName(&pszLocalFileName);
if (SUCCEEDED(hr))
{
  hr = pFile->GetRemoteName(&pszRemoteFileName);
  if (SUCCEEDED(hr))
  {
    pFile->GetProgress(&Progress);
    if (BG_SIZE_UNKNOWN == Progress.BytesTotal)
    {
      StringCchPrintf(szPercentComplete, sizeof(szPercentComplete), L"0%%");
    }
    else
    {
      StringCchPrintf(szPercentComplete, sizeof(szPercentComplete), L"%I64d%%",
          100*Progress.BytesTransferred/Progress.BytesTotal);
    }
    //Do something with the file names and progress information.
  }
}
if (pszLocalFileName)
  CoTaskMemFree(pszLocalFileName);
if (pszRemoteFileName)
  CoTaskMemFree(pszRemoteFileName);
```

## See also

[IBackgroundCopyFile](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyfile)

[IBackgroundCopyFile::GetRemoteName](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyfile-getremotename)

[IBackgroundCopyJob::AddFile](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-addfile)

[IBackgroundCopyJob::AddFileSet](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-addfileset)