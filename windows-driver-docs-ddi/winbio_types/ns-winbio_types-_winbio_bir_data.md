# _WINBIO_BIR_DATA structure

## Description

The WINBIO_BIR_DATA structure contains the location and size of a block in a BIR. The offset is measured from the beginning of the [WINBIO_BIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_bir) structure.

## Members

### `Size`

Specifies the size, in bytes, of a block in the BIR.

### `Offset`

Specifies the offset, in bytes, of the block within the BIR.

## See also

[WINBIO_BIR_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_bir_header)

[WINBIO_CAPTURE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_capture_data)

[WINBIO_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_data)