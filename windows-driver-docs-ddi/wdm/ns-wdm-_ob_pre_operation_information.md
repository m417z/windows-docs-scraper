# _OB_PRE_OPERATION_INFORMATION structure

## Description

The **OB_PRE_OPERATION_INFORMATION** structure provides information about a process or thread handle operation to an [ObjectPreCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback) routine.

## Members

### `Operation`

The type of handle operation. This member might be one of the following values:

#### OB_OPERATION_HANDLE_CREATE

A new handle to a process or thread will be opened. Use **Parameters->CreateHandleInformation** for create-specific information.

#### OB_OPERATION_HANDLE_DUPLICATE

A process or thread handle will be duplicated. Use **Parameters->DuplicateHandleInformation** for duplicate-specific information.

### `Flags`

Reserved. Use the **KernelHandle** member instead.

### `KernelHandle`

A bit that specifies whether the handle is a kernel handle. If this member is **TRUE**, the handle is a kernel handle. Otherwise, this handle is not a kernel handle.

### `Reserved`

Reserved for system use.

### `Object`

A pointer to the process or thread object that is the target of the handle operation.

### `ObjectType`

A pointer to the object type of the object. This member is **PsProcessType** for a process or **PsThreadType** for a thread.

### `CallContext`

A pointer to driver-specific context information for the operation. By default, the Filter Manager sets this member to **NULL**, but the [ObjectPreCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback) routine can reset the **CallContext** member in a driver-specific manner. The Filter Manager passes this value to the matching [ObjectPostCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_post_operation_callback) routine.

### `Parameters`

A pointer to an [OB_PRE_OPERATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_pre_operation_parameters) union that contains operation-specific information. The **Operation** member determines which member of the union is valid.

## See also

[OB_PRE_OPERATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_pre_operation_parameters)

[ObjectPostCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_post_operation_callback)

[ObjectPreCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback)