# QOS_TRAFFIC_TYPE enumeration

## Description

The **QOS_TRAFFIC_TYPE** enumeration defines the various traffic types. Each flow has a single traffic type. This allows the QOS subsystem to apply user-specified policies to each type.

## Constants

### `QOSTrafficTypeBestEffort:0`

Flow traffic has the same network priority as regular traffic not associated with QOS.

This traffic type is the same as not specifying priority, and as a result, the DSCP mark and 802.1p tag are not added to sent traffic.

### `QOSTrafficTypeBackground:1`

Flow traffic has a network priority lower than that of **QOSTrafficTypeBestEffort**. This traffic type could be used for traffic of an application doing data backup.

Sent traffic will contain a DSCP mark with a value of 0x08 and an 802.1p tag with a value of 2.

### `QOSTrafficTypeExcellentEffort:2`

Flow traffic has a network priority higher than **QOSTrafficTypeBestEffort**, yet lower than **QOSTrafficTypeAudioVideo**. This traffic type should be used for data traffic that is more important than normal end-user scenarios, such as email.

Sent traffic will contain a DSCP mark with value of 0x28 and 802.1p tag with a value of 5.

### `QOSTrafficTypeAudioVideo:3`

Flow traffic has a network priority higher than **QOSTrafficTypeExcellentEffort**, yet lower than **QOSTrafficTypeVoice**. This traffic type should be used for A/V streaming scenarios such as MPEG2 streaming.

Sent traffic will contain a DSCP mark with a value of 0x28 and an 802.1p tag with a value of 5.

### `QOSTrafficTypeVoice:4`

Flow traffic has a network priority higher than **QOSTrafficTypeAudioVideo**, yet lower than **QOSTrafficTypeControl**. This traffic type should be used for realtime voice streams such as VOIP.

Sent traffic will contain a DSCP mark with a value of 0x38 and an 802.1p tag with a value of 7.

### `QOSTrafficTypeControl:5`

Flow traffic has the highest network priority. This traffic type should only be used for the most critical of data. For example, it may be used for data carrying user inputs.

Sent traffic will contain a DSCP mark with a value of 0x38 and an 802.1p tag with a value of 7.

## Remarks

802.1p tags are added to sent traffic only when the following conditions are met:

* [QOSAddSocketToFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosaddsockettoflow) is called without the QOS_NON_ADAPTIVE_FLOW flag
* The destination host is on the local link and not across a router
* The qWAVE subsystem has determined that 802.1p tagged packets are not discarded by a network element on the end-to-end path

## See also

[QOSAddSocketToFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosaddsockettoflow)

[QOSSetFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qossetflow)

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)