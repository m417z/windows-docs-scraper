# ITTAPIObjectEvent::get_TAPIObject

## Description

The
**get_TAPIObject** method gets a pointer to the
[TAPI object](https://learn.microsoft.com/windows/desktop/Tapi/tapi-object) on which the event occurred.

## Parameters

### `ppTAPIObject` [out]

Pointer to an
[ITTAPI](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapi) interface of the TAPI object on which the event occurred.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppTAPIObject* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the **AddRef** method on the
[ITTAPI](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapi) interface returned by **ITTAPIObjectEvent::get_TAPIObject**. The application must call **Release** on the
**ITTAPI** interface to free resources associated with it.

## See also

[ITTAPIObjectEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapiobjectevent)

[TAPI Object](https://learn.microsoft.com/windows/desktop/Tapi/tapi-object)