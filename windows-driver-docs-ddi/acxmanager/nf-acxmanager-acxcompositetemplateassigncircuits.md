## Description

The **AcxCompositeTemplateAssignCircuits** function adds an array of circuit templates to the specified composite template.

## Parameters

### `CompositeTemplate` [in]

The composite template to which the circuit templates are added.

### `CircuitTemplates` [in, reads(CircuitTemplatesCount)]

A pointer to an array of **ACXCIRCUITTEMPLATE** objects to add to the specified *CompositeTemplate*.

### `CircuitTemplatesCount` [in]

The number of **ACXCIRCUITTEMPLATE** objects in the *CircuitTemplates* array.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [AcxCircuitTemplateCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/nf-acxmanager-acxcircuittemplatecreate)
- [AcxCompositeTemplateCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/nf-acxmanager-acxcompositetemplatecreate)
- [acxmanager.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/)