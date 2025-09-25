# IVssBackupComponentsEx3::RecoverSet

## Description

Initiates a LUN resynchronization operation. This method is supported only on Windows server operating systems.

## Parameters

### `dwFlags` [in]

A bitmask of [VSS_RECOVERY_OPTIONS](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_recovery_options) flags that specify how the resynchronization is to be performed.

### `ppAsync` [out]

A pointer to a variable that receives an [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface pointer that can be used to retrieve the status of the LUN resynchronization operation. When the operation is complete, the caller must release the interface pointer by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

This method can return one of these values.

| Return code/value | Description |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The operation was successfully completed. |
| **E_NOTIMPL**<br><br>0x80000001L | The provider for the volume does not support LUN resynchronization. |
| **VSS_E_BAD_STATE**<br><br>0x80042301L | Possible reasons for this return value include:<br><br>* There is no hardware provider that supports the operation.<br>* The requester did not successfully add any volumes to the recovery set.<br>* The method was called in WinPE or in Safe mode.<br>* The caller did not call the [IVssBackupComponents::InitializeForRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-initializeforrestore) method before calling this method. |
| **VSS_E_LEGACY_PROVIDER**<br><br>0x800423F7L | This version of the hardware provider does not support this operation. |
| **VSS_E_PROVIDER_VETO**<br><br>0x80042306L | An unexpected provider error occurred. If this error code is returned, the error must be described in an entry in the application event log, giving the user information on how to resolve the problem. |
| **VSS_E_UNSELECTED_VOLUME**<br><br>0x8004232AL | The resynchronization destination contained a volume that was not explicitly included. |
| **VSS_E_CANNOT_REVERT_DISKID**<br><br>0x800423FEL | The MBR signature or GPT ID for one or more disks could not be set to the intended value. Check the Application event log for more information. |

## Remarks

At the end of the resynchronization operation, by default the newly resychronized LUN will have the same disk signature that the destination LUN had before the resynchronization.

This method cannot be called in WinPE, and it cannot be called in Safe mode. Before calling this method, the caller must call [IVssBackupComponents::InitializeForRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-initializeforrestore) to prepare for the resynchronization.

## See also

[IVssBackupComponentsEx3](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponentsex3)