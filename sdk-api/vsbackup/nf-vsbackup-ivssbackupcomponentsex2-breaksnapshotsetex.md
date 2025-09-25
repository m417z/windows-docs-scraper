# IVssBackupComponentsEx2::BreakSnapshotSetEx

## Description

Breaks a shadow copy set according to requester-specified options.

## Parameters

### `SnapshotSetID` [in]

A shadow copy set identifier.

### `dwBreakFlags` [in]

A bitmask of [_VSS_HARDWARE_OPTIONS](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_hardware_options) flags that specify how the shadow copy set is broken.

### `ppAsync` [out]

A pointer to a variable that receives an [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface pointer that can be used to retrieve the status of the shadow copy set break operation. When the break operation is complete, the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method must be called for this interface pointer.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The shadow copy set was successfully broken. |
| **E_ACCESSDENIED**<br><br>0x80070005L | The caller does not have sufficient privileges or is not an administrator. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | The caller is out of memory or other system resources. |
| **VSS_E_BREAK_REVERT_ID_FAILED**<br><br>0x800423F6L | The shadow copy set break operation failed because the MBR disk signature, the GPT disk identifier, or the GPT partition identifier of one or more of the destination LUNs could not be reverted to those of the original LUNs. If one or more original LUNs are not masked on the computer, the break operation would cause a signature collision. |
| **VSS_E_OBJECT_NOT_FOUND**<br><br>0x80042308L | The specified shadow copy does not exist. |
| **VSS_E_PROVIDER_VETO**<br><br>0x80042306L | The shadow copy was created by a software provider and cannot be broken. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

**BreakSnapshotSetEx** is similar to the [IVssBackupComponents::BreakSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-breaksnapshotset) method, except that it has extra parameters to query status and specify how the shadow copy set is broken.

Like [BreakSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-breaksnapshotset), **BreakSnapshotSetEx** can be used only for shadow copies that were created by a hardware shadow copy provider.

After this method returns, the shadow copy volume is still a volume, but it is no longer a shadow copy. For more information, see [Breaking Shadow Copies](https://learn.microsoft.com/windows/desktop/VSS/breaking-shadow-copies).