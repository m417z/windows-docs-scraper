# IMXF::SetState

## Description

The SetState method is used to set the state of the MIDI transform interface.

## Parameters

### `State`

Specifies the state that the filter graph is to be set to. This parameter is a KSSTATE enumeration value. For more information, see the following Remarks section.

## Return value

This method returns NTSTATUS which contains STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

For an audio filter graph, the four KSSTATE enumeration values are interpreted as follows:

|Value | State |
|--|--|
| KSSTATE_RUN | Everything is running and functioning as normal. In this state, the IMXF interface will be active and pass messages as usual.|
| KSSTATE_ACQUIRE | This is a transitional state that helps manage the transition between KSSTATE_RUN and KSSTATE_STOP. In this state, messages cannot be passed downstream in the filter graph. |
| KSSTATE_PAUSE | This is a transitional state that helps manage the transition between KSSTATE_RUN and KSSTATE_STOP. |
| KSSTATE_STOP | Everything is stopped in the current filter graph. |

The behavior of the miniport driver depends on the state of the filter graph. This behavior differs for rendering (output) and capture (input).

On the output side, if the current state is anything other than KSSTATE_RUN, the IMXF interface should hold onto the data and not pass it to the hardware. If the current state is KSTATE_STOP then the miniport driver should discard any data it is given by passing that data to the allocator.

On the input side, if the input stream is in either KSSTATE_RUN or KSSTATE_PAUSE, it is legal for the miniport driver to get messages from the allocator and send them upstream to the capture sink. If the state is KSSTATE_STOP or KSSTATE_ACQUIRE and the hardware is trying to produce data, that data should be thrown away.

## See also

[IMXF](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-imxf)