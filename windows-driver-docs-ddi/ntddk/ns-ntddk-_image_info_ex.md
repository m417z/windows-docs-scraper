# _IMAGE_INFO_EX structure

## Description

IMAGE_INFO_EX is the larger, extended version of the [IMAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_image_info) load image information structure.

## Members

### `Size`

Specifies the size, in bytes, of the IMAGE_INFO_EX structure.

### `ImageInfo`

An [IMAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_image_info) structure that specifies load image information.

### `FileObject`

Pointer to the file object of the backing file for the image. The driver can take a reference to this object or use it for other operations.

## Remarks

If the **ExtendedInfoPresent** flag is set in the IMAGE_INFO structure, the load image information is part of IMAGE_INFO_EX. In this case, the load-image notify routine can use the **CONTAINING_RECORD** macro (in *miniport.h*) to obtain the base address of the IMAGE_INFO_EX structure.

## See also

[IMAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_image_info)

[PLOAD_IMAGE_NOTIFY_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pload_image_notify_routine)

[PsSetLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetloadimagenotifyroutine)