## Description

The **IGPUPMigrationVtbl** structure defines the virtual table for the [**IGPUPMigration**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/nn-igpupvdev-igpupmigration) interface.

## Members

### `b`

### `QueryInterface`

Retrieves pointers to supported interfaces.

### `AddRef`

Increments the reference count for an interface on an object.

### `Release`

Decrements the reference count for an interface on an object.

### `SaveImmutableGpup`

Method to save the immutable GPU partition.

### `RestoreImmutableGpup`

Method to restore the immutable GPU partition.

## Remarks

For more information see [Live migration on GPU-P machines](https://learn.microsoft.com/windows-hardware/drivers/display/live-migration-on-gpup-devices).

## See also

[**RestoreImmutableGpup**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/nf-igpupvdev-igpupmigration-restoreimmutablegpup)

[**SaveImmutableGpup**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/nf-igpupvdev-igpupmigration-saveimmutablegpup)

[**IGPUPMigration**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/nn-igpupvdev-igpupmigration)