# AuxKlibInitialize function

## Description

The **AuxKlibInitialize** routine initializes the [Auxiliary Kernel-Mode Library](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/).

## Return value

**AuxKlibInitialize** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the routine returns an appropriate NTSTATUS value.

## Remarks

Drivers that use the Auxiliary Kernel-Mode Library must call **AuxKlibInitialize** before calling any of the library's other routines.