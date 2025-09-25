# EPcMiniportEngineEvent enumeration

## Description

This topic introduces the EPcMiniportEngineEvent enum, and describes the parameters that provide additional information when the miniport driver reports a glitching error.

The event IDs in the following enum represent events that the miniport driver can report, by using callbacks via the port class driver (PortCls).

## Constants

### `eMINIPORT_IHV_DEFINED`

Specifies the ID for an IHV-defined event.

### `eMINIPORT_BUFFER_COMPLETE`

Specifies the ID for the buffer complete event.

### `eMINIPORT_PIN_STATE`

Specifies the ID for the event related to a change in pin state.

### `eMINIPORT_GET_STREAM_POSITION`

Specifies the ID for a "get stream position" event.

### `eMINIPORT_SET_WAVERT_BUFFER_WRITE_POSITION`

Specifies the ID for a "wave buffer write position" event.

### `eMINIPORT_GET_PRESENTATION_POSITION`

Specifies the ID for a "get presentation position" event.

### `eMINIPORT_PROGRAM_DMA`

Specifies the ID for a "program DMA" event.

### `eMINIPORT_GLITCH_REPORT`

Specifies the ID for a "glitch report" event.

### `eMINIPORT_LAST_BUFFER_RENDERED`

Specifies the ID for the last buffer that was rendered.

### `eMINIPORT_PROCESSING_MODE`

Specifies the ID for the processing mode that was in effect when the glitch happened.

### `eMINIPORT_FX_CLSID`

Specifies the class ID for the audio processing effect (FX) that was in effect when the glitch happened.

### `eMINIPORT_MaxValue`

Specifies the ID for the highest enumerated value that was used to report the glitch.

## Remarks

The following table shows the members of the EPcMiniportEngineEvent enum that were introduced with Windows 8. The table shows the events associated with the enum's members, and the meanings of their parameters.

| Event type | Parameter 1 | Parameter 2 | Parameter 3 | Parameter 4 |
| --- | --- | --- | --- | --- |
| IHV-specific event type. | Defined and used by IHVs. | Defined and used by IHVs. | Defined and used by IHVs. | Defined and used by IHVs. |
| Buffer complete. | Current linear buffer position. | Current WaveRTBuffer write position. | Data length completed. | 0 |
| Pin state. | Current linear buffer position. | Current WaveRTBuffer write position. | 0 - KS_STOP<br><br>1 - KS_ACQUIRE<br><br>2 - KS_PAUSE<br><br>3 - KS_RUN | 0 |
| Get stream position. | Current linear buffer position. | Current WaveRTBuffer write position. | 0 | 0 |
| Set WaveRT buffer write position. | Current linear buffer position. | Current WaveRTBuffer write position that was received from PortCls. | Target WaveRTBuffer write position that was received from PortCls. | 0 |
| Get presentation position. | Current linear buffer position. | Current WaveRTBuffer write position. | Presentation position. | 0 |
| Program DMA. | Current linear buffer position. | Current WaveRTBuffer write position. | Starting WaveRtBuffer offset | Data length. |
| Glitch detection. | Current linear buffer position. | Current WaveRTBuffer write position. | 1 - WaveRT buffer under run<br><br>2 - Decoder errors<br><br>3 - Receive the same WaveRT buffer write position twice in a row. | When Parameter 3 = '3' then Parameter 4 is the offending write position. |

The following table shows the members of the EPcMiniportEngineEvent enum that were introduced with Windows 8.1. The table shows the events associated with the enum's members, and the meanings of their parameters.

| Event type | Parameter 1 | Parameter 2 | Parameter 3 | Parameter 4 |
| --- | --- | --- | --- | --- |
| Last buffer rendered. | Current linear buffer position. | The very last WaveRtBuffer write position that the driver received. | 0 | 0 |
| Processing mode. | Current linear buffer position. | Current WaveRTBuffer write position. | First 8 bytes of GUID. | Second 8 bytes of GUID. |
| FX class ID. | Current linear buffer position. | Current WaveRTBuffer write position. | First 8 bytes of FX CLSID. | Second 8 bytes of FX CLSID. |
| Max value. | ID for enumerated value. | 0 | 0 | 0 |

## See also

[Glitch Reporting for Offloaded Audio](https://learn.microsoft.com/windows-hardware/drivers/audio/glitch-reporting-for-offloaded-audio)

[MiniportWriteEtwEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportclsetwhelper-miniportwriteetwevent)