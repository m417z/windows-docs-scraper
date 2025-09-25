# KsDispatchSetSecurity function

## Description

The **KsDispatchSetSecurity** function is used in the KSDISPATCH_TABLE.SetSecurity entry to handle setting the current security descriptor. The assumption is that the KSOBJECT_HEADER structure is being used in the **FsContext** data structure and that the **CreateItem** points to a valid item that optionally contains a security descriptor.

## Parameters

### `DeviceObject` [in]

Specifies the device object associated with the IRP.

### `Irp` [in]

Specifies the IRP that is being handled.

## Return value

The **KsDispatchSetSecurity** function returns the security set status and completes the IRP.

## Remarks

This security descriptor must be allocated in its own piece of pool memory, since **KsDispatchSetSecurity** will replace the existing descriptor with a new allocation. Therefore, it cannot be shared with **CreateItem**.