# IVssFileShareSnapshotProvider::IsPathSupported

## Description

Determines whether the given Universal Naming Convention (UNC) path is supported by this provider.

## Parameters

### `pwszSharePath` [in]

The path to the file share.

### `pbSupportedByThisProvider` [out]

This parameter receives **TRUE** if shadow copies are supported on the specified volume, otherwise **FALSE**.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The requested information was successfully returned. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **VSS_E_NESTED_VOLUME_LIMIT** | The specified volume is nested too deeply to participate in the VSS operation.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This return code is not supported. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_OBJECT_NOT_FOUND** | The specified volume was not found. |
| **VSS_E_PROVIDER_VETO** | Provider error. The provider logged the error in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The VSS coordinator calls this method as part of [AddToSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addtosnapshotset) to determine which provider to use for snapshot creation.

## See also

[IVssFileShareSnapshotProvider](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivssfilesharesnapshotprovider)