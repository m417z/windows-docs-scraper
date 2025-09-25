# ITDigitGenerationEvent::get_GenerationTermination

## Description

The
**get_GenerationTermination** method gets the digit or digits that indicate the end of the generated digit series.

## Parameters

### `plGenerationTermination` [out]

Pointer to digit or digits that indicate the end of the generated digit series.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plGenerationTermination* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITDigitGenerationEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdigitgenerationevent)