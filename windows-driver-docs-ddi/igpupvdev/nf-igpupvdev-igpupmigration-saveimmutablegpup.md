## Description

The **SaveImmutableGpup** method is part of the [**IGPUPMigration**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/nn-igpupvdev-igpupmigration) interface, designed to save the immutable state of a virtual GPU (vGPU) during live migration processes.

## Parameters

### `DeviceLuid`

[in] Pointer to a [**LUID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid) structure that represents the locally unique identifier (LUID) of the device whose immutable state is to be saved.

### `Length`

[in, out] Pointer to a variable that specifies the length in bytes of the buffer that **SaveBuffer** points to. On input, this variable specifies the size of the buffer. On output, it receives the number of bytes written to the buffer.

### `SaveBuffer`

[in, out] Pointer to a caller-allocated buffer that receives the immutable state of the device.

## Return value

**SaveImmutableGpup** returns an **HRESULT** value that indicates the status of the method call. Possible return values include, but are not limited to, the following:

| Return value | Description |
|--------------|-------------|
| S_OK | The method call was successful. |
| E_INVALIDARG | An invalid argument was passed to the method. |
| E_OUTOFMEMORY | The method failed to allocate memory for the buffer. |

## Remarks

The **SaveImmutableGpup** method captures the immutable state of a vGPU device, which remains constant throughout the device's lifetime. This state is essential for ensuring consistency during live migration.

It's typically called during the preparation phase of a live migration process, before the device's mutable state is saved.

For more information see [Live migration on GPU-P machines](https://learn.microsoft.com/windows-hardware/drivers/display/live-migration-on-gpup-devices).

## See also

[**RestoreImmutableGpup**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/nf-igpupvdev-igpupmigration-restoreimmutablegpup)