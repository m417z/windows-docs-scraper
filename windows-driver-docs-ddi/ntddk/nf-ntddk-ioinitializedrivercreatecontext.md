# IoInitializeDriverCreateContext function

## Description

The **IoInitializeDriverCreateContext** routine initializes a caller-allocated variable of type [IO_DRIVER_CREATE_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_io_driver_create_context).

## Parameters

### `DriverContext`

A pointer to a caller-allocated variable of type IO_DRIVER_CREATE_CONTEXT.

## Remarks

The **IoInitializeDriverCreateContext** routine initializes a caller-allocated IO_DRIVER_CREATE_CONTEXT structure used in passing additional create parameters to the [FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2) and [IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex) routines.

Callers of **IoInitializeDriverCreateContext** can be running at any IRQL if the *DriverContext* block is in nonpaged pool. Otherwise, the caller must be running at IRQL <= APC_LEVEL.

Starting in Windows 10, version 1607, this routine sets the **SiloContext** member of [IO_DRIVER_CREATE_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_io_driver_create_context) to **IO_USE_AMBIENT_SILO**.

## See also

[FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2)

[IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)