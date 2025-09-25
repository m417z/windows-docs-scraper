# IVssBackupComponents::DisableWriterInstances

## Description

The
**DisableWriterInstances** method disables a specified writer instance or instances.

## Parameters

### `rgWriterInstanceId` [in]

An array containing one or more writer instance identifiers.

### `cInstanceId` [in]

The number of entries in the *rgWriterInstanceId* array.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The writer class has been successfully enabled. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

If you have multiple running copies of the same writer, they will all have the same writer class identifier, but they will have different writer instance identifiers. Disabling one instance of a writer does not cause the writer's other instances to be disabled.

If you call **DisableWriterInstances**, you must do so before calling the [IVssBackupComponents::GatherWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwritermetadata) method. If you call **GatherWriterMetadata** first and then call **DisableWriterInstances**, the call to **DisableWriterInstances** has no effect. If you need to call **GatherWriterMetadata** first, to determine which writer instances to disable, you must call it from a different instance of the [IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents) interface.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::DisableWriterClasses](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-disablewriterclasses)

[IVssBackupComponents::EnableWriterClasses](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-enablewriterclasses)

[IVssBackupComponents::GatherWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwritermetadata)