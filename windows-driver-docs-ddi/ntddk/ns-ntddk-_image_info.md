## Description

The IMAGE_INFO structure is used by driver's load-image routine ([PLOAD_IMAGE_NOTIFY_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pload_image_notify_routine)) to specify load image information.

## Members

### `Properties`

Represents all the bit values within the structure that **Properties** is unioned with.

### `ImageAddressingMode`

Always set to IMAGE_ADDRESSING_MODE_32BIT.

### `SystemModeImage`

Set either to one for newly loaded kernel-mode components, such as drivers, or to zero for images that are mapped into user space.

### `ImageMappedToAllPids`

Always set to zero.

### `ExtendedInfoPresent`

If the **ExtendedInfoPresent** flag is set, IMAGE_INFO is a part of [IMAGE_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_image_info_ex). Added in Windows Vista.

### `MachineTypeMismatch`

Always set to zero. Added in Windows 8/Windows Server 2012.

### `ImageSignatureLevel`

The level of signature with which code integrity has labeled the image. This value is one of the `#define SE_SIGNING_LEVEL_*` constants in *ntddk.h*. Added in Windows 8.1/Windows Server 2012 R2.

### `ImageSignatureType`

The type of signature with which code integrity has labeled the image. This value is a **SE_IMAGE_SIGNATURE_TYPE** enumeration value, defined in *ntddk.h*. Added in Windows 8.1/Windows Server 2012 R2.

### `ImagePartialMap`

This value is non-zero if the image mapping view called out for is a partial view that does not map the entire image; 0 if the view maps the entire image. Added in Windows 10/Windows Server 2016.

### `Reserved`

Always set to zero.

### `ImageBase`

Set to the virtual base address of the image.

### `ImageSelector`

Always set to zero.

### `ImageSize`

Set to the virtual size, in bytes, of the image.

### `ImageSectionNumber`

Always set to zero.

## Remarks

If the **ExtendedInfoPresent** flag is set, the IMAGE_INFO structure is part of IMAGE_INFO_EX, which is a larger, extended version of the image information structure. In this case, the load-image notify routine can use the **CONTAINING_RECORD** macro (in *miniport.h*) to obtain the base address of the IMAGE_INFO_EX structure.

## See also

[IMAGE_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_image_info_ex)

[PLOAD_IMAGE_NOTIFY_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pload_image_notify_routine)

[PsSetLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetloadimagenotifyroutine)