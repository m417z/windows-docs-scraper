# INQUIRYDATA structure (storport.h)

## Description

The **INQUIRYDATA** structure is used in conjunction with the [**TapeMiniExtensionInit**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_extension_init_routine) and [**TapeMiniVerifyInquiry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_verify_inquiry_routine) routines to report SCSI inquiry data associated with a tape device.

## Members

### `DeviceType`

Specifies the type of device. For a complete list of symbolic constants that indicate the various device types, see [Specifying Device Types](https://learn.microsoft.com/windows-hardware/drivers/kernel/specifying-device-types).

### `DeviceTypeQualifier`

Indicates whether the device is present or not. The values that this member can take are as follows:

| Value | Meaning |
| ----- | ------- |
| DEVICE_QUALIFIER_ACTIVE | The operating system supports the device, and the device is present. |
| DEVICE_QUALIFIER_NOT_ACTIVE | The operating system supports the device, but the device is not present. |
| DEVICE_QUALIFIER_NOT_SUPPORTED | The operating system does not support this device. |

### `DeviceTypeModifier`

Specifies the device type modifier, if any, as defined by SCSI. If no device type modifier exists, this member is zero.

### `RemovableMedia`

Indicates, when TRUE, that the media is removable, and when FALSE that the media is not removable.

### `Versions`

Indicates the version of the inquiry data standard that this data conforms to. For more information about the version values allowed in this field, see the *SCSI Primary Commands - 2 (SPC-2)* specification.

### `ResponseDataFormat`

Indicates the SCSI standard that governs the response data format. The value of this member must be 2.

### `HiSupport`

Indicates, when zero, that the target does not use the hierarchical addressing model to assign LUNs to logical units. A value of 1 indicates the target uses the hierarchical addressing model to assign LUNs to logical units.

### `NormACA`

Indicates, when set to one, that the operating system supports setting the NACA bit to one in the control byte of the command descriptor block (CDB). A value of zero indicates that the system does not support setting the NACA bit to one. For more information about the function of the NACA bit and the control byte in a CDB, see the *SCSI Primary Commands - 2 (SPC-2)* specification.

### `ReservedBit`

### `AERC`

Indicates, when set to one, that the target device supports the asynchronous event reporting capability. A value of zero indicates that the target device does not support asynchronous event reports. Details of the asynchronous event reporting support are protocol-specific. For more information about asynchronous even reporting, see the *SCSI Primary Commands - 2 (SPC-2)* specification.

### `AdditionalLength`

Specifies the length in bytes of the parameters of the command descriptor block (CDB).

### `Reserved`

Reserved.

### `SoftReset`

Indicates, when set to one, that the target device supports soft resets. A value of zero indicates that the target does not support soft resets.

### `CommandQueue`

Indicates, when set to one, that the target device supports command queuing for this logical unit. However, a value of zero does not necessarily indicate that the target device does not support command queuing. The meaning of these values depends on the values present in the SCSI inquiry data. For information about the meaning of the command queuing bit, see the *SCSI Primary Commands - 2 (SPC-2)* specification.

### `Reserved2`

Reserved.

### `LinkedCommands`

Indicates, when set to one, that the operating system supports linked commands. A value of zero indicates the operating system does not support linked commands.

### `Synchronous`

Indicates, when set to one, that the target supports synchronous data transfer. A value of zero indicates that the target does not support synchronous data transfer.

### `Wide16Bit`

Indicates, when set to one, that the target supports 16-bit wide data transfers. A value of zero indicates that the device does not support 16-bit wide data transfers.

### `Wide32Bit`

Indicates, when set to one, that the target supports 32-bit wide data transfers. A value of zero indicates that the device does not support 32-bit wide data transfers.

### `RelativeAddressing`

Indicates, when set to one, that the operating system supports the relative addressing mode. A value of zero indicates the operating system does not support relative addressing.

### `VendorId`

Contains eight bytes of ASCII data that identifies the vendor of the product.

### `ProductId`

Contains sixteen bytes of ASCII data that indicates the product ID, as defined by the vendor. The data shall be left-aligned within this field and the unused bytes filled with ASCII blanks.

### `ProductRevisionLevel`

Contains four bytes of ASCII data that indicates the product revision level, as defined by the vendor.

### `VendorSpecific`

Contains 20 bytes of vendor-specific data.

### `Reserved3`

Reserved.

### `VersionDescriptors`

Contains 8 bytes of ASCII data that indicates the version descriptor, as defined by the vendor.

### `Reserved4`

 Reserved.

## See also

[**TapeMiniExtensionInit**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_extension_init_routine)

[**TapeMiniVerifyInquiry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_verify_inquiry_routine)