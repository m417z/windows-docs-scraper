## Description

The **AcxCircuitTemplateCreate** function is used to create a circuit template for use by the audio class extension (ACX) manager.

## Parameters

### `Driver` [in]

A **WDFDRIVER** object, described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects), that will be associated with the circuit template.

### `Attributes` [in]

A pointer to the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure to use when creating the circuit template.

### `Config` [in]

A pointer to an [ACX_CIRCUIT_TEMPLATE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/ns-acxmanager-acx_circuit_template_config) structure to use when creating the circuit template.

### `Template` [out]

A pointer to the newly created circuit template object.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)
- [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)
- [ACX_CIRCUIT_TEMPLATE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/ns-acxmanager-acx_circuit_template_config)
- [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)
- [acxmanager.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/)