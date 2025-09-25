# IBackgroundCopyFile::GetRemoteName

## Description

Retrieves the remote name of the file.

## Parameters

### `pVal` [out]

Null-terminated string that contains the remote name of the file to transfer. The name is fully qualified. Call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *ppName* when done.

## Return value

This method returns **S_OK** on success or one of the standard COM **HRESULT** values on error.

## Remarks

The remote file name is set when you call the
[AddFile](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-addfile) or
[AddFileSet](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-addfileset) methods of the
[IBackgroundCopyJob](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob) interface.

To change the remote file name, call the [IBackgroundCopyFile2::SetRemoteName](https://learn.microsoft.com/windows/desktop/api/bits2_0/nf-bits2_0-ibackgroundcopyfile2-setremotename) method or the [IBackgroundCopyJob3::ReplaceRemotePrefix](https://learn.microsoft.com/windows/desktop/api/bits2_0/nf-bits2_0-ibackgroundcopyjob3-replaceremoteprefix) method.

#### Examples

See the example code for the
[IBackgroundCopyFile::GetLocalName](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyfile-getlocalname) method.

## See also

[IBackgroundCopyFile](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyfile)

[IBackgroundCopyFile::GetLocalName](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyfile-getlocalname)

[IBackgroundCopyJob::AddFile](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-addfile)

[IBackgroundCopyJob::AddFileSet](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-addfileset)