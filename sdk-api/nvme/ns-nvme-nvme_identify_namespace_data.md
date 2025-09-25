# NVME_IDENTIFY_NAMESPACE_DATA structure

## Description

Contains values that indicate capabilities and settings that are specific to a particular namespace.

The capabilities and settings that are common to all namespaces are contained in the **NVME_IDENTIFY_NAMESPACE_DATA** data structure for the namespace with the Namespace Identifier of `0xFFFFFFFF`.

The **nvme.h** header file defines the constant **NVME_NAMESPACE_ALL** with a value of `0xFFFFFFFF`.

If the controller supports Namespace Management and the Namespace Identifier (**NSID**) field of the [NVME_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure is set to **NVME_NAMESPACE_ALL**, the controller returns an **NVME_IDENTIFY_NAMESPACE_DATA** data structure that specifies capabilities that are common across all namespaces.

## Members

### `NSZE`

Indicates the total size of the namespace in logical blocks.

A namespace of size *n* consists of Logical Block Address (LBA) `0` through `(n - 1)`. The number of logical blocks is based on the formatted LBA size. This field is undefined prior to the namespace being formatted.

### `NCAP`

Indicates the maximum number of logical blocks that may be allocated in the namespace at any point in time.

The number of logical blocks is based on the formatted LBA size. This field is undefined prior to the namespace being formatted.

The **NCAP** field is used in the case of thin provisioning and reports a value that is smaller than or equal to the Namespace Size (**NSZE**).

Spare LBAs are not reported as part of this field. A value of `0h` for the Namespace Capacity (**NCAP**) indicates that the namespace ID is an inactive namespace ID. A logical block is allocated when it is written with a Write or Write Uncorrectable command. A logical block may be deallocated using the [Dataset Management](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command#-field-u.datasetmanagement) command.

### `NUSE`

Indicates the current number of logical blocks allocated in the namespace.

The value of this field is smaller than or equal to the value of the Namespace Capacity **NCAP** field.

The number of logical blocks is based on the formatted LBA size. When using the NVM command set: A logical block is allocated when it is written with a Write or Write Uncorrectable command. A logical block may be deallocated using the [Dataset Management](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command#-field-u.datasetmanagement) command.

A controller may report a **NUSE** value equal to an **NCAP** value at all times if the product is not targeted for thin provisioning environments.

### `NSFEAT`

A Namespace Features (NSFEAT) structure containing fields that define features of the namespace.

### `NSFEAT.ThinProvisioning`

Bit 0 of the **NSFEAT** structure indicates whether the namespace supports thin provisioning.

When this value is set to `1`, the namespace supports thin provisioning. Specifically, the Namespace Capacity (**NCAP**) reported may be less than the Namespace Size (**NSZE**). When this feature is supported and the Dataset Management command is supported, then deallocating LBAs will be reflected in the Namespace Utilization (**NUSE**) field.

When this value is cleared to `0`, it indicates that thin provisioning is not supported and the **NSZE** and **NCAP** fields report the same value.

### `NSFEAT.NameSpaceAtomicWriteUnit`

Bit 1 of the **NSFEAT** structure indicates whether Namespace Atomic Boundary Parameters are defined for this namespace.

When this value is set to `1`, the fields **NAWUN**, **NAWUPF**, and **NACWU** are defined for this namespace and should be used by the host for this namespace instead of the **AWUN**, **AWUPF**, and **ACWU** fields in the [Identify Controller](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) data structure.

When this value is cleared to `0`, the controller does not support the fields **NAWUN**, **NAWUPF**, and **NACWU** for this namespace. In this case, the host should use the **AWUN**, **AWUPF**, and **ACWU** fields defined in the [Identify Controller](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) data structure.

### `NSFEAT.DeallocatedOrUnwrittenError`

Bit 2 of the **NSFEAT** structure indicates whether the controller supports the Deallocated or Unwritten Logical Block error for this namespace.

When this value is set to `1`, the controller supports the [Deallocated or Unwritten Logical Block (**NVME_STATUS_NVM_DEALLOCATED_OR_UNWRITTEN_LOGICAL_BLOCK**)](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_media_error_codes) error for this namespace. When this value is cleared to `0`, the controller does not support the **NVME_STATUS_NVM_DEALLOCATED_OR_UNWRITTEN_LOGICAL_BLOCK** error for this namespace.

### `NSFEAT.SkipReuseUI`

Bit 3 of the **NSFEAT** structure is a setting for the Skip Reuse UI feature.

### `NSFEAT.Reserved`

Bits 4:7 of the **NSFEAT** structure are reserved.

### `NLBAF`

Defines the number of supported LBA data size and metadata size combinations supported by the namespace.

LBA formats are allocated in order (starting with 0) and packed sequentially. This is a 0’s based value. The maximum number of LBA formats that may be indicated as supported is 16.

The supported LBA formats are indicated in the **LBAF** field (bytes 128 – 191 of this data structure). The metadata may be either transferred as part of the LBA (creating an extended LBA which is a larger LBA size that is exposed to the application) or it may be transferred as a separate contiguous buffer of data. The metadata cannot be split between the LBA and a separate metadata buffer.

It is recommended that software and controllers transition to an LBA size that is 4KB or larger for ECC efficiency at the controller. If providing metadata, it is recommended that at least 8 bytes are provided per logical block to enable use with end-to-end data protection.

### `FLBAS`

A Formatted LBA Size (FLBAS) structure containing fields that indicate the LBA data size and metadata size combination that the namespace has been formatted with.

### `FLBAS.LbaFormatIndex`

Bits 0:3 of the **FLBAS** structure specify one of the 16 supported LBA Formats indicated in this data structure.

### `FLBAS.MetadataInExtendedDataLBA`

Bit 4 of the **FLBAS** structure indicates whether metadata is transferred at the end of the data LBA, creating an extended data LBA.

When this value is set to `1`, the metadata is transferred at the end of the data LBA, creating an extended data LBA. When this value is cleared to `0`, it indicates that all of the metadata for a command is transferred as a separate contiguous buffer of data.

Bit 4 is not applicable when there is no metadata.

### `FLBAS.Reserved`

Bits 5:7 of the **FLBAS** structure are reserved.

### `MC`

A Metadata Capabilities (MC) structure containing fields that indicate the capabilities for metadata.

### `MC.MetadataInExtendedDataLBA`

Bit 0 of the **MC** structure indicates whether the namespace supports the metadata being transferred as part of an extended data LBA.

When this value is set to `1`, the namespace supports the metadata being transferred as part of an extended data LBA. When this value is cleared to `0`, it indicates that the namespace does not support the metadata being transferred as part of an extended data LBA.

### `MC.MetadataInSeparateBuffer`

Bit 1 of the **MC** structure indicates whether the namespace supports the metadata being transferred as part of a separate buffer.

When this value is set to `1`, the namespace supports the metadata being transferred as part of a separate buffer that is specified in the Metadata Pointer (**MPTR**) field of the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure. When this value is cleared to `0`, the namespace does not support the metadata being transferred as part of a separate buffer.

### `MC.Reserved`

Bits 7:2 of the **MC** structure are reserved.

### `DPC`

An End-to-end Data Protection Capabilities (DPC) structure containing fields that indicate the capabilities for the end-to-end data protection feature.

Multiple bits may be set in this field.

### `DPC.ProtectionInfoType1`

Bit 0 of the **DPC** structure indicates whether the namespace supports Protection Information Type 1.

When this value is set to `1`, the namespace supports Protection Information Type 1. When this value is cleared to `0`, the namespace does not support Protection Information Type 1.

### `DPC.ProtectionInfoType2`

Bit 1 of the **DPC** structure indicates whether the namespace supports Protection Information Type 2.

When this value is set to `1`, the namespace supports Protection Information Type 2. When this value is cleared to `0`, the namespace does not support Protection Information Type 2.

### `DPC.ProtectionInfoType3`

Bit 2 of the **DPC** structure indicates whether the namespace supports Protection Information Type 3.

When this value is set to `1`, the namespace supports Protection Information Type 3. When this value is cleared to `0`, the namespace does not support Protection Information Type 3.

### `DPC.InfoAtBeginningOfMetadata`

Bit 3 of the **DPC** structure indicates whether the namespace supports protection information transferred as the first eight bytes of metadata.

When this value is set to `1`, the namespace supports protection information transferred as the first eight bytes of metadata. When this value is cleared to `0`, the namespace does not support protection information transferred as the first eight bytes of metadata.

### `DPC.InfoAtEndOfMetadata`

Bit 4 of the **DPC** structure indicates whether the namespace supports protection information transferred as the last eight bytes of metadata.

When this value is set to `1`, the namespace supports protection information transferred as the last eight bytes of metadata. When this value is cleared to `0`, the namespace does not support protection information transferred as the last eight bytes of metadata.

### `DPC.Reserved`

Bits 7:5 of the **DPC** structure are reserved.

### `DPS`

A End-to-end Data Protection Type Settings (DPS) structure containing fields that indicate the Type settings for the end-to-end data protection feature.

[NVME_PROTECTION_INFORMATION_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_protection_information_types)

### `DPS.ProtectionInfoTypeEnabled`

Bits 2:0 of the **DPS** structure is an [NVME_PROTECTION_INFORMATION_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_protection_information_types) value that indicates whether Protection Information is enabled and the type of Protection Information enabled.

### `DPS.InfoAtBeginningOfMetadata`

Bit 3 of the **DPS** structure indicates whether the protection information, if enabled, is transferred as the first eight bytes of metadata.

When this value is set to `1`, the protection information, if enabled, is transferred as the first eight bytes of metadata. When this value is cleared to `0`, the protection information, if enabled, is transferred as the last eight bytes of metadata.

### `DPS.Reserved`

Bits 7:4 of the **DPS** structure are reserved.

### `NMIC`

A Namespace Multi-path I/O and Namespace Sharing Capabilities (NMIC) structure containing fields that specify the multi-path I/O and namespace sharing capabilities of the namespace.

### `NMIC.SharedNameSpace`

Bit 0 of the **NMIC** structure indicates whether the namespace may be a shared namespace.

When this value is set to `1`, the namespace may be accessible by two or more controllers in the NVM subsystem. When this value is cleared to `0`, the namespace is a private namespace and may only be accessed by the controller that returned this namespace data structure.

### `NMIC.Reserved`

Bits 7:1 of the **NMIC** structure are reserved.

### `RESCAP`

A Reservation Capabilities (RESCAP) structure containing fields that specify the reservation capabilities of the namespace.

A value of `00h` in this field indicates that reservations are not supported by this namespace.

### `RESCAP.PersistThroughPowerLoss`

Bit 0 of the **RESCAP** structure indicates whether the namespace supports the Persist Through Power Loss capability.

When this value is set to `1`, the namespace supports the Persist Through Power Loss capability. When this value is cleared to `0`, the namespace does not support the Persist Through Power Loss Capability.

### `RESCAP.WriteExclusiveReservation`

Bit 1 of the **RESCAP** structure indicates whether the namespace supports the Write Exclusive reservation type.

When this value is set to `1`, the namespace supports the Write Exclusive reservation type. When this value is cleared to `0`, the namespace does not support the Write Exclusive reservation type.

### `RESCAP.ExclusiveAccessReservation`

Bit 2 of the **RESCAP** structure indicates whether the namespace supports the Exclusive Access reservation type.

When this value is set to `1`, the namespace supports the Exclusive Access reservation type. When this value is cleared to `0`, the namespace does not support the Exclusive Access reservation type.

### `RESCAP.WriteExclusiveRegistrantsOnlyReservation`

Bit 3 of the **RESCAP** structure indicates whether the namespace supports the Write Exclusive – Registrants Only reservation type.

Bit 3 if set to `1` indicates that the namespace supports the Write Exclusive – Registrants Only reservation type. When this value is cleared to `0`, the namespace does not support the Write Exclusive – Registrants Only reservation type.

### `RESCAP.ExclusiveAccessRegistrantsOnlyReservation`

Bit 4 of the **RESCAP** structure indicates whether the namespace supports the Exclusive Access – Registrants Only reservation type.

When this value is set to `1`, the namespace supports the Exclusive Access – Registrants Only reservation type. When this value is cleared to `0`, the namespace does not support the Exclusive Access – Registrants Only reservation type.

### `RESCAP.WriteExclusiveAllRegistrantsReservation`

Bit 5 of the **RESCAP** structure indicates whether the namespace supports the Write Exclusive – All Registrants reservation type.

When this value is set to `1`, the namespace supports the Write Exclusive – All Registrants reservation type. When this value is cleared to `0`, the namespace does not support the Write Exclusive – All Registrants reservation type.

### `RESCAP.ExclusiveAccessAllRegistrantsReservation`

Bit 6 of the **RESCAP** structure indicates whether the namespace supports the Exclusive Access – All Registrants reservation type.

When this value is set to `1`, the namespace supports the Exclusive Access – All Registrants reservation type. When this value is cleared to `0`, the namespace does not support the Exclusive Access – All Registrants reservation type.

### `RESCAP.Reserved`

Bit 7 of the **RESCAP** structure is reserved.

### `FPI`

A Format Progress Indicator (FPI) structure containing fields that indicate the percentage of the namespace that remains to be formatted when a format operation is in progress.

### `FPI.PercentageRemained`

Bits 0:6 of the **FPI** structure indicate the percentage of the namespace that remains to be formatted. For example, a value of `25` indicates that 75% of the namespace has been formatted and 25% remains to be formatted.

A value of `0` indicates that the namespace is formatted with the format specified by the **FLBAS** and **DPS** fields in this data structure.

### `FPI.Supported`

Bit 7 of the **FPI** structure indicates whether the namespace supports the Format Progress Indicator defined by the **FPI.PercentageRemained** field.

When this value is set to `1`, the namespace supports the Format Progress Indicator defined by the **FPI.PercentageRemained** field. When this value is cleared to `0`, the namespace does not support the Format Progress Indicator and the **FPI.PercentageRemained** field will be cleared to `0h`.

### `Reserved0`

A reserved field.

### `NAWUN`

Indicates the namespace specific size of the write operation guaranteed to be written atomically to the NVM during normal operation.

A value of `0h` indicates that the size for this namespace is the same size as that reported in the **AWUN** field of the [Identify Controller](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) data structure. All other values specify a size in terms of logical blocks using the same encoding as the **AWUN** field.

### `NAWUPF`

Indicates the namespace specific size of the write operation guaranteed to be written atomically to the NVM during a power fail or error condition.

A value of `0h` indicates that the size for this namespace is the same size as that reported in the **AWUPF** field of the [Identify Controller](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) data structure. All other values specify a size in terms of logical blocks using the same encoding as the **AWUPF** field.

### `NACWU`

Indicates the namespace specific size of the write operation guaranteed to be written atomically to the NVM for a Compare and Write fused command.

A value of `0h` indicates that the size for this namespace is the same size as that reported in the **ACWU** field of the [Identify Controller](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) data structure. All other values specify a size in terms of logical blocks using the same encoding as the **ACWU** field.

### `NABSN`

Indicates the atomic boundary size for this namespace for the **NAWUN** value.

This field is specified in logical blocks. Writes to this namespace that cross atomic boundaries are not guaranteed to be atomic to the NVM with respect to other read or write commands.

A value of `0h` indicates that there are no atomic boundaries for normal write operations. All other values specify a size in terms of logical blocks using the same encoding as the **AWUN** field.

### `NABO`

Indicates the Logical Block Address (LBA) on this namespace where the first atomic boundary starts.

If the **NABSN** and **NABSPF** fields are cleared to `0h`, then the **NABO** field is cleared to 0h. The value of **NABO** should be less than or equal to **NABSN** and **NABSPF**.

### `NABSPF`

Indicates the atomic boundary size for this namespace specific to the Namespace Atomic Write Unit Power Fail value.

This field is specified in logical blocks. Writes to this namespace that cross atomic boundaries are not guaranteed to be atomic with respect to other read or write commands and there is no guarantee of data returned on subsequent reads of the associated logical blocks.

A value of `0h` indicates that there are no atomic boundaries for power fail or error conditions. All other values specify a size in terms of logical blocks using the same encoding as the **AWUPF** field.

### `NOIOB`

Indicates the Namespace Optimal IO Boundary (NOIOB).

### `NVMCAP`

Indicates the total size of the NVM allocated to this namespace.

The value of this field is in bytes. This field is supported if the Namespace Management and Namespace Attachment commands are supported.

Note: This field may not correspond to the logical block size multiplied by the Namespace Size (**NSZE**) field. Due to thin provisioning or other settings (such as, endurance), this field may be larger or smaller than the **NSZE** reported.

### `Reserved2`

A reserved field.

### `NVMSETID`

Indicates the Associated NVM Set Identifier (NVMSETID).

### `ENDGID`

Indicates the Associated Endurance Group Identifier (ENDGID).

### `NGUID`

Contains a 128-bit value that is globally unique and assigned to the namespace when the namespace is created.

The Namespace Globally Unique Identifier (**NGUID**) field remains fixed throughout the life of the namespace and is preserved across namespace and controller operations (such as controller reset and namespace format).

This field uses the EUI-64 based 16-byte designator format.

- Bytes 114:112 contain the 24-bit company_id value assigned by the IEEE Registration Authority.
- Bytes 119:115 contain an extension identifer assigned by the corresponding organization.
- Bytes 111:104 contain the vendor specific extension identifier assigned by the corresponding organization.

See the IEEE EUI-64 guidelines for more information. The controller should specify a globally unique namespace identifier in this field or the **EUI64** field when the namespace is created.

### `EUI64`

Contains a 64-bit IEEE Extended Unique Identifier (EUI-64) that is globally unique and assigned to the namespace when the namespace is created.

The **EUI64** field remains fixed throughout the life of the namespace and is preserved across namespace and controller operations (such as controller reset and namespace format).

The EUI-64 is a concatenation of a 24-bit or 36-bit company_id value assigned by the IEEE Registration Authority and an extension identifier assigned by the corresponding
organization. See the IEEE EUI-64 guidelines for more information.

The controller should specify a globally unique namespace identifier in this field or the **NGUID** field when the namespace is created. If the controller is not able to allocate a globally unique 64-bit identifier then this field will be cleared to `0h`.

### `LBAF`

Contains an array of 16 [NVME_LBA_FORMAT](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_lba_format) structures. Each structure in the array specifies an LBA Format and indicates that it is supported by the controller.

The zero-based position of a structure in the array corresponds to the name of the LBA Format, such that LBA Format 0 (LBAF0) is in position 0, LBA Format 1 (LBAF1) is in position 1, and so on, up to LBA Format 15 (LBAF15) in position 15.

### `Reserved3`

Bytes 192:383A are reserved.

### `VS`

This range of bytes (384:4095) is allocated for Vendor Specific (VS) usage.

## Remarks

## See also