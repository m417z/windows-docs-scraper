# PLOAD_IMAGE_NOTIFY_ROUTINE callback function

## Description

Called by the operating system to notify the driver when a driver image or a user image (for example, a DLL or EXE) is mapped into virtual memory. The operating system invokes this routine after an image has been mapped to memory, but before its entrypoint is called.

> [!WARNING]
> The actions that you can perform in this routine are restricted for safe calls. See [Best Practices](https://learn.microsoft.com/windows-hardware/drivers/kernel/windows-kernel-mode-process-and-thread-manager#best).

## Parameters

### `FullImageName` [in, optional]

A pointer to a buffered Unicode string that identifies the executable image file. (The *FullImageName* parameter can be **NULL** in cases in which the operating system is unable to obtain the full name of the image at process creation time.)

### `ProcessId` [in]

The process ID of the process in which the image has been mapped, but this handle is zero if the newly loaded image is a driver.

### `ImageInfo` [in]

A pointer to an [IMAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_image_info) structure that contains image information. See Remarks.

## Remarks

Highest-level system-profiling drivers can call [PsSetLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetloadimagenotifyroutine) to set up their load-image notify routine.

The operating system does not call load-image notify routines when sections created with the SEC_IMAGE_NO_EXECUTE attribute are mapped to virtual memory.

In Windows 7, Windows Server 2008 R2, and earlier versions of Windows, the operating system holds an internal system lock during calls to load-image notify routines for images loaded in user process address space (user space). To avoid deadlocks, load-image notify routines must not call system routines that map, allocate, query, free, or perform other operations on user-space virtual memory.

A driver must remove any callbacks it registers before it unloads. You can remove the callback by calling the [PsRemoveLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psremoveloadimagenotifyroutine) routine.

When the main executable image for a newly created process is loaded, the load-image notify routine runs in the context of the new process. The operating system calls the driver's load-image notify routine at PASSIVE_LEVEL inside a critical region with [normal kernel APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/types-of-apcs) always disabled and sometimes with both kernel and special APCs disabled.

When the load-image notify routine is called, the input *FullImageName* points to a buffered Unicode string that identifies the executable image file. (The *FullImageName* parameter can be **NULL** in cases in which the operating system is unable to obtain the full name of the image at process creation time.) The *ProcessId* handle identifies the process in which the image has been mapped, but this handle is zero if the newly loaded image is a driver. To see the format of the buffered data at *ImageInfo*, see [IMAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_image_info). If the **ExtendedInfoPresent** flag is set in the **IMAGE_INFO** structure, the information is part of a larger, extended version of the image information structure, [IMAGE_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_image_info_ex).

## See also

[IMAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_image_info)

[IMAGE_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_image_info_ex)

[PsSetLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetloadimagenotifyroutine)