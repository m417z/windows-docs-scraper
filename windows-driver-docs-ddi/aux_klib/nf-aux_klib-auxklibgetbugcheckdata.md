# AuxKlibGetBugCheckData function

## Description

The **AuxKlibGetBugCheckData** routine retrieves information about a bug check that has just occurred.

## Parameters

### `BugCheckData` [out]

A pointer to a [KBUGCHECK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/ns-aux_klib-_kbugcheck_data) structure that contains information about the bug check. The *BugCheckData* size of this structure should be set equal to the size, in bytes, of the **KBUGCHECK_DATA** structure.

## Return value

**AuxKlibGetBugCheckData** returns STATUS_SUCCESS if the operation succeeds. The routine returns STATUS_INFO_LENGTH_MISMATCH if the **KBUGCHECK_DATA** structure's size is incorrect.

## Remarks

The **AuxKlibGetBugCheckData** routine can be called only from a [BugCheckCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kbugcheck_callback_routine) routine.

Drivers must call [AuxKlibInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibinitialize) before calling **AuxKlibGetBugCheckData**.

## See also

[AuxKlibInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibinitialize)

[BugCheckCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kbugcheck_callback_routine)

[KBUGCHECK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/ns-aux_klib-_kbugcheck_data)