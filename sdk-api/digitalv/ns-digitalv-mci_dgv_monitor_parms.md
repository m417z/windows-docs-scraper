# MCI_DGV_MONITOR_PARMS structure

## Description

The **MCI_DGV_MONITOR_PARMS** structure contains parameters for the [MCI_MONITOR](https://learn.microsoft.com/windows/desktop/Multimedia/mci-monitor) command.

## Members

### `dwCallback`

The low-order word specifies a window handle used for the MCI_NOTIFY flag.

### `dwSource`

One of the following flags for the monitor source:

| Name | Description |
| --- | --- |
| **MCI_DGV_MONITOR_FILE** | The workspace is the presentation source. (This is the default source.) If this flag is used during recording, the recording pauses. If the [MCI_MONITOR](https://learn.microsoft.com/windows/desktop/Multimedia/mci-monitor) command changes the presentation source, recording or playing stops and the current position is the value returned by the [MCI_STATUS](https://learn.microsoft.com/windows/desktop/Multimedia/mci-status) command for the start position. |
| **MCI_DGV_MONITOR_INPUT** | The external input is the presentation source. Playback is paused before the input is selected. If the [MCI_SETVIDEO](https://learn.microsoft.com/windows/desktop/Multimedia/mci-setvideo) command has been enabled using the MCI_SET_ON flag, this flag displays a default hidden window. Device drivers might limit what other device instances can do while monitoring input. |

### `dwMethod`

One of the following constants for the type of monitoring:

| Name | Description |
| --- | --- |
| **MCI_DGV_METHOD_DIRECT** | The device should be configured for optimum display quality during monitoring. Direct monitoring might be incompatible with motion-video recording. |
| **MCI_DGV_METHOD_POST** | The device should show the external input after compression. Post monitoring supports motion-video recording. |
| **MCI_DGV_METHOD_PRE** | The device should show the external input prior to compression. |

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85)) function to validate the members.

## See also

[MCI](https://learn.microsoft.com/windows/desktop/Multimedia/mci)

[MCI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/mci-structures)

[MCI_MONITOR](https://learn.microsoft.com/windows/desktop/Multimedia/mci-monitor)

[MCI_SETVIDEO](https://learn.microsoft.com/windows/desktop/Multimedia/mci-setvideo)

[MCI_STATUS](https://learn.microsoft.com/windows/desktop/Multimedia/mci-status)

[mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85))