## Description

The **ACX_STREAM_CALLBACKS** structure identifies the driver callbacks for streaming to the ACX framework. This structure is a part of the [ACX_PIN_CONFIG structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_pin_config).

## Members

### `Size`

The length, in bytes, of this structure.

### `EvtAcxStreamPrepareHardware`

The [EVT_ACX_STREAM_PREPARE_HARDWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_prepare_hardware) Callback.

### `EvtAcxStreamReleaseHardware`

The [EVT_ACX_STREAM_RELEASE_HARDWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_release_hardware) Callback.

### `EvtAcxStreamRun`

The [EVT_ACX_STREAM_RUN](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_run) Callback.

### `EvtAcxStreamPause`

The [EVT_ACX_STREAM_PAUSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_pause) Callback.

### `EvtAcxStreamAssignDrmContentId`

The [EVT_ACX_STREAM_ASSIGN_DRM_CONTENT_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_assign_drm_content_id) Callback.

## Remarks

For RT streaming, the driver will also define and use the [ACX_RT_STREAM_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acx_rt_stream_callbacks).

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)
- [AcxStreamInitAssignAcxStreamCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nf-acxstreams-acxstreaminitassignacxstreamcallbacks)