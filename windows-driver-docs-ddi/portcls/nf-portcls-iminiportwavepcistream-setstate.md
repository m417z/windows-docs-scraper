# IMiniportWavePciStream::SetState

## Description

The `SetState` method changes the state of the stream transport.

## Parameters

### `State` [in]

Specifies the new state of the stream. This parameter is a [KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate) enumeration value. For more information, see the following Remarks section.

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

For most miniports, KSSTATE_ACQUIRE and KSSTATE_PAUSE are indistinguishable.

Transitions always occur in one of the following two sequences:

* STOP -> ACQUIRE -> PAUSE -> RUN
* RUN -> PAUSE -> ACQUIRE -> STOP

The [IMiniportWavePci::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepci-newstream) method sets the initial state of the stream to KSSTATE_STOP.

## See also

[IMiniportWavePci::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepci-newstream)

[IMiniportWavePciStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavepcistream)

[KSPROPERTY_CONNECTION_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-connection-state)

[KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate)