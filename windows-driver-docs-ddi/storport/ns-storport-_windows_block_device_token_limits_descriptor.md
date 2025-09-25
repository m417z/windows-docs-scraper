# _WINDOWS_BLOCK_DEVICE_TOKEN_LIMITS_DESCRIPTOR structure (storport.h)

## Description

The **WINDOWS_BLOCK_DEVICE_TOKEN_LIMITS_DESCRIPTOR** structure is the third party copy descriptor for Windows systems. This structure serves as the descriptor for the vital product data (VPD) third party copy page.

## Members

### `DescriptorType`

The descriptor type identifying this structure. The descriptor type is defined in *storport.h* as **BLOCK_DEVICE_TOKEN_LIMITS_DESCRIPTOR_TYPE_WINDOWS**.

### `DescriptorLength`

The length of this structure starting with the **VendorSpecific** member.

### `VendorSpecific`

Vendor specific bytes included in the descriptor. Windows applications must treat this member as reserved and ignore the reported value.

### `MaximumRangeDescriptors`

The maximum number of range descriptors that may be included along with the [POPULATE_TOKEN_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-populate_token_header) or the [WRITE_USING_TOKEN_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-write_using_token_header) structures.

### `MaximumInactivityTimer`

The maximum available to specify as the timeout value in the **InactivityTimeout** member of the [POPULATE_TOKEN_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-populate_token_header) structure.

### `DefaultInactivityTimer`

The default value that is used by the copy provider when the **InactivityTimeout** of the [POPULATE_TOKEN_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-populate_token_header) structure is set to 0.

### `MaximumTokenTransferSize`

The maximum number of logical blocks that can be specified as a total of the block range descriptors in the [POPULATE_TOKEN_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-populate_token_header) or the [WRITE_USING_TOKEN_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-write_using_token_header) structures.

### `OptimalTransferCount`

The optimal number of logical blocks, as a maximum, to specify as a total of the block range descriptors in the [POPULATE_TOKEN_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-populate_token_header) or the [WRITE_USING_TOKEN_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-write_using_token_header) structures. Offload data transfer performance may degrade if the transfer count is larger than this value.

## Remarks

All multibyte values are in big endian format. Prior to evaluation, these values must be converted to match the endian format of the current platform.

## See also

[POPULATE_TOKEN_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-populate_token_header)

[VPD_THIRD_PARTY_COPY_PAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_vpd_third_party_copy_page)

[WRITE_USING_TOKEN_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-write_using_token_header)