# MC_VCP_CODE_TYPE enumeration

## Description

Describes a Virtual Control Panel (VCP) code type.

## Constants

### `MC_MOMENTARY`

Momentary VCP code. Sending a command of this type causes the monitor to initiate a self-timed operation and then revert to its original state. Examples include display tests and degaussing.

### `MC_SET_PARAMETER`

Set Parameter VCP code. Sending a command of this type changes some aspect of the monitor's operation.

## See also

[GetVCPFeatureAndVCPFeatureReply](https://learn.microsoft.com/windows/desktop/api/lowlevelmonitorconfigurationapi/nf-lowlevelmonitorconfigurationapi-getvcpfeatureandvcpfeaturereply)

[Monitor Configuration Enumeration Types](https://learn.microsoft.com/windows/desktop/Monitor/monitor-configuration-enumeration-types)

[SetMonitorDisplayAreaSize](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-setmonitordisplayareasize)