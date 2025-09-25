# _DXVAHDDDI_STREAM_STATE_PRIVATE_IVTC_DATA structure

## Description

The DXVAHDDDI_STREAM_STATE_PRIVATE_IVTC_DATA structure describes private stream-state data that is used to query the inverse telecine statistics from the driver.

## Members

### `Enable` [in/out]

A Boolean value that indicates whether to capture the statistics is enabled. By enabling the capture of statistics, the driver resets all the statistics data to zero. The default value is **FALSE**, which indicates that capturing the statistics is disabled.

### `ITelecineFlags` [out]

One of the following DXVAHDDDI_ITELECINE_CAPS enumeration values that indicates the telecine type that the driver detected while reversing the telecined frames.

| **Value** | **Meaning** |
|:--|:--|
| DXVAHDDDI_ITELECINE_CAPS_32 (0x1) | The driver can perform reverse 3:2 telecine, NTSC(60i) -> Film(24p). |
| DXVAHDDDI_ITELECINE_CAPS_22 (0x2) | The driver can perform reverse 2:2 telecine, PAL(50i) -> Film(25p:4% faster) and NTSC(60i) -> CG(30p). |
| DXVAHDDDI_ITELECINE_CAPS_2224 (0x4) | The driver can perform reverse 2:2:2:4 telecine, NTSC(60i) -> DVCAM(24p). |
| DXVAHDDDI_ITELECINE_CAPS_2332 (0x8) | The driver can perform reverse 2:3:3:2 telecine, NTSC(60i) -> DVCAM(24p). |
| DXVAHDDDI_ITELECINE_CAPS_32322 (0x10) | The driver can perform reverse 3:2:3:2:2 telecine, NTSC(60i) -> Film(25p:4% faster). |
| DXVAHDDDI_ITELECINE_CAPS_55 (0x20) | The driver can perform reverse 5:5 telecine, NTSC(60i) -> Animation(12p). |
| DXVAHDDDI_ITELECINE_CAPS_64 (0x40) | The driver can perform reverse 6:4 telecine, NTSC(60i) -> Animation(12p). |
| DXVAHDDDI_ITELECINE_CAPS_87 (0x80) | The driver can perform reverse 8:7 telecine, NTSC(60i) -> Anime(8p). |
| DXVAHDDDI_ITELECINE_CAPS_222222222223 (0x100) | The driver can perform reverse 2:2:2:2:2:2:2:2:2:2:2:3 telecine, PAL(50i) -> Film(24p). |
| DXVAHDDDI_ITELECINE_CAPS_OTHER (0x80000000) | The driver can perform reverse non-standard telecine. |

### `Frames` [out]

The number of consecutive frames that the driver detects for the telecined frames.

### `InputField` [out]

The last field number of the input stream that was processed (so far). The driver updates this member after the driver has processed the input field that is specified in the **InputFrameOrField** member of the [DXVAHDDDI_STREAM_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_data) structure.

## Remarks

The DXVAHDDDI_STREAM_STATE_PRIVATE_IVTC GUID is set in the **Guid** member of the [DXVAHDDDI_STREAM_STATE_PRIVATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_private_data) structure when the driver's [GetVideoProcessStreamStatePrivate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_getvideoprocessstreamstateprivate) function is called to query the inverse telecine statistics from the driver.

When an application de-interlaces an interlaced stream, the driver might inverse the telecined frames. If the driver supports inverse telecine statistics, the application can query the statistics data.

The playback application can dynamically switch the frame rate converter as described in the following scenario:

* The application enables the inverse telecine statistics.
* The application begins to de-interlace the interlaced fields to the progressive frames.
* At some point, the application queries the statistics and determines the streams are telecined frames.
* The application enables the custom frame rate in order to output the frames at the original content frame rate (for example, 60i -> 24p).

The application continues to query the statistics to determine if the frames are changed (for example, progressive or interlaced).

## See also

[DXVAHDDDI_STREAM_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_data)