# VSS_HARDWARE_OPTIONS enumeration

## Description

Defines shadow copy LUN flags.

## Constants

### `VSS_BREAKEX_FLAG_MASK_LUNS:0x1`

The shadow copy LUN will be masked from the host.

### `VSS_BREAKEX_FLAG_MAKE_READ_WRITE:0x2`

The shadow copy LUN will be exposed to the host as a read-write volume.

### `VSS_BREAKEX_FLAG_REVERT_IDENTITY_ALL:0x4`

The disk identifiers of all of the shadow copy LUNs will be reverted to that of the original LUNs. However, if any of the original LUNs are present on the system, the operation will fail and none of the identifiers will be reverted.

### `VSS_BREAKEX_FLAG_REVERT_IDENTITY_NONE:0x8`

None of the disk identifiers of the shadow copy LUNs will be reverted.

### `VSS_ONLUNSTATECHANGE_NOTIFY_READ_WRITE:0x100`

The shadow copy LUNs will be converted permanently to read-write. This flag is set only as a notification for the provider; no provider action is required. For more information, see the [IVssHardwareSnapshotProviderEx::OnLunStateChange](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotproviderex-onlunstatechange) method.

### `VSS_ONLUNSTATECHANGE_NOTIFY_LUN_PRE_RECOVERY:0x200`

The shadow copy LUNs will be converted temporarily to read-write and are about to undergo TxF recovery or VSS auto-recovery. This flag is set only as a notification for the provider; no provider action is required. For more information, see the [IVssHardwareSnapshotProviderEx::OnLunStateChange](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotproviderex-onlunstatechange) method.

### `VSS_ONLUNSTATECHANGE_NOTIFY_LUN_POST_RECOVERY:0x400`

The shadow copy LUNs have just undergone TxF recovery or VSS auto-recovery and have been converted back to read-only. This flag is set only as a notification for the provider; no provider action is required. For more information, see the [IVssHardwareSnapshotProviderEx::OnLunStateChange](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotproviderex-onlunstatechange) method.

### `VSS_ONLUNSTATECHANGE_DO_MASK_LUNS:0x800`

The provider must mask shadow copy LUNs from this computer. For more information, see the [IVssHardwareSnapshotProviderEx::OnLunStateChange](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotproviderex-onlunstatechange) method.

## See also

[IVssHardwareSnapshotProviderEx::OnLunStateChange](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotproviderex-onlunstatechange)