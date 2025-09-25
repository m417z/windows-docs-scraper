# IMiniportWaveRTStream::SetState

## Description

The SetState method changes the transport state of the audio stream.

## Parameters

### `State` [in]

Specifies the new state of the stream. This parameter is a [KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate) enumeration value.

## Return value

SetState returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error status code.

## Remarks

For most driver implementations, KSSTATE_ACQUIRE and KSSTATE_PAUSE are indistinguishable.

Transitions always occur in one of the following two sequences:

- STOP → ACQUIRE → PAUSE → RUN

- RUN → PAUSE → ACQUIRE → STOP

The [IMiniportWaveRT::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavert-newstream) method sets the initial state of the stream to KSSTATE_STOP.

## See also

[IMiniPortWaveRTStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavertstream)

[IMiniportWaveRT::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavert-newstream)

[KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate)