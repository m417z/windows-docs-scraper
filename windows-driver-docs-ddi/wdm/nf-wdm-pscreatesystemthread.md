## Description

The **PsCreateSystemThread** routine creates a system thread that executes in kernel mode and returns a handle for the thread.

## Parameters

### `ThreadHandle` [out]

Points to a variable that will receive the handle. The driver must close the handle with [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) once the handle is no longer in use. This handle is a kernel handle for Windows Vista and later versions of Windows. In earlier versions of Windows, the handle might not be a kernel handle.

### `DesiredAccess` [in]

Specifies the [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that represents the requested types of access to the created thread.

### `ObjectAttributes` [in, optional]

Points to a structure that specifies the object's attributes. OBJ_PERMANENT, OBJ_EXCLUSIVE, and OBJ_OPENIF are not valid attributes for a thread object. On Windows XP and later versions of Windows, if the caller is not running in the system process context, it must set the OBJ_KERNEL_HANDLE attribute for *ObjectAttributes*. Drivers for Microsoft Windows 2000 and Windows 98/Me must only call **PsCreateSystemThread** from the system process context. For Windows Vista and later versions of Windows, the handle will be a kernel handle.

### `ProcessHandle` [in, optional]

Specifies an open handle for the process in whose address space the thread is to be run. The caller's thread must have PROCESS_CREATE_THREAD access to this process. If this parameter is not supplied, the thread will be created in the initial system process. This value should be **NULL** for a driver-created thread. Use the **NtCurrentProcess** macro, defined in Ntddk.h, to specify the current process.

### `ClientId` [out, optional]

Points to a structure that receives the client identifier of the new thread. This value should be **NULL** for a driver-created thread.

### `StartRoutine` [in]

The entry point for the newly created system thread. This parameter is a function pointer to a [ThreadStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kstart_routine) routine that receives a single argument, which is the *StartContext* parameter value supplied by the caller.

### `StartContext` [in, optional]

Supplies a single argument that is passed to the thread when it begins execution.

## Return value

**PsCreateSystemThread** returns STATUS_SUCCESS if the thread was created.

## Remarks

Drivers that create device-dedicated threads call this routine, either when they initialize or when I/O requests begin to come in to such a driver's Dispatch routines. For example, a driver might create such a thread when it receives an asynchronous device control request.

**PsCreateSystemThread** creates a kernel-mode thread that begins a separate thread of execution within the system. Such a system thread has no TEB or user-mode context and runs only in kernel mode.

If the input *ProcessHandle* is **NULL**, the created thread is associated with the system process. Such a thread continues running until either the system is shut down or the thread terminates itself by calling **PsTerminateSystemThread**.

Driver routines that run in a process context other than that of the system process must set the OBJ_KERNEL_HANDLE attribute for the *ObjectAttributes* parameter of **PsCreateSystemThread**. This restricts the use of the handle returned by **PsCreateSystemThread** to processes running in kernel mode. Otherwise, the thread handle can be accessed by the process in whose context the driver is running. Drivers can set the OBJ_KERNEL_HANDLE attribute as follows.

```cpp
InitializeObjectAttributes(&ObjectAttributes, NULL, OBJ_KERNEL_HANDLE, NULL, NULL);
```

For more information about the *StartContext* parameter, see [ThreadStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kstart_routine).

 The newly created system thread runs at PASSIVE_LEVEL inside a critical region with [normal kernel APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/types-of-apcs) disabled.

## See also

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[KeSetBasePriorityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesetbaseprioritythread)

[KeSetPriorityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetprioritythread)

[PsTerminateSystemThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psterminatesystemthread)

[ThreadStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kstart_routine)

[ZwSetInformationThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwsetinformationthread)