# UFS_INTERCONNECT_DESCRIPTOR structure

## Description

**UFS_INTERCONNECT_DESCRIPTOR** contains the MIPI M-PHY® specification version number and the MIPI
6338 UniPro℠ specification version number.

## Members

### `bLength`

Specifies the length, in bytes, of this descriptor.

### `bDescriptorIDN`

Specifies the type of the descriptor. This descriptor will have a value of **UFS_DESC_INTERCONNECT_IDN**.

### `bcdUniproVersion`

Specifies the MIPI UniPro℠ version number in Binary Coded Decimal (BCD) format.

### `bcdMphyVersion`

Specifies the MIPI M-PHY® version number in BCD format.