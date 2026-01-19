## Description

Specifies the data type of Quantization Parameter (QP) map values.

## Constants

### `CODEC_API_QP_MAP_INT8`

QP map elements are of type **int8_t**.

### `CODEC_API_QP_MAP_INT16`

QP map elements are of type **int16_t**.

### `CODEC_API_QP_MAP_INT32`

QP map elements are of type **int32_t**.

### `CODEC_API_QP_MAP_UINT8`

QP map elements are of type **uint8_t**.

### `CODEC_API_QP_MAP_UINT16`

QP map elements are of type **uint16_t**.

### `CODEC_API_QP_MAP_UINT32`

QP map elements are of type **uint32_t**.

## Remarks

This enumeration is used by the *dataType* field of the [InputQPSettings](https://learn.microsoft.com/windows/win32/api/mfapi/ns-mfapi-inputqpsettings) structure which provides data for the [CODECAPI_AVEncVideoInputAbsoluteQPBlockSettings](https://learn.microsoft.com/windows/win32/medfound/codecapi-avencvideoinputabsoluteqpblocksettings) and [CODECAPI_AVEncVideoInputDeltaQPBlockSettings](https://learn.microsoft.com/windows/win32/medfound/codecapi-avencvideoinputdeltaqpblocksettings) properties.

## See also