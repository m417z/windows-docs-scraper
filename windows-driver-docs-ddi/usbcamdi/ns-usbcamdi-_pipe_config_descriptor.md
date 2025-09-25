## Description

The **USBCAMD_Pipe_Config_Descriptor** structure describes the association between pipes and streams.

## Members

### `StreamAssociation`

Specifies the type of stream. This should be set to one of the following values:

| Flag | Meaning |
|---|---|
| USBCAMD_VIDEO_STREAM | Indicates that the stream contains video data. |
| USBCAMD_STILL_STREAM | Indicates that the stream contains still data. |
| USBCAMD_VIDEO_STILL_STREAM | Indicates that the stream contains both video and still data. |

### `PipeConfigFlags`

Specifies the pipe characteristics. This should be set to one of the following values:

| Flag | Meaning |
|---|---|
| USBCAMD_DATA_PIPE | Indicates a video or still data pipe. |
| USBCAMD_MULTIPLEX_PIPE | Indicates a video and still data pipe. |
| USBCAMD_SYNC_PIPE | Indicates an out-of-band signaling pipe. |
| USBCAMD_DONT_CARE_PIPE | Indicates a pipe that is not to be used for video or still streaming. |

## Remarks

The camera minidriver indicates pipe stream associations by identifying all streams associated with a particular pipe. If there is more than one stream association, USBCAMD creates a virtual still pin. The still stream pin always follows the video stream pin (that is, the video stream pin is the first stream pin).

The [CamConfigureEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_configure_routine_ex) routine uses the **USBCAMD_Pipe_Config_Descriptor** structure to establish a connection between pipes and streams. An array of USBCAMD_Pipe_Config_Descriptor structures is passed into **CamConfigureEx**, along with the array size, which is equal to the number of pipes found.

The camera minidriver must set the **PipeConfigFlags** member to the value USBCAMD_DONT_CARE_PIPE if a particular pipe should not be used by USBCAMD. For example, when using an audio and video isochronous pipe, and a camera device that supports stills and video, the **PipeConfigFlags** member in the first structure should be set to USBCAMD_DONT_CARE_PIPE. The second **USBCAMD_Pipe_Config_Descriptor** structure should have its **StreamAssociation** member value set to USBCAMD_VIDEO_STILL_STREAM and its **PipeConfigFlags** member value set to USBCAMD_MULTIPLEX_PIPE.

The USBCAMD library requires that the camera must have a single configuration description, and all alternate settings within the USB video streaming interface must have the same number and type of pipes.

**USBCAMD_Pipe_Config_Descriptor** is not supported in the original USBCAMD.

## See also

[CamConfigureEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_configure_routine_ex)