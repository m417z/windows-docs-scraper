## Description

The **ObCloseHandle** routine closes an object handle.

## Parameters

### `Handle` [in]

A handle to a system-supplied object of any type.

### `PreviousMode` [in]

Specifies the previous processor mode of the thread that opened the handle. To close a kernel handle set this parameter to **KernelMode**. To close a *user handle*, set this parameter to **UserMode**. For more information about these two handle types, see Remarks.

## Return value

**ObCloseHandle** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following NTSTATUS codes.

| Return code | Description |
|---|---|
| **STATUS_INVALID_HANDLE** | *Handle* is not a valid handle. |
| **STATUS_HANDLE_NOT_CLOSABLE** | The calling thread does not have permission to close the handle. |

## Remarks

A kernel-mode driver calls **ObCloseHandle** to close a handle to any type of object that is created by the Windows kernel. A driver must close every handle that it opens as soon as the handle is no longer required.

After **ObCloseHandle** closes an object's handle, the caller must treat the handle as invalid and avoid using the handle to access the object. However, other handles might remain open on the same object. During an **ObCloseHandle** call, the system decrements the handle count for the object and checks whether the object can be deleted. The system does not delete the object until all of the object's handles are closed and all reference-counted pointers to the object are released.

The *PreviousMode* parameter specifies whether the handle to be closed is a kernel handle or a user handle. To close a kernel handle, set *PreviousMode* to **KernelMode**. To close a user handle, set *PreviousMode* to **UserMode**.

A kernel handle is a handle that is opened by a system thread, or by a kernel-mode driver that assigns the OBJ_KERNEL_HANDLE attribute to the handle. (For example, see the description of OBJ_KERNEL_HANDLE in [ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile).) If a kernel-mode driver opens a handle for its private use, and this driver runs in the context of a user-mode thread, the driver must open the handle with the OBJ_KERNEL_HANDLE attribute. This attribute ensures that the handle is inaccessible to user-mode applications.

A user handle is a handle that is opened by a user-mode application, or by a kernel-mode driver that runs in the context of a user-mode thread but that does not open the handle with the OBJ_KERNEL_HANDLE attribute. If a driver creates a user handle to be used by a user-mode application, but an error occurs that requires the driver to close the handle on behalf of the application, the driver can call **ObCloseHandle** to close the handle.

The **ZwClose** routine is similar to **ObCloseHandle** but can close only kernel handles. The call **ZwClose**(*hObject*), which closes kernel handle *hObject*, has the same effect as the call **ObCloseHandle**(*hObject*, **KernelMode**). For more information about closing a kernel handle, see [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose).

To determine whether a handle is a kernel handle or a user handle, a driver that receives a handle can call the [ExGetPreviousMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exgetpreviousmode) routine. Or, the driver can read the **RequestorMode** field from the [**IRP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure that describes the I/O request. The I/O manager sets the **RequestorMode** field to the previous processor mode of the thread that requested the I/O operation.

Callers of **ObCloseHandle** should not assume that this routine automatically waits for all pending I/O operations to complete before it returns.

For more information, see [Object Handles](https://learn.microsoft.com/windows-hardware/drivers/kernel/object-handles).

**ObCloseHandle** is not declared in a header file prior to Windows 7. To use this routine in your driver, include the following function declaration in your driver code:

```cpp
#if (NTDDI_VERSION < NTDDI_WIN7)
NTKERNELAPI
NTSTATUS
  ObCloseHandle(
    __in HANDLE Handle,
    __in KPROCESSOR_MODE PreviousMode
    );
#endif
```

## See also

[ExGetPreviousMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exgetpreviousmode)

[**IRP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)