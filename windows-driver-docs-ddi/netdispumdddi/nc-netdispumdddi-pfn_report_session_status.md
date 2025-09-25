# PFN_REPORT_SESSION_STATUS callback function

## Description

Called by the user-mode display driver to report the status of the current Miracast connected session.The data type of this function is **PFN_REPORT_SESSION_STATUS**.

## Parameters

### `hMiracastDeviceHandle` [in]

A handle that represents a Miracast device. The Miracast user-mode driver previously obtained this handle as the *hMiracastDeviceHandle* parameter in a call to the [CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context) function.

### `MiracastStatus` [in]

The current status of the Miracast link, of type [MIRACAST_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ne-netdispumdddi-miracast_status).

### `Status` [in]

A status value the driver can provide that's logged for diagnostics purposes.

## Remarks

If the Miracast user-mode driver reports an error in the *MiracastStatus* parameter, it initiates a tear-down of the current Miracast connected session.

## See also

[CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context)

[MIRACAST_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ne-netdispumdddi-miracast_status)