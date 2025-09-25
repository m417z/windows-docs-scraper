# RtlNextUnicodePrefix function

## Description

The **RtlNextUnicodePrefix** routine is used to enumerate the elements in a Unicode prefix table.

## Parameters

### `PrefixTable` [in]

Pointer to the prefix table. The table must have been initialized by calling [RtlInitializeUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinitializeunicodeprefix).

### `Restart` [in]

Set to **TRUE** if the enumeration is to start at the first element in the table. Set to **FALSE** if resuming the enumeration from a previous call.

To enumerate all elements in the table, use **RtlNextUnicodePrefix** as follows:

```
for (p = RtlNextUnicodePrefix ( Table, TRUE );
     p != NULL;
     p = RtlNextUnicodePrefix ( Table, FALSE )) {
        // Process the element pointed to by p
}
```

## Return value

**RtlNextUnicodePrefix** returns a pointer to the next element, if one exists. If there are no more elements in the table, **RtlNextUnicodePrefix** returns **NULL**.

## Remarks

File systems must call [RtlInitializeUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinitializeunicodeprefix) to initialize the prefix table before using any other **Rtl..UnicodePrefix** routines on it. The initialized prefix table structure should be considered opaque.

Callers of the **Rtl..UnicodePrefix** routines are responsible for synchronizing access to the prefix table. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[RtlFindUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlfindunicodeprefix)

[RtlInitializeUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinitializeunicodeprefix)

[RtlInsertUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinsertunicodeprefix)

[RtlRemoveUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlremoveunicodeprefix)