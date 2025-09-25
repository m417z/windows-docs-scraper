# IVssBackupComponents::EnableWriterClasses

## Description

The
**EnableWriterClasses** method enables the specified writers to receive all events.

## Parameters

### `rgWriterClassId` [in]

An array containing one or more writer class identifiers.

### `cClassId` [in]

The number of entries in the *rgWriterClassId* array.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully enabled the writer class. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

If the **EnableWriterClasses** method and the [IVssBackupComponents::DisableWriterClasses](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-disablewriterclasses) method are never called, all writer classes are enabled.

After the first call to **EnableWriterClasses** returns, the writer classes that were specified in the *rgWriterClassId* array are enabled, and all other writer classes are disabled.

If you call **EnableWriterClasses** more than once, each call adds the writers in the *rgWriterClassId* array to the list of enabled writers.

If you call **EnableWriterClasses** one or more times and then call [DisableWriterClasses](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-disablewriterclasses), the call to **DisableWriterClasses** disables any writers in the *rgWriterClassId* array that were enabled in the calls to **EnableWriterClasses**.

If you call **EnableWriterClasses**, you must do so before calling the [IVssBackupComponents::GatherWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwritermetadata) method. If you call **GatherWriterMetadata** first and then call **EnableWriterClasses**, the call to **EnableWriterClasses** has no effect. If you need to call **GatherWriterMetadata** first, to determine which writer classes to enable, you must call it from a different instance of the [IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents) interface.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::DisableWriterClasses](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-disablewriterclasses)

[IVssBackupComponents::DisableWriterInstances](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-disablewriterinstances)