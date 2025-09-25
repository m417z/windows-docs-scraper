# _WINBIO_BIR structure

## Description

The WINBIO_BIR structure is the root of the BIR (Biometric Information Record). It contains the size and offset of any other data elements in the BIR.

## Members

### `HeaderBlock`

A structure of type [WINBIO_BIR_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_bir_data) that contains size and offset information for a standard biometric header. This member is required.

### `StandardDataBlock`

A structure of type [WINBIO_BIR_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_bir_data) that contains size and offset information for a standard data block based on the ANSI 381 format. This member is optional. Set this member to 0,0 if you do not use it.

### `VendorDataBlock`

A structure of type [WINBIO_BIR_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_bir_data) that contains size and offset information for a vendor-specific data block. This member is optional. Set this member to 0,0 if you do not use it.

### `SignatureBlock`

A structure of type [WINBIO_BIR_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_bir_data) that contains size and offset information for a signature block. This member is optional. Set this member to 0,0 if you do not use it.

## Remarks

The four WINBIO_BIR_DATA structures are contiguous and should be immediately followed by the actual data for each block. Thus, the offset for the *HeaderBlock* will always be 4*(sizeof (WINBIO_BIR_DATA). You can use the [WINBIO_BIR_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_bir_header) structure to provide the actual data of the header block.

The offset of where the *StandardDataBlock* starts should be the offset of the HeaderBlock plus the size of the HeaderBlock.

## See also

[WINBIO_BIR_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_bir_data)

[WINBIO_BIR_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_bir_header)

[WINBIO_CAPTURE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_capture_data)

[WINBIO_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_data)