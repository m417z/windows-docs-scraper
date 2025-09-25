# CVssWriter::IsPathAffected

## Description

The **IsPathAffected** method determines whether
the specified directory or file is included in the current shadow copy set. The path for the directory or file can be a local path or a UNC path of a remote file share.

**IsPathAffected** is a protected method
implemented by the [CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class.

## Parameters

### `wszPath` [in]

Path of the directory or file to be queried.
This path can be a local path or a UNC path of a remote file share.

If the path refers to a directory, it can contain environment variables (for example, %SystemRoot%) but
cannot contain wildcard characters.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **true** | The path is included in the set of volumes being included in the shadow copy set. |
| **false** | The path is not included in the set of volumes being included in the shadow copy set. |

## Remarks

**Windows 7, Windows Server 2008 R2, Windows Vista, Windows Server 2008, Windows XP and Windows Server 2003:** Remote file shares are not supported until Windows 8 and Windows Server 2012. Writers support only local resources—sets of files whose absolute path starts with a
valid local volume specification and cannot be a mapped network drive. The input to
**IsPathAffected** (after the resolution of any
environment variables) must be in this format.

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::OnFreeze](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onfreeze)

[CVssWriter::OnPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparesnapshot)

[CVssWriter::OnThaw](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onthaw)