## Description

A wrapper around the internal [IKsControl::KsProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-ikscontrol-ksproperty) method, which sets a property or retrieves property information, along with any other defined support operations available on a property set.

## Parameters

### `propertySet`

A GUID representing the [KSPROPERTY.Set](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure) field.

### `propertyId`

A ULONG representing the **KSPROPERTY.Id** field.

### `propertyFlags`

A set of bit-wise or-ed flags representing the **KSPROPERTY.Flags** field.

### `propertyPayload`

Extended data added to the end of the **KSPROPERTY** structure. Any property payload provided will be added to the end of the **KSPROPERTY** structure before being sent to the virtual camera’s custom media source

### `propertyPayloadLength`

The size in bytes of the buffer pointed to by *propertyPayload*.

### `data`

The byte buffer for the payload of the property.

### `dataLength`

The size in bytes of the buffer pointed to by *data*.

### `dataWritten`

An output parameter indicating the amount of data written to the data buffer. This value is only valid when *commandFlags* contains a GET or query operation.

## Return value

Returns an HRESULT value, including but not limited to the following values:

| Error code | Description |
|------------|-------------|
| S_OK | Succeeded |

## Remarks

## See also

[IKsControl::KsProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-ikscontrol-ksproperty)

[KSPROPERTY Structure](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure)