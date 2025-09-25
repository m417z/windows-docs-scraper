# IVssHardwareSnapshotProviderEx::ResyncLuns

## Description

The VSS service calls this method to notify hardware providers that a LUN resynchronization is needed.

**Note** Hardware providers are only supported on Windows Server operating systems.

## Parameters

### `pSourceLuns` [in]

A pointer to an array of *dwCount* [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structures, one for each LUN that contributes to the shadow copy volume.

### `pTargetLuns` [in]

A pointer to an array of *dwCount* [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structures, one for each LUN that contributes to the destination volume where the contents of the shadow copy volume are to be copied.

### `dwCount` [in]

The number of elements in the *pSourceLuns* array. This is also the number of elements in the *pTargetLuns* array.

### `ppAsync` [out]

A pointer to a location that will receive an [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface pointer that can be used to retrieve the status of the resynchronization operation. When the operation is complete, the caller must release the interface pointer by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

This method can return one of these values.

| Return code/value | Description |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The operation was successfully completed. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | Out of memory or other system resources. |
| **VSS_E_PROVIDER_VETO**<br><br>0x80042306L | An unexpected provider error occurred. If this error code is returned, the error must be described in an entry in the application event log, giving the user information on how to resolve the problem. |
| **VSS_E_INSUFFICIENT_STORAGE**<br><br>0x8004231FL | The provider cannot perform the operation because there is not enough disk space. |

## Remarks

The destination LUNs can be the LUNs that contribute to the original production volume from which the shadow copy was created, or they can be new or existing LUNs that are used to replace an original volume that is removed from production.

The provider must perform the resynchronization by copying data at the LUN array level, not at the host level. This means that the provider cannot implement LUN resynchronization by simply copying the contents of the source LUN to the destination LUN. The I/O that is required to perform the LUN resynchronization must be performed in the hardware, through the disk devices of the resynchronized LUNs, and not through the host computer. This I/O should be completely transparent to the host computer.

When the resynchronization is complete, the LUNs are fully functional and are available for I/O operations.

The underlying disk hardware must support unique page 83 device identifiers.

If the destination LUN is larger than the source LUN, the provider must resize the destination LUN if necessary to ensure that it matches the source LUN after resynchronization.

This method cannot be called in WinPE, and it cannot be called in Safe mode. Before calling this method, the caller must use the [IVssBackupComponents::InitializeForRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-initializeforrestore) method to prepare for the resynchronization.

## See also

[IVssHardwareSnapshotProviderEx](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivsshardwaresnapshotproviderex)