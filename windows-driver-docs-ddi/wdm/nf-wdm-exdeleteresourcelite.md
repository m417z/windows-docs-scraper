# ExDeleteResourceLite function

## Description

The **ExDeleteResourceLite** routine deletes a given resource from the system's resource list.

## Parameters

### `Resource` [in, out]

A pointer to the caller-supplied storage for the initialized resource variable to be deleted.

## Return value

**ExDeleteResourceLite** returns STATUS_SUCCESS if the resource was deleted.

## Remarks

A call to **ExDeleteResourceLite** must be preceded by a call to **ExInitializeResourceLite**.

After calling **ExDeleteResourceLite**, the caller can free the memory it allocated for its resource.

For more information, see [ERESOURCE routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-eresource-routines).

## See also

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)

[ExInitializeResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializeresourcelite)

[ExReinitializeResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializeresourcelite)