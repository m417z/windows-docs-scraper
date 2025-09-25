# RtlInsertUnicodePrefix function

## Description

The **RtlInsertUnicodePrefix** routine inserts a new element into a Unicode prefix table.

## Parameters

### `PrefixTable` [in]

Pointer to the prefix table. The table must have been initialized by calling [RtlInitializeUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinitializeunicodeprefix).

### `Prefix` [in]

Pointer to the name string to be inserted with the element at *PrefixTableEntry*.

### `PrefixTableEntry` [out]

Pointer to caller-allocated storage, which must be at least **sizeof**(UNICODE_PREFIX_TABLE_ENTRY), for the element to be inserted for the new prefix. **RtlInsertUnicodePrefix** initializes this element, which should be considered opaque by the caller.

## Return value

**RtlInsertUnicodePrefix** returns **TRUE** if the new element was inserted in the prefix table, or it returns **FALSE** if a duplicate element already exists in the prefix table.

## Remarks

Each prefix entry in the table is a pathname relative to the root directory of a file system volume. To be well-formed, the prefix must begin with a single backslash (\).

After inserting the new element, **RtlInsertUnicodePrefix** rebalances the prefix table's splay tree.

File systems must call [RtlInitializeUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinitializeunicodeprefix) to initialize the prefix table before using any other **Rtl..UnicodePrefix** routines on it. The initialized prefix table structure should be considered opaque.

Callers of the **Rtl..UnicodePrefix** routines are responsible for synchronizing access to the prefix table. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[RtlFindUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlfindunicodeprefix)

[RtlInitializeUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinitializeunicodeprefix)

[RtlNextUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlnextunicodeprefix)

[RtlRemoveUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlremoveunicodeprefix)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)