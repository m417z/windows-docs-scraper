# RtlRemoveUnicodePrefix function

## Description

The **RtlRemoveUnicodePrefix** routine removes an element from a prefix table.

## Parameters

### `PrefixTable` [in]

Pointer to the prefix table. The table must have been initialized by calling [RtlInitializeUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinitializeunicodeprefix).

### `PrefixTableEntry` [in]

Pointer to the prefix table element to be deleted.

## Return value

None

## Remarks

File systems must call [RtlInitializeUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinitializeunicodeprefix) to initialize the prefix table before using any other **Rtl..UnicodePrefix** routines on it. The initialized prefix table structure should be considered opaque.

Callers of the **Rtl..UnicodePrefix** routines are responsible for synchronizing access to the prefix table. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[RtlFindUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlfindunicodeprefix)

[RtlInitializeUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinitializeunicodeprefix)

[RtlInsertUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinsertunicodeprefix)

[RtlNextUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlnextunicodeprefix)