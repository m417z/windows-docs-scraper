## Description

**DXGK_UPDATECURRENTVALUESFROMCPU_FLAGS** specifies flags to use when updating the current value of a batch of native fences from the CPU.

## Members

### `AlwaysSignaled`

To handle special cases such as the parent device of the fence being put in error, *Dxgkrnl* will provide a new **CurrentValue** as 0xFFFFFFFF and call [**DxgkDdiUpdateCurrentValuesFromCpu**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updatecurrentvaluesfromcpu) with the **AlwaysSignaled** flag set. This flag indicates to the driver that the fence object **CurrentValue** can't be relied upon to be updated as before. The driver / context management processor must ensure that when it sees a GPU wait of this fence, it must be unblocked immediately without actually queuing a wait. Similarly, when it sees a signal of this fence it should be a no-op and not touch the fence storage.

### `NotificationOnly`

OS sets this flag to inform KMD that it should not actually write a new value to **CurrentValue** location, and instead this call is just a notification that **CurrentValue** was updated and KMD should re-scan its runlist to unblock any GPU waiters that are now signaled. This flag is used to handle cross-adapter native fences, as described in [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

### `Reserved`

Reserved for system use.

### `Value`

An alternative way to access the flags.

## Remarks

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DXGKARG_UPDATECURRENTVALUESFROMCPU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_updatecurrentvaluesfromcpu)

[**DxgkDdiUpdateCurrentValuesFromCpu**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updatecurrentvaluesfromcpu)