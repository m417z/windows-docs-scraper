# ITDigitsGatheredEvent::get_Digits

## Description

The
**get_Digits** method gets the gathered digits for the call.

## Parameters

### `ppDigits` [out]

Pointer to a **BSTR** where the gathered digits are stored.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppDigits* parameter is not a valid pointer. |

## See also

[ITDigitsGatheredEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdigitsgatheredevent)