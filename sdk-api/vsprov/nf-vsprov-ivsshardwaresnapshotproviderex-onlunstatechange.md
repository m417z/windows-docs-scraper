# IVssHardwareSnapshotProviderEx::OnLunStateChange

## Description

The VSS service calls this method to notify hardware providers of a LUN state change.

**Note** Hardware providers are only supported on Windows Server operating systems.

## Parameters

### `pSnapshotLuns` [in]

A pointer to an array of *dwCount* [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structures, one for each LUN that contributes to the shadow copy volume.

### `pOriginalLuns` [in]

A pointer to an array of *dwCount* [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structures, one for each LUN that contributes to the original volume.

### `dwCount` [in]

Number of elements in the *pSnapshotLuns* array. This is also the number of elements in the *pOriginalLuns* array.

### `dwFlags` [in]

A bitmask of [_VSS_HARDWARE_OPTIONS](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_hardware_options) flags that provide information about the state change that the shadow copy LUNs have undergone. The following table describes how each flag is used in this parameter.

| Value | Meaning |
| --- | --- |
| **VSS_ONLUNSTATECHANGE_NOTIFY_READ_WRITE**<br><br>0x00000100 | The shadow copy LUN will be converted permanently to read-write. |
| **VSS_ONLUNSTATECHANGE_NOTIFY_LUN_PRE_RECOVERY**<br><br>0x00000200 | The shadow copy LUNs will be converted temporarily to read-write and are about to undergo TxF recovery or VSS auto-recovery. |
| **VSS_ONLUNSTATECHANGE_NOTIFY_LUN_POST_RECOVERY**<br><br>0x00000400 | The shadow copy LUNs have just undergone TxF recovery or VSS auto-recovery and have been converted back to read-only. |
| **VSS_ONLUNSTATECHANGE_DO_MASK_LUNS**<br><br>0x00000800 | The shadow copy LUNs must be masked from the current machine but not deleted. |

## Return value

This method can return one of these values.

| Return code/value | Description |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The operation was successfully completed. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | Out of memory or other system resources. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| **VSS_E_PROVIDER_VETO**<br><br>0x80042306L | An unexpected provider error occurred. If this is returned, the error must be described in an entry in the application event log, giving the user information on how to resolve the problem. |

## See also

[IVssHardwareSnapshotProviderEx](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivsshardwaresnapshotproviderex)