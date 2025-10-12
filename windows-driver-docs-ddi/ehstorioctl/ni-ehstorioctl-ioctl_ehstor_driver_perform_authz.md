# IOCTL_EHSTOR_DRIVER_PERFORM_AUTHZ IOCTL

## Description

**IOCTL_EHSTOR_DRIVER_PERFORM_AUTHZ** is sent by the Enhanced Storage Class Driver (EHSTOR) to the silo driver to initiate on-demand authentication or deauthentication.

## Parameters

### Major code

### Input buffer

The input buffer at **Irp->AssociatedIrp.SystemBuffer** must contain an **AUTHZ_STATE** structure that indicates the type of authentication operation to perform. **AUTHZ_STATE** is declared in *ehstorioctl.h* as the following.

```
typedef struct _AUTHZ_STATE
{
    ULONG AuthzState;
} AUTHZ_STATE;
```

The value of **AuthzState** specifies the authentication operation. This is one of the following.

| Value | Description |
| --- | --- |
| 0 | Perform on-demand deauthentication. |
| AUTHZSTATE_AUTHENTICATE | Perform on-demand authentication. |
| AUTHZSTATE_CLEAR_AUTHKEY_CACHE | Perform on-demand deauthentication and clear cached authentication keys. |

### Input buffer length

The length of an **AUTHZ_STATE** structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

STATUS_SUCCESS is returned in the **Status** field by the silo driver if the authentication state is changed. Otherwise, STATUS_UNSUCCESSFUL is returned.

## Remarks

This IOCTL is sent by EHSTOR to a silo driver that supports on-demand authentication. The silo driver notifies EHSTOR of this capability in a prior [IOCTL_EHSTOR_DRIVER_REPORT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_driver_report_capabilities) request with the **CAP_ON_DEMAND_AUTHENTICATION** flag set in the **Capabilities** member of [SILO_DRIVER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-_silo_driver_capabilities).

In response to this IOCTL, the silo driver performs authentication or deauthentication for the device. For banded devices, the silo driver will, depending on the specified operation in the system buffer, unlock or lock as many bands as possible for reads and writes.

If the silo driver fails to perform the requested operation, it will not change the authentication state of a device.

If the **AuthzState** member of **AUTHZ_STATE** is set to **AUTHZSTATE_CLEAR_AUTHKEY_CACHE**, then the silo driver clears its authentication key cache in addition to deauthenticating. **AUTHZSTATE_CLEAR_AUTHKEY_CACHE** is set when the system is shutting down or hibernating. This prevents the presence of the key cache in the hibernation file.

If a device supports multiple silos, authentication by each silo is exclusive. An authentication operation by one silo driver does not affect the authentication state set by another silo driver.

## See also

[IOCTL_EHSTOR_DRIVER_REPORT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_driver_report_capabilities)

[SILO_DRIVER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-_silo_driver_capabilities)