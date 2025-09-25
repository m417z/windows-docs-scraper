# QOS_FLOWRATE_REASON enumeration

## Description

The **QOS_FLOWRATE_REASON** enumeration indicates the reason for a change in a flow's bandwidth.

## Constants

### `QOSFlowRateNotApplicable:0`

Indicates that there has not been a change in the flow.

### `QOSFlowRateContentChange:1`

Indicates that the content of a flow has changed.

### `QOSFlowRateCongestion:2`

Indicates that the flow has changed due to congestion.

### `QOSFlowRateHigherContentEncoding:3`

### `QOSFlowRateUserCaused:4`

Indicates that the user has caused the flow to change.

## See also

[QOSQueryFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosqueryflow)

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)