# IVssBackupComponents::DisableWriterClasses

## Description

The
**DisableWriterClasses** method prevents a specific class of writers from receiving any events.

## Parameters

### `rgWriterClassId` [in]

An array containing one or more writer class identifiers.

### `cClassId` [in]

The number of entries in the *rgWriterClassId* array.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The writer class has been successfully disabled. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

If you have multiple running copies of the same writer, they will all have the same writer class identifier, but they will have different writer instance identifiers. Disabling a writer class causes all of the writer's instances to be disabled.

If the **DisableWriterClasses** method and the [IVssBackupComponents::EnableWriterClasses](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-enablewriterclasses) method are never called, all writer classes are enabled.

After the first call to **DisableWriterClasses** returns, the writer classes that were specified in the *rgWriterClassId* array are disabled, and all other writer classes are enabled.

If you call **DisableWriterClasses** more than once, each call adds the writers in the *rgWriterClassId* array to the list of disabled writers.

If you call **DisableWriterClasses** one or more times and then call [EnableWriterClasses](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-enablewriterclasses), the first call to **EnableWriterClasses** cancels the effect of the calls to **DisableWriterClasses** and enables only the writers in the *rgWriterClassId* array.

If you call **DisableWriterClasses**, you must do so before calling the [IVssBackupComponents::GatherWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwritermetadata) method. If you call **GatherWriterMetadata** first and then call **DisableWriterClasses**, the call to **DisableWriterClasses** has no effect. If you need to call **GatherWriterMetadata** first, to determine which writer classes to disable, you must call it from a different instance of the [IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents) interface.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::DisableWriterInstances](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-disablewriterinstances)

[IVssBackupComponents::EnableWriterClasses](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-enablewriterclasses)