# _OB_OPERATION_REGISTRATION structure

## Description

The **OB_OPERATION_REGISTRATION** structure specifies [ObjectPreCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback) and [ObjectPostCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_post_operation_callback) callback routines and the types of operations that the routines are called for.

## Members

### `ObjectType`

A pointer to the object type that triggers the callback routine. Specify one of the following values:

* **PsProcessType** for process handle operations
* **PsThreadType** for thread handle operations
* **ExDesktopObjectType** for desktop handle operations. This value is supported in Windows 10 and not in the earlier versions of the operating system.

### `Operations`

Specify one or more of the following flags:

#### OB_OPERATION_HANDLE_CREATE

A new process, thread, or desktop handle was or will be opened.

#### OB_OPERATION_HANDLE_DUPLICATE

A process, thread, or desktop handle was or will be duplicated.

### `PreOperation`

A pointer to an [ObjectPreCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback) routine. The system calls this routine before the requested operation occurs.

### `PostOperation`

A pointer to an [ObjectPostCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_post_operation_callback) routine. The system calls this routine after the requested operation occurs.

## Remarks

This structure is used by the [ObRegisterCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obregistercallbacks) routine. The *CallBackRegistration* parameter to this routine is a pointer to a buffer that contains an [OB_CALLBACK_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_callback_registration) structure that is followed by an array of one or more **OB_OPERATION_REGISTRATION** structures.

In each **OB_OPERATION_REGISTRATION** structure passed to **ObRegisterCallback**, the caller must supply one or both callback routines. If the **PreOperation** and **PostOperation** members of this structure are both **NULL**, the callback registration operation fails.

## See also

[OB_CALLBACK_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_callback_registration)

[ObRegisterCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obregistercallbacks)

[ObjectPostCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_post_operation_callback)

[ObjectPreCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback)