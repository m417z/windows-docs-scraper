# PSET_DMA_ENGINE_STATE callback function

## Description

The *SetDmaEngineState* routine sets the state of one or more DMA engines to the Running, Stopped, Paused, or Reset state.

The function pointer type for a *SetDmaEngineState* routine is defined as follows.

## Parameters

### `_context` [in]

Specifies the context value from the **Context** member of the [HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface), [HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2), or [HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl) structure.

### `StreamState` [in]

Specifies the new stream state. Set this parameter to one of the following HDAUDIO_STREAM_STATE enumeration values:

* **PauseState** (paused)
* **ResetState** (reset)
* **RunState** (running)
* **StopState** (stopped)

In the current implementation, **PauseState** and **StopState** represent the same hardware state.

### `NumberOfHandles` [in]

Specifies the number of handles in the *handles* array. Set this parameter to a nonzero value.

### `Handles` [in]

Pointer to an array of handles to DMA engines. Specify a non-**NULL** value for this parameter.

## Return value

*SetDmaEngineState* returns STATUS_SUCCESS if the call succeeds in changing the DMA engines' states. Otherwise, the routine returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_HANDLE** | Indicates that one of the handles is invalid. |
| **STATUS_INVALID_PARAMETER** | Indicates that one of the parameter values is incorrect (invalid parameter value or bad pointer). |
| **STATUS_INVALID_DEVICE_REQUEST** | Indicates that no buffer is currently allocated for one of the DMA engines. |

## Remarks

This routine changes the state of one or more DMA engines to the state that the *streamState* parameter specifies. The routine synchronizes the state transitions of all the DMA engines that the handles in the *handles* array identify. For more information, see [Synchronizing Two or More Streams](https://learn.microsoft.com/windows-hardware/drivers/audio/synchronizing-two-or-more-streams).

Before calling this routine, set up each DMA engine in the *handles* array:

* If using the HDAUDIO_BUS_INTERFACE version of the HD Audio DDI, call [AllocateDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer) to set up the DMA engine.
* If using the HDAUDIO_BUS_INTERFACE_BDL version of the DDI, call [SetupDmaEngineWithBdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-psetup_dma_engine_with_bdl) to set up the DMA engine.

If no DMA buffer is currently allocated for any DMA engine in the *handles* array, an attempt to change the stream to any state other than Reset causes the *SetDmaEngineState* call to fail and return error code STATUS_INVALID_DEVICE_REQUEST.

The stream state cannot transition directly between Running and Reset. Instead, the stream must first pass through an intermediate state of Paused or Stopped:

* From a Running or Reset state, the stream state can change directly to either Paused or Stopped.
* From a paused or stopped state, the stream state can change directly to either Running or Reset.

A WDM audio driver calls this routine during a call to its **SetState** method. For example, see [IMiniportWaveCyclicStream::SetState](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavecyclicstream-setstate).

## See also

[AllocateDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer)

[HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface)

[HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl)

[HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2)

[IMiniportWaveCyclicStream::SetState](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavecyclicstream-setstate)

[SetupDmaEngineWithBdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-psetup_dma_engine_with_bdl)