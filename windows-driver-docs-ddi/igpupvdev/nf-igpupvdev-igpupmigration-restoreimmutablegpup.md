## Description

The **RestoreImmutableGpup** method is part of the [**IGPUPMigration**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/nn-igpupvdev-igpupmigration) interface, designed to restore the immutable state of a virtual GPU (vGPU) during live migration processes.

## Parameters

### `DeviceLuid`

[in] Pointer to a [**LUID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid) structure that represents the locally unique identifier (LUID) of the device whose immutable state is to be restored.

### `Length`

[in] Pointer to a variable that specifies the length in bytes of the buffer that **RestoreBuffer** points to.

### `RestoreBuffer`

[in] Pointer to a buffer that contains the immutable state of the vGPU that was previously stored.

## Return value

**RestoreImmutableGpup** returns an **HRESULT** value that indicates the status of the method call. Possible return values include, but are not limited to, the following:

| Return value | Description |
|--------------|-------------|
| S_OK | The method call was successful. |
| E_INVALIDARG | The buffer is not large enough to store the immutable state. |

## Remarks

For more information see [Live migration on GPU-P machines](https://learn.microsoft.com/windows-hardware/drivers/display/live-migration-on-gpup-devices).

## See also

[**SaveImmutableGpup**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/nf-igpupvdev-igpupmigration-saveimmutablegpup)