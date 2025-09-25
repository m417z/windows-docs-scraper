# CVssWriter::AreComponentsSelected

## Description

The
**AreComponentsSelected** method indicates whether a requester is running under component mode and supports selecting individual components to be backed up or backs up entire volumes.

**AreComponentsSelected** is a protected method implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **true** | The requester supports selecting components. |
| **false** | The requester does not support selecting components. |

## Remarks

If false is returned, it indicates that the backup application (requester) is not running under component mode.

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::OnBackupComplete](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onbackupcomplete)

[CVssWriter::OnPostRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostrestore)

[CVssWriter::OnPreRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onprerestore)

[CVssWriter::OnPrepareBackup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparebackup)