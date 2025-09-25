# _OB_POST_OPERATION_INFORMATION structure

## Description

The **OB_POST_OPERATION_INFORMATION** structure provides information about a process or thread handle operation to an [ObjectPostCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_post_operation_callback) routine.

## Members

### `Operation`

The type of handle operation. This member might be one of the following values:

#### OB_OPERATION_HANDLE_CREATE

A new handle to a process or thread was created. Use **Parameters->CreateHandleInformation** for create-specific information.

#### OB_OPERATION_HANDLE_DUPLICATE

A process or thread handle was duplicated. Use **Parameters->DuplicateHandleInformation** for duplicate-specific information.

### `Flags`

Reserved. Use the **KernelHandle** member instead.

### `KernelHandle`

A ULONG value that specifies whether the handle is a kernel handle. If this value is **TRUE**, the handle is a kernel handle. Otherwise, the handle is not a kernel handle.

### `Reserved`

Reserved for system use.

### `Object`

A pointer to the process or thread object that is the target of the handle operation.

### `ObjectType`

A pointer to the object type of the object. This type can be **PsProcessType** for a process or **PsThreadType** for a thread.

### `CallContext`

A pointer to driver-specific context information for the operation. This value is the value that the *OperationInformation*->**CallContext** member specifies to the [ObjectPreCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback) routine.

### `ReturnStatus`

The NTSTATUS value for the handle operation.

### `Parameters`

A pointer to an [OB_POST_OPERATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_post_operation_parameters) union that contains operation-specific information. The **Operation** member determines which member of the union is valid. The pointer is valid only when **ReturnStatus** is a success code.

## Remarks

Unlike the [OB_PRE_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_pre_operation_information) structure, the members of the **OB_POST_OPERATION_INFORMATION** structure are purely informational; you cannot modify them.

## See also

[OB_PRE_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_pre_operation_information)

[ObjectPostCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_post_operation_callback)

[ObjectPreCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback)