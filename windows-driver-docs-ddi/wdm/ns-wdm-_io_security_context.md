# _IO_SECURITY_CONTEXT structure

## Description

The **IO_SECURITY_CONTEXT** structure represents the security context of an [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) request.

## Members

### `SecurityQos`

Reserved for system use.

### `AccessState`

Reserved for use by file systems and file system filter drivers. This member is a pointer to an [ACCESS_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_access_state) structure that contains the object's subject context, granted access types, and remaining desired access types.

### `DesiredAccess`

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that expresses the access rights that are requested in the [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) request.

### `FullCreateOptions`

Reserved for system use.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[ACCESS_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_access_state)

[IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)