## Description

The **StorPortGetDeviceBase2** function is like **[StorPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdevicebase)**, but the *Flags* parameter allows for additional optional behavior. Rather than returning a mapped base address, a status is returned and the caller provides a pointer to store the mapping.

## Parameters

### `HwDeviceExtension`

Used to find port device extension.

### `BusType`

Specifies the type of bus, such as EISA, MCA, or ISA.

### `SystemIoBusNumber`

Specifies the IO bus for machines with multiple buses.

### `Address`

The base device address to be mapped.

### `NumberOfBytes`

The number of bytes for which *Address* is valid.

### `InIoSpace`

Indicates an IO address.

### `Flags`

Used to request different attributes when mapping *BaseAddress*. If *Flags* is zero, the mapping is non-cached read/write.

### `BaseAddress`

A pointer to store the base address mapping in.

## Return value

Returns a STOR_STATUS_xxx code.

| Return code | Description |
|--|--|
| STOR_STATUS_SUCCESS | The extended function was successfully returned. |
| STOR_STATUS_INVALID_PARAMETER | One of the *Flags* parameters is invalid. |
| STOR_STATUS_NOT_IMPLEMENTED | The specified extended function is not implemented. |

## Remarks

## See also

- **[StorPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdevicebase)**