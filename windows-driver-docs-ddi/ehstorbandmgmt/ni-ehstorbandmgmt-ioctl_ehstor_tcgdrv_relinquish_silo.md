# IOCTL_EHSTOR_TCGDRV_RELINQUISH_SILO IOCTL

## Description

The **IOCTL_EHSTOR_TCGDRV_RELINQUISH_SILO** request relinquishes control of band management by the Trusted Computing Group (TCG) Storage Silo driver. Applications issue this request to manage a storage silo directly. The band management functionality and API provided by the TCG Storage Silo driver are disabled.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

On return, the **Status** field will contain STATUS_SUCCESS if the operation was successful. Otherwise, another appropriate status code is returned.

## Remarks

When the TCG Storage Silo driver relinquishes control, all band management IOCTLs registered by an  [IOCTL_EHSTOR_DRIVER_REPORT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_driver_report_capabilities) request are unregistered. Any band management IOCTL requests received are returned with STATUS_INVALID_DEVICE_REQUEST.

After relinquishing control, the TCG Storage Silo driver can regain control of a storage device when the device is stopped and restarted.

To prevent the TCG Storage Silo driver from reconfiguring the TCG subsystem in a mode compatible with Windows after restart, the SID credential should be changed to a nondefault value or SID authority should be disabled. This will also allow direct management of a storage silo.

## See also

[IOCTL_EHSTOR_DRIVER_REPORT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_driver_report_capabilities)