# CreateVssBackupComponentsInternal function

## Description

The **CreateVssBackupComponents** function
creates an [IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)
interface object and returns a pointer to it.

**Note** This function is exported as **CreateVssBackupComponentsInternal**, but you should call **CreateVssBackupComponents**, not **CreateVssBackupComponentsInternal**.

## Parameters

### `ppBackup` [out]

Doubly indirect pointer to the created
[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents) interface object.

## Return value

The return values listed here are in addition to the normal COM **HRESULT**s that may be returned at any time
from the function.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned a pointer to an [IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents) interface. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | Out of memory or other system resources. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. **E_UNEXPECTED** is used instead. |

## Remarks

The calling application is responsible for calling [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) to release the
resources held by the returned
[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents) when it is no
longer needed.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)