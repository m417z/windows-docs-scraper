# IMiniportMidiStream::SetState

## Description

The `SetState` method sets the stream's transport state to a new state value.

## Parameters

### `State` [in]

Specifies the new state that the stream is to be set to. This parameter is a [KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate) enumeration value. For more information, see the following Remarks section.

## Return value

`SetState` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

For an audio filter graph, the four [KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate) enumeration values are interpreted as follows:

* KSSTATE_RUN

  Data transport in the current audio filter graph is running and functioning as normal.
* KSSTATE_ACQUIRE

  This is a transitional state that helps to manage the transition between KSSTATE_RUN and KSSTATE_STOP.
* KSSTATE_PAUSE

  This is a transitional state that helps to manage the transition between KSSTATE_RUN and KSSTATE_STOP.
* KSSTATE_STOP

  Data transport is stopped in the current audio filter graph.

For most miniport drivers, KSSTATE_ACQUIRE and KSSTATE_PAUSE are indistinguishable. The [IMiniportMidi::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportmidi-newstream) method sets the initial state of the stream to KSSTATE_STOP.

Transitions always occur in one of the following two sequences:

* STOP -> ACQUIRE -> PAUSE -> RUN
* RUN -> PAUSE -> ACQUIRE -> STOP

## See also

[IMiniportMidi::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportmidi-newstream)

[IMiniportMidiStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportmidistream)

[KSPROPERTY_CONNECTION_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-connection-state)

[KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate)