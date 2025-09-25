# ITDigitsGatheredEvent::get_GatherTermination

## Description

The
**get_GatherTermination** method gets the reason why the TAPI Server terminated the gathering of digits on the call.

## Parameters

### `pGatherTermination` [out]

Pointer to a value from the
[TAPI_GATHERTERM](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-tapi_gatherterm) enumeration.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pGatherTermination* parameter is not a valid pointer. |

## See also

[ITDigitsGatheredEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdigitsgatheredevent)