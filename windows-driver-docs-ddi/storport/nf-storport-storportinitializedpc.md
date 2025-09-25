# StorPortInitializeDpc function

## Description

The **StorPortInitializeDpc** routine initializes a StorPort DPC.

## Parameters

### `DeviceExtension` [in]

Pointer to the per-adapter device extension.

### `Dpc` [out]

Pointer to a buffer where a DPC object of type [STOR_DPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_dpc) will be created. The caller must ensure that the size in bytes of this buffer is greater than or equal to **sizeof**(STOR_DPC).

### `HwDpcRoutine` [in]

Pointer to the DPC routine that corresponds to the DPC object pointed to by *Dpc*. The prototype for this deferred routine is defined in Storport.h as follows:

```
typedef
VOID
(*PHW_DPC_ROUTINE)
  IN PSTOR_DPC  Dpc,
  IN PVOID  HwDeviceExtension,
  IN PVOID  SystemArgument1,
  IN PVOID  SystemArgument2
  );
```

## Remarks

The **StorPortInitializeDpc** routine must be called during HBA initialization from within the miniport driver's [HwStorPassiveInitializeRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_passive_initialize_routine) routine.

This routine is implemented using inline function definitions, so that miniport drivers that use this routine will not have to link to libraries that are dependent on the version of the operating system. Miniport drivers can use this routine without sacrificing backward compatibility with versions of the operating system that do not support DPCs in storage miniport drivers.

## See also

[HwStorPassiveInitializeRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_passive_initialize_routine)

[STOR_DPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_dpc)