# MmDoesFileHaveUserWritableReferences function

## Description

The **MmDoesFileHaveUserWritableReferences** function determines whether a file associated with a transaction has any user-mapped sections present.

## Parameters

### `SectionPointer` [in]

Pointer to a [**SECTION_OBJECT_POINTERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_section_object_pointers) structure that contains the file object's section object pointers. This parameter is required and can't be **NULL**.

## Return value

**MmDoesFileHaveUserWritableReferences** returns one of the following values.

| Return value | Meaning |
|--------------|---------|
| 0 | The file object has no user-mapped sections. It's safe to proceed with the transaction. |
| 1 | The file object has user-mapped sections. The transaction must be rolled back. |

## Remarks

For transactional file systems, you can use this function to determine if a given transaction is referencing a file object that can change. If so, the transaction must be rolled back because [atomicity](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-kernel-transaction-manager) can't be guaranteed.

Prior to calling **MmDoesFileHaveUserWritableReferences**, transactional file systems must check and intercept the creation of file objects that specify write access. Specifically, prior to starting a transaction, transactional file systems must ensure that there are no writable file objects that currently exist for the given file in the transaction. While the transaction is ongoing, transactional file systems must fail the requests to create file objects with write access for the transacted files.

This function can be used to detect if there are writable views for a file object even when all file handles and section handles for the file object have been closed.

For more information about transactions, see [Kernel Transaction Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-ktm).

For more information about file objects, see [**FILE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object).

## See also

[**FILE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)

[**SECTION_OBJECT_POINTERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_section_object_pointers)