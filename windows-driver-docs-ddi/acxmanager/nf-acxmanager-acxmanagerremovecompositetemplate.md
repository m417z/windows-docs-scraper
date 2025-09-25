## Description

The **AcxManagerRemoveCompositeTemplate** function removes the specified composite template from the specified **ACXMANAGER**.

## Parameters

### `Manager` [in]

The **ACXMANAGER** from which the specified *Template* is removed.

### `Template` [in]

The composite template to remove from the specified *Manager*.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

When a composite template is removed, all endpoints associated with that composite template are also stopped and removed.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmanager.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/)