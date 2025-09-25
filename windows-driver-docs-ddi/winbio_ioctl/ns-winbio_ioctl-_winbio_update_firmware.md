# _WINBIO_UPDATE_FIRMWARE structure

## Description

The WINBIO_UPDATE_FIRMWARE structure is the IN payload for [IOCTL_BIOMETRIC_UPDATE_FIRMWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ni-winbio_ioctl-ioctl_biometric_update_firmware).

## Members

### `PayloadSize`

Specifies the total size of the payload, which includes the fixed length structure and any variable data at the end.

### `FirmwareData`

Specifies a structure of type [WINBIO_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_data) that contains the vendor-specific firmware image.

## See also

[IOCTL_BIOMETRIC_UPDATE_FIRMWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ni-winbio_ioctl-ioctl_biometric_update_firmware)

[WINBIO_BLANK_PAYLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_blank_payload)