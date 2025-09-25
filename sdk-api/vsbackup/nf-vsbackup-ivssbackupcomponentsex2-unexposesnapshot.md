# IVssBackupComponentsEx2::UnexposeSnapshot

## Description

Unexposes a shadow copy either by deleting the file share or by removing the drive letter or mounted folder.

## Parameters

### `snapshotId` [in]

The shadow copy identifier. The value of this identifier should be the same as the value that was used when the shadow copy was exposed.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The shadow copy was successfully unexposed. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_OBJECT_NOT_FOUND** | The specified shadow copy does not exist or is not exposed. |
| **VSS_E_PROVIDER_VETO** | An expected provider error has occurred. The error code is logged in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |
| **VSS_E_UNEXPECTED_PROVIDER_ERROR** | An unexpected provider error has occurred. The error code is logged in the error log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## See also

[IVssBackupComponents::ExposeSnapshot](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-exposesnapshot)

[IVssBackupComponentsEx2](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponentsex2)