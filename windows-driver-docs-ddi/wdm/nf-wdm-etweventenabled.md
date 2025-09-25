# EtwEventEnabled function

## Description

The **EtwEventEnabled** function verifies whether an event is enabled.

## Parameters

### `RegHandle` [in]

A pointer to the event provider registration handle, which is returned by the
**EtwRegister** function if the event provider registration is successful.

### `EventDescriptor` [in]

A pointer to a constant EVENT_DESCRIPTOR.

## Return value

The **EtwEventEnabled** function returns **TRUE** if the
event is enabled and **FALSE** if the event is not enabled.

## Remarks

If logging an event requires additional computing, the **EtwEventEnabled**
function can be used to determine whether the event is going to be logged, which will minimize the overhead when
logging is disabled.

If the event descriptor is not available, use the
[EtwProviderEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwproviderenabled) function instead.

## See also

[EtwProviderEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwproviderenabled)