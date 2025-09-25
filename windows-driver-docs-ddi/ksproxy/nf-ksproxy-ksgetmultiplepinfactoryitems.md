# KsGetMultiplePinFactoryItems function

## Description

The **KsGetMultiplePinFactoryItems** function retrieves pin property items in a variable length data buffer.

## Parameters

### `FilterHandle` [in]

Handle to the filter that contains the pin factory to query.

### `PinFactoryId` [in]

Identifier of the pin factory against which the property items are being returned.

### `PropertyId` [in]

Identifier of the property in the pin property set ([KSPROPSETID_Pin](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-pin)) to query.

### `Items` [out]

Pointer to a buffer to receive the property items. If successfully retrieved, this pointer must be subsequently deleted with the **CoTaskMemFree** function.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The **KsGetMultiplePinFactoryItems** function queries for the data size, in bytes, of the requested property, allocates a buffer, and retrieves the data.

For more information about **CoTaskMemFree**, see the Microsoft Windows SDK documentation.

## See also

[IKsPinFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikspinfactory)

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPSETID_Pin](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-pin)

[KSP_PIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksp_pin)