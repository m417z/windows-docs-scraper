# QOS_SET_FLOW enumeration

## Description

The **QOS_SET_FLOW** enumeration indicates what is being changed about a flow.

## Constants

### `QOSSetTrafficType:0`

Indicates that the traffic type of the flow will change.

### `QOSSetOutgoingRate:1`

Indicates that the flow rate will change.

### `QOSSetOutgoingDSCPValue:2`

Windows 7, Windows Server 2008 R2, and later: Indicates that the outgoing DSCP value will change.

**Note** This setting requires the calling application be a member of the Administrators or the Network Configuration Operators group.

## See also

[QOSSetFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qossetflow)

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)