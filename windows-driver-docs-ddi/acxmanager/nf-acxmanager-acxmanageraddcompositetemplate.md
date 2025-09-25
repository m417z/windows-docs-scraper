## Description

The **AcxManagerAddCompositeTemplate** function adds the specified composite template to the specified **ACXMANAGER**.

## Parameters

### `Manager` [in]

The **ACXMANAGER** to which the specified *Template* is added.

### `Template` [in]

The composite template to add to the specified *Manager*.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

A composite template tells the ACX manager how to build a composite endpoint. For example, build an audio endpoint using two or more ACXCIRCUIT objects.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmanager.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/)