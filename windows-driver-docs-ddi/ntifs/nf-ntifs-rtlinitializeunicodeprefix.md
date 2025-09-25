# RtlInitializeUnicodePrefix function

## Description

The **RtlInitializeUnicodePrefix** routine initializes a prefix table.

## Parameters

### `PrefixTable` [out]

Pointer to caller-allocated buffer, which must be at least **sizeof**(UNICODE_PREFIX_TABLE), for the prefix table header. **RtlInitializeUnicodePrefix** initializes this header, which should be considered opaque by the caller.

## Return value

None

## Remarks

File systems must call **RtlInitializeUnicodePrefix** to initialize the prefix table before using any other **Rtl..UnicodePrefix** routines on it. The initialized prefix table structure should be considered opaque.

Callers of the **Rtl..UnicodePrefix** routines are responsible for synchronizing access to the prefix table. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[ExInitializeFastMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializefastmutex)

[RtlFindUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlfindunicodeprefix)

[RtlInsertUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinsertunicodeprefix)

[RtlNextUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlnextunicodeprefix)

[RtlRemoveUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlremoveunicodeprefix)