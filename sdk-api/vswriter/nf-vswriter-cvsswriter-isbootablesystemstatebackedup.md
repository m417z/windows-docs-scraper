# CVssWriter::IsBootableSystemStateBackedUp

## Description

The
**IsBootableSystemStateBackedUp** method indicates whether the bootable state will be backed up.

**IsBootableSystemStateBackedUp** is a protected method implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **true** | Bootable system state will be backed up. |
| **false** | Bootable system state will not be backed up. |

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::OnBackupComplete](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onbackupcomplete)

[CVssWriter::OnPostRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostrestore)

[CVssWriter::OnPreRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onprerestore)

[CVssWriter::OnPrepareBackup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparebackup)