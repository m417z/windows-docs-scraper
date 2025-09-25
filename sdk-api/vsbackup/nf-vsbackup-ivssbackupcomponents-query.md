# IVssBackupComponents::Query

## Description

The **Query** method queries providers on the
system and/or the completed shadow copies in the system that reside in the current context. The method can be
called only during backup operations.

## Parameters

### `QueriedObjectId` [in]

Reserved. The value of this parameter must be GUID_NULL.

### `eQueriedObjectType` [in]

Indicates restriction of the query to the given object type. A value of VSS_OBJECT_NONE indicates no
restriction—that is, all objects will be queried.

Currently, the value of this parameter must be **VSS_OBJECT_NONE**.

### `eReturnedObjectsType` [in]

Object types to be returned. The value of this parameter must be either
**VSS_OBJECT_SNAPSHOT** or **VSS_OBJECT_PROVIDER**.

### `ppEnum` [out]

Doubly indirect pointer to an [IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject) enumerator object.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned a pointer to an instance of the [IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject) interface. |
| **E_ACCESSDENIED** | The caller is not an administrator or a backup operator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | Out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_OBJECT_NOT_FOUND** | The queried object is not found. |
| **VSS_E_PROVIDER_VETO** | Expected provider error. The provider logged the error in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |
| **VSS_E_UNEXPECTED_PROVIDER_ERROR** | Unexpected provider error. The error code is logged in the error log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

Because **Query** returns only information on
completed shadow copies, the only shadow copy state it can disclose is VSS_SS_COMPLETED.

The method may be called only during backup operations and must be preceded by calls to
[IVssBackupComponents::InitializeForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-initializeforbackup)
and [IVssBackupComponents::SetContext](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setcontext).

While **Query** can return information on all of
the providers available on a system, it will return only information about shadow copies with the current context
(set by [IVssBackupComponents::SetContext](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setcontext)).
For instance, if the [_VSS_SNAPSHOT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_context) context
is set to **VSS_CTX_BACKUP**,
**Query** will not return information on a shadow
copy created with a context of VSS_CTX_FILE_SHARE_BACKUP.

While this method currently returns a lists of all available providers and/or all completed shadow copies, in the
future, specialized queries may be supported: for instance, querying all shadow copies associated with a provider.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::InitializeForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-initializeforbackup)

[IVssBackupComponents::SetContext](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setcontext)

[IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject)