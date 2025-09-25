# ITACDGroupEvent::get_Event

## Description

The
**get_Event** method gets the descriptor of an event which indicates that a new ACD group has been added.

## Parameters

### `pEvent` [out]

Pointer to
[ACDGROUP_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-acdgroup_event) descriptor of event.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pEvent* parameter is not a valid pointer. |

## Remarks

The ACDGE_NEW_GROUP and ACDGE_REMOVE_GROUP values are not currently supported.

## See also

[ACDGROUP_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-acdgroup_event)

[ITACDGroupEvent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroupevent)