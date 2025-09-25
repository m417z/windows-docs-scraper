## Description

The **AcxJackCreate** function creates and initializes a new audio jack object.

## Parameters

### `AcxPin` [in]

The pin object associated with the jack.

### `Attributes` [in]

A pointer to the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure to use when creating the jack.

### `Config` [in]

A pointer to an [ACX_JACK_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_jack_config) structure to use when creating the jack.

### `Jack` [out]

A pointer to the newly created jack object.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_JACK_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_jack_config)
- [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)