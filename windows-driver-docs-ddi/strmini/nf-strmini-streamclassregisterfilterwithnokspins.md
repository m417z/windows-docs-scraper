# StreamClassRegisterFilterWithNoKSPins function

## Description

The **StreamClassRegisterFilterWithNoKSPins** routine is used to register filter drivers with Microsoft DirectShow that have no kernel streaming pins and, therefore, do not stream in kernel mode.

## Parameters

### `DeviceObject` [in]

Points to the driver's device object.

### `InterfaceClassGUID` [in]

Specifies the interface class GUID to register.

### `PinCount` [in]

Specifies the number of pins on the filter.

### `PinDirection` [in]

Specifies a *PinCount*-sized array of Boolean values, one for each pin on the filter. The values indicate the pin direction for each pin. If **TRUE**, this pin is an output pin. If **FALSE**, the pin is an input pin.

### `MediumList` [in]

Specifies a *PinCount*-sized array of [KSPIN_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-medium-structure) structures, one for each pin on the filter.

### `CategoryList` [in, optional]

If non-NULL, specifies an array of pin category GUIDs, one for each pin on the filter.

## Return value

Returns STATUS_SUCCESS on success, or the appropriate error code on failure.

## See also

[KSPIN_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-medium-structure)