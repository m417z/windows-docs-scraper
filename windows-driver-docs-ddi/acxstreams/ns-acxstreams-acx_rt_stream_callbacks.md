## Description

The **ACX_RT_STREAM_CALLBACKS** structure defines callbacks for RT streaming to the ACX framework.

## Members

### `Size`

The length, in bytes, of this structure.

### `EvtAcxStreamGetHwLatency`

The [EvtAcxStreamGetHwLatency](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_get_hw_latency) callback.

### `EvtAcxStreamAllocateRtPackets`

The [EvtAcxStreamAllocateRtPackets](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_allocate_rtpackets) callback.

### `EvtAcxStreamFreeRtPackets`

The [EvtAcxStreamFreeRtPackets](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_free_rtpackets) callback.

### `EvtAcxStreamSetRenderPacket`

The [EvtAcxStreamSetRenderPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_set_render_packet) callback.

### `EvtAcxStreamGetCurrentPacket`

The [EvtAcxStreamGetCurrentPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_get_current_packet) callback.

### `EvtAcxStreamGetCapturePacket`

The [EvtAcxStreamGetCapturePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_get_capture_packet) callback.

### `EvtAcxStreamGetPresentationPosition`

The [EvtAcxStreamGetPresentationPosition](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_get_presentation_position) callback.

## Remarks

The driver must also define and use the [ACX_STREAM_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acx_stream_callbacks) structure to create an ACXRTSTREAM.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)
- [AcxStreamInitAssignAcxRtStreamCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nf-acxstreams-acxstreaminitassignacxrtstreamcallbacks)