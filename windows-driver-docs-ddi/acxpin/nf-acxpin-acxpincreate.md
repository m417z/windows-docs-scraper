## Description

The **AcxPinCreate** function creates and initializes a new [ACXPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/) object.

## Parameters

### `Circuit` [in]

The [ACXCIRCUIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/) to which the new pin is added.

### `Attributes` [in]

Pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure for configuration of the pin.

### `Config` [in]

Pointer to an [ACX_PIN_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_pin_config) structure for configuration of the pin.

### `Pin` [out]

The newly created and initialized **ACXPIN** object.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACXPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)
- [ACXCIRCUIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)
- [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)
- [ACX_PIN_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_pin_config)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)