## Description

The **AcxCompositeTemplateSetCoreCircuit** function sets the core circuit template for the specified composite template.

## Parameters

### `CompositeTemplate` [in]

The composite template on which to set the core circuit template.

### `CircuitTemplates` [in]

The circuit template to set as the core on the specified *CompositeTemplate*. This parameter is mistakenly named in the plural. It actually represents the single core circuit template.

## Remarks

The core circuit gives the identity to the composite endpoint. If this circuit is not present, ACX manager doesn't start the endpoint building process.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmanager.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/)