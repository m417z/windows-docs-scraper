# ITPrivateEvent::get_EventCode

## Description

The
**get_EventCode** method returns a pointer to a provider-specific event descriptor.

## Parameters

### `plEventCode` [out]

 Pointer to the provider-specific event descriptor.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *plEventCode* parameter is not a valid pointer. |

## See also

[ITPrivateEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itprivateevent)