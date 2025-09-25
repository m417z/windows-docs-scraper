# PNEGOTIATE_IEEE_MODE callback

## Description

The old version of the **PNEGOTIATE_IEEE_MODE** callback function. For the latest version, see the **[PNEGOTIATE_IEEE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pnegotiate_ieee_mode-r1)** (new) callback function.

## Parameters

### `Extension` [in]

Pointer to the device extension of the parallel port device.

### `Extensibility` [in]

Specifies the IEEE 1284 extensibility mode to negotiate. This is a UCHAR value that indicates the specific parallel port communication mode to establish.

## Return value

Returns an NTSTATUS value. Possible return values include:

| Return code | Description |
|--|--|
| STATUS_SUCCESS| The IEEE mode was successfully negotiated. |
| STATUS_UNSUCCESSFUL | The mode negotiation failed. |
| STATUS_INVALID_PARAMETER | An invalid extensibility mode was specified. |
| STATUS_DEVICE_NOT_READY | The parallel port device is not ready for mode negotiation. |

## Remarks

## See also

- **[PNEGOTIATE_IEEE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pnegotiate_ieee_mode-r1)**