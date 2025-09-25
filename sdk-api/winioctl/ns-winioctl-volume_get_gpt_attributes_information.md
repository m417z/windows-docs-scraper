# VOLUME_GET_GPT_ATTRIBUTES_INFORMATION structure

## Description

Contains volume attributes retrieved with the [IOCTL_VOLUME_GET_GPT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_volume_get_gpt_attributes) control code.

## Members

### `GptAttributes`

Specifies all of the attributes
associated with a volume.

| Value | Meaning |
| --- | --- |
| **GPT_BASIC_DATA_ATTRIBUTE_READ_ONLY**<br><br>0x1000000000000000 | The volume is read-only. |
| **GPT_BASIC_DATA_ATTRIBUTE_SHADOW_COPY**<br><br>0x2000000000000000 | The volume is a shadow copy of another volume. For more information, see [Volume Shadow Copy Service Overview](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-service-overview). |
| **GPT_BASIC_DATA_ATTRIBUTE_HIDDEN**<br><br>0x4000000000000000 | The volume is hidden. |
| **GPT_BASIC_DATA_ATTRIBUTE_NO_DRIVE_LETTER**<br><br>0x8000000000000000 | The volume is not assigned a default drive letter. |

## See also

[IOCTL_VOLUME_GET_GPT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_volume_get_gpt_attributes)