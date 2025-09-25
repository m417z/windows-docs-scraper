# DXGK_DISPLAYDETECTCONTROLTYPE enumeration

## Description

Enumeration indicating the type of display detection action.

## Constants

### `DXGK_DDCT_UNINITIALIZED:0`

Indicates that a variable of type DXGK_DISPLAYDETECTCONTROLTYPE has not yet been assigned a meaningful value.

### `DXGK_DDCT_POLLONE`

Requests a poll of the target specified in the TargetId field. The driver should initiate polling the target if the current status is not known. If the status is not the same as the last reported status for the target, an updated status should be reported using DxgkCbIndicateConnectorChange.

### `DXGK_DDCT_POLLALL`

Request to initiate polls for all targets where the driver does not have current status before completing the call but the driver should not wait for the results of polling before returning.
As status of each target is discovered, if it is not the same as the previously updated status should be reported using DxgkCbIndicateConnectorChange.

### `DXGK_DDCT_ENABLEHPD`

Applies to all targets and requires that the driver enables new notifications and indicates any pending notifications using DxgkCbIndicateConnectorChange before completing the call. It must also initiate polls for all targets where the driver does not have current status before completing the call but it should not wait for the results of polling before returning. For the POST adapter, it is important that the display which was initialized by firmware be included in the set of displays which is reported before returning from the call made during boot so that the OS is aware of the monitor before it requests the boot functional VidPn. Since firmware has already detected and initialized the boot display and the driver has been able to query for the frame buffer state, the connection status should naturally be known by the driver and pending notification to the OS.

### `DXGK_DDCT_DISABLEHPD`

Applies to all targets and requires that the driver disables new notifications. It is understood that, this does not prevent an in-flight notification from being reported after the driver has returned.