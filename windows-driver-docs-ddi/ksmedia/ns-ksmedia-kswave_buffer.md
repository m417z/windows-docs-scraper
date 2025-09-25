## Description

The **KSWAVE_BUFFER** structure is used to describe a sample buffer.

## Members

### `Attributes`

Specifies the following flags:

| Flag | Meaning |
|---|---|
| KSWAVE_BUFFER_ATTRIBUTEF_LOOPING | Indicates that the buffer loops. |
| KSWAVE_BUFFER_ATTRIBUTEF_STATIC | Indicates that the buffer is static. |

### `BufferSize`

Specifies the size of the buffer, in bytes.

### `BufferAddress`

Specifies the starting address of the buffer.

## Remarks

This structure is used by the [KSPROPERTY_WAVE_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-wave-buffer) property.

## See also

[KSPROPERTY_WAVE_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-wave-buffer)