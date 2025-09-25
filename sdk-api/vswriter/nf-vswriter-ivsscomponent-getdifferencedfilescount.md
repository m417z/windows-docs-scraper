# IVssComponent::GetDifferencedFilesCount

## Description

The **GetDifferencedFilesCount**
method returns the number of file specifications in this component (and in any subcomponents of the
component set it defines) marked by a writer supporting an incremental backup or restore as differenced
files—that is, backup and restores associated with it are to be implemented as if
entire files are copied to and from backup media (as opposed to using partial files).

## Parameters

### `pcDifferencedFiles` [out]

The address of a caller-allocated variable that receives the number of differenced file specifications.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::AddDifferencedFilesByLastModifyTime](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-adddifferencedfilesbylastmodifytime)

[IVssComponent::GetDifferencedFile](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getdifferencedfile)

[Incremental and Differential Backups](https://learn.microsoft.com/windows/desktop/VSS/incremental-and-differential-backups)