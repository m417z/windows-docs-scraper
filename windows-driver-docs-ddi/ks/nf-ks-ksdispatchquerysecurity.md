# KsDispatchQuerySecurity function

## Description

The **KsDispatchQuerySecurity** function is used in the KSDISPATCH_TABLE.QuerySecurity entry to handle querying about the current security descriptor. The assumption is that the KSOBJECT_HEADER structure is being used in the **FsContext** data structure and that the **CreateItem** points to a valid item that optionally contains a security descriptor.

## Parameters

### `DeviceObject` [in]

Specifies the device object associated with the IRP.

### `Irp` [in]

Specifies the IRP that is being handled.

## Return value

The **KsDispatchQuerySecurity** function returns the security query status and completes the IRP if a security descriptor is present. If no security descriptor is present, it returns STATUS_NO_SECURITY_ON_OBJECT.