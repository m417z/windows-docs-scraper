# CVssWriter::GetBackupType

## Description

The
**GetBackupType** method indicates the type of backup to be performed.

**GetBackupType** is a protected method implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class.

## Return value

This method returns the backup type as a
[VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type) enumeration value. See
**VSS_BACKUP_TYPE** for a description of these values.

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::OnBackupComplete](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onbackupcomplete)

[CVssWriter::OnPostRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostrestore)

[CVssWriter::OnPreRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onprerestore)

[CVssWriter::OnPrepareBackup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparebackup)

[VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type)