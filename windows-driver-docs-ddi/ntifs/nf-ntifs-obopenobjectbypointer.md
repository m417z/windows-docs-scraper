# ObOpenObjectByPointer function

## Description

The **ObOpenObjectByPointer** function opens an object referenced by a pointer and returns a handle to the object.

## Parameters

### `Object` [in]

Pointer to the object to be opened.

### `HandleAttributes` [in]

Bitmask of flags specifying the desired attributes for the object handle. If the caller is not running in the system process context, these flags must include OBJ_KERNEL_HANDLE. This parameter is optional and can be zero. Otherwise, it is an OR'ed combination of one or more of the following values.

| Flag | Meaning |
| ---- | ------- |
| OBJ_EXCLUSIVE | The object is to be opened for exclusive access. If this flag is set and the call to **ObOpenObjectByPointer** succeeds, the object cannot be shared and cannot be opened again until the handle is closed. This flag is incompatible with the OBJ_INHERIT flag. This flag is invalid for file objects. |
| OBJ_FORCE_ACCESS_CHECK | All access checks are to be enforced for the object, even if the object is being opened in kernel mode. If this flag is specified, the value of the **AccessMode** parameter is ignored. |
| OBJ_INHERIT | The handle can be inherited by child processes of the current process. This flag is incompatible with the OBJ_EXCLUSIVE flag. |
| OBJ_KERNEL_HANDLE | The handle can only be accessed in kernel mode. This flag must be specified if the caller is not running in the system process context. |

### `PassedAccessState` [in, optional]

Pointer to an [**ACCESS_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_access_state) structure containing the object's subject context, granted access types, and remaining desired access types. This parameter is optional and can be NULL. In a create dispatch routine, this pointer can be found in **IrpSp->Parameters.Create.SecurityContext->AccessState**, where **IrpSp** is a pointer to the caller's own stack location in the IRP. (For more information, see [**IRP_MJ_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create).)

### `DesiredAccess` [in]

[**ACCESS_MASK**](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value specifying the desired access to the object. This parameter is optional and can be zero.

### `ObjectType` [in, optional]

Pointer to the object type. If the value of **AccessMode** is **KernelMode**, this parameter is optional and can be NULL. Otherwise, it must be either ***ExEventObjectType**, ***ExSemaphoreObjectType**, ***IoFileObjectType**, ***PsThreadType**, ***SeTokenObjectType**, or ***CmKeyObjectType**.

> [!NOTE]
>
> The **SeTokenObjectType** object type is supported staring with Windows XP and the **CmKeyObjectType** object type is supported staring with Windows 7.

### `AccessMode` [in]

Access mode to be used for the access check. This parameter is required and must be either **UserMode** or **KernelMode**:

* If **AccessMode** is **KernelMode**, the system always allows the requested access regardless of any restricted access previously set a driver (for example, [access restricted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_pre_create_handle_information) in a prior call to [**POB_PRE_OPERATION_CALLBACK callback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback)).

* If **AccessMode** is **UserMode**, the requested access is compared to the granted access for the object.

### `Handle` [out]

Pointer to a caller-allocated variable that receives a handle to the object.

## Return value

**ObOpenObjectByPointer** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_ACCESS_DENIED | The caller did not have the required access to open a handle for the object. This is an error code. |
| STATUS_INSUFFICIENT_RESOURCES | **ObOpenObjectByPointer** encountered a pool allocation failure. This is an error code. |
| STATUS_INVALID_PARAMETER | An invalid flag value was specified in the **HandleAttributes** parameter. This is an error code. |
| STATUS_OBJECT_TYPE_MISMATCH | The object pointed to by the **Object** parameter was not of the type specified in the **ObjectType** parameter. This is an error code. |
| STATUS_PRIVILEGE_NOT_HELD | The caller did not have the required privilege to create a handle with the access specified in the **DesiredAccess** parameter. This is an error code. |
| STATUS_QUOTA_EXCEEDED | The caller is running in the context of a process whose memory quota is not sufficient to allocate the object handle. This is an error code. |
| STATUS_UNSUCCESSFUL | The object handle could not be created. This is an error code. |

## Remarks

If the **Object** parameter points to a file object (that is, a FILE_OBJECT structure), **ObOpenObjectByPointer** can only be called after at least one handle has been created for the file object. Callers can check the **Flags** member of the FILE_OBJECT structure that the **Object** parameter points to. If the FO_HANDLE_CREATED flag is set, this means that one or more handles have been created for the file object, so it is safe to call **ObOpenObjectByPointer**.

Any handle obtained by calling **ObOpenObjectByPointer** must eventually be released by calling [**ZwClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose).

Driver routines that run in a process context other than that of the system process must set the OBJ_KERNEL_HANDLE flag in the **HandleAttributes** parameter. This restricts the use of the handle returned by **ObOpenObjectByPointer** to processes running in kernel mode. Otherwise, the handle can be accessed by the process in whose context the driver is running.

## See also

[**ACCESS_MASK**](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[**ACCESS_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_access_state)

[**IRP_MJ_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)

[**ObReferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obfreferenceobject)

[**ObReferenceObjectByHandle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[**ObReferenceObjectByPointer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbypointer)

[**ZwClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)