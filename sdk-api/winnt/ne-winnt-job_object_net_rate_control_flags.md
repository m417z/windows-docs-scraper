# JOB_OBJECT_NET_RATE_CONTROL_FLAGS enumeration

## Description

Specifies types of scheduling policies for network rate control.

## Constants

### `JOB_OBJECT_NET_RATE_CONTROL_ENABLE:0x1`

Turns on the control of the network traffic. You must set this value if you also set either **JOB_OBJECT_NET_RATE_CONTROL_MAX_BANDWIDTH** or **JOB_OBJECT_NET_RATE_CONTROL_DSCP_TAG**.

### `JOB_OBJECT_NET_RATE_CONTROL_MAX_BANDWIDTH:0x2`

### `JOB_OBJECT_NET_RATE_CONTROL_DSCP_TAG:0x4`

Sets the DSCP field in the packet header to the value of the **DscpTag** member of the [JOBOBJECT_NET_RATE_CONTROL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_net_rate_control_information) structure. For information about DSCP, see [Differentiated Services](https://learn.microsoft.com/previous-versions/windows/desktop/qos/differentiated-services).

### `JOB_OBJECT_NET_RATE_CONTROL_VALID_FLAGS:=`

The combination of all of the valid flags for the [JOB_OBJECT_NET_RATE_CONTROL_FLAGS](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-job_object_net_rate_control_flags) enumeration.

#### - JOB_OBJECT_NET_RATE_CONTROL_MAX_BANDWITH

Uses the value of the **MaxBandwidth** member of the [JOBOBJECT_NET_RATE_CONTROL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_net_rate_control_information) structure to set the maximum bandwidth for outgoing network traffic for the job, in bytes.

## See also

[JOBOBJECT_NET_RATE_CONTROL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_net_rate_control_information)