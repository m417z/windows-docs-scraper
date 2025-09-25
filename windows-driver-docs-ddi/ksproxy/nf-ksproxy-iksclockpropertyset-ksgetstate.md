## Description

The **KsGetState** method retrieves the streaming state of a pin from the underlying clock.

## Parameters

### `State` [out]

Pointer to a variable that receives a value that specifies the streaming state of a pin. This value can be one of the following values from the [**KSSTATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate) enumerated type:

| Value | Description |
|---|---|
| KSSTATE_STOP | The streaming of data to or from the pin is stopped. Represents the initial state of the pin with the least resource usage and the most latency to obtain a **KSSTATE_RUN** state. |
| KSSTATE_ACQUIRE | Represents the state at which allocators are negotiated and resources acquired, though no data may be buffered in this state. |
| KSSTATE_PAUSE | The clock is waiting and is prepared to instantly change to the **KSSTATE_RUN** state. Represents the mode of most resource usage and least latency to a Run state, without actually being in a **KSSTATE_RUN** state. Data can be buffered in this state. If the state of the pin is queried and that state is currently paused, the pin can return an error of STATUS_NO_DATA_DETECTED to indicate that this pin does not perform queuing of data when in a paused state. |
| KSSTATE_RUN | The pin is streaming data. That is, the pin consumes or produces stream data. |

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The state of the pin gives gross motor control for pins. Fine motor control is done on a class-by-class basis with custom properties. For instance, in order to make an external laser disc player spin up, you could set a custom Mode property specific to that class. Setting this property may also change the state of the device, though not necessarily, depending on the effect of the mode.

A filter itself can support this state property so that applications can set the entire filter's state. Otherwise, each pin must have its state set. When the state of a pin transitions from KSSTATE_STOP, each connection that forwards IRPs must recalculate stack depth.

The proxy uses the KSPROPERTY_CLOCK_STATE property to retrieve the streaming state of a pin.