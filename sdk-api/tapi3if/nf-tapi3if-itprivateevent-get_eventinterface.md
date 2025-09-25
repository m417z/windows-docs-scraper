# ITPrivateEvent::get_EventInterface

## Description

The
**get_EventInterface** method returns a pointer to the **IDispatch** interface of the private object's event handler.

## Parameters

### `pEventInterface` [out]

 Pointer to the **IDispatch** interface of the private object's event handler.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pEventInterface* parameter is not a valid pointer. |

## See also

[ITPrivateEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itprivateevent)