# NVME_IDENTIFY_CONTROLLER_DATA structure

## Description

Contains values that indicate controller capabilities, features, command set attributes, and power state descriptors.

## Members

### `VID`

Contains the company vendor identifier that is assigned by the [Peripheral Component Interconnect - Special Interest Group (PCI-SIG)](https://pcisig.com/).

### `SSVID`

Contains the company vendor identifier that is assigned by the PCI-SIG for the subsystem.

### `SN`

Contains the serial number for the NVM subsystem that is assigned by the vendor as an ASCII string.

### `MN`

Contains the model number for the NVM subsystem that is assigned by the vendor as an ASCII string.

### `FR`

Contains the currently active firmware revision for the NVM subsystem.

This is the same firmware revision information in the [NVME_FIRMWARE_SLOT_INFO_LOG](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_firmware_slot_info_log) that can be retrieved with the Get Log Page command.

### `RAB`

Contains the recommended Arbitration Burst size.

### `IEEE`

Contains the Organization Unique Identifier (OUI) for the controller vendor.

The OUI is a valid IEEE/RAC assigned identifier that can be registered at http://standards.ieee.org/develop/regauth/oui/public.html.

### `CMIC`

A Controller Multi-Path I/O and Namespace Sharing Capabilities (CMIC) structure that specifies the multi-path I/O and namespace sharing capabilities of the controller and NVM subsystem.

### `CMIC.MultiPCIePorts`

Bit 0 of the **CMIC** structure.

When this value is set to `1`, the NVM subsystem may contain two or more physical PCI Express ports. When the value is cleared to `0`, the NVM subsystem contains a single PCI Express port.

### `CMIC.MultiControllers`

Bit 1 of the **CMIC** structure.

When this value is set to `1`, the NVM subsystem may contain two or more controllers. When the value is cleared to `0`, the NVM subsystem contains a single controller.

### `CMIC.SRIOV`

Bit 2 of the **CMIC** structure.

When this value is set to `1`, the controller is associated with an Single-root I/O virtualization (SR-IOV) Virtual Function. When the value is cleared to `0`, the controller is associated with a PCI Function.

### `CMIC.Reserved`

Bits 3:7 of the **CMIC** structure are reserved.

### `MDTS`

Indicates the maximum data transfer size between the host and the controller.

The host should not submit a command that exceeds this transfer size. If a command is submitted that exceeds the transfer size, the command is aborted with a status of [NVME_STATUS_INVALID_FIELD_IN_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_generic_command_codes#field-nvme-status-invalid-field-in-command).

The value of this field is in units of the minimum memory page size specified in the **MPSMIN** field of the [Controller Capabilities](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_capabilities) structure, and is reported as a power of two (2^n). A value of `0h` indicates no restrictions on transfer size. The restriction includes metadata if it is interleaved with the logical block data.

If SGL Bit Bucket descriptors are supported, their lengths are included in determining if a command exceeds the Maximum Data Transfer Size for destination data buffers. Their length in a source data buffer is not included for a Maximum Data Transfer Size calculation.

### `CNTLID`

Contains the NVM subsystem unique controller identifier associated with the controller.

### `VER`

Contains the value reported in the Version register, defined in the **VS** field of the [NVME_CONTROLLER_REGISTERS](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_registers) structure.

Implementations that are compliant with NVMe specification version 1.2 or later, will report a non-zero value in this field.

### `RTD3R`

Indicates the typical latency in microseconds when resuming from Runtime D3 (RTD3).

Implementations that are compliant with NVMe specification version 1.2 or later, will report a non-zero value in this field.

### `RTD3E`

Indicates the typical latency in microseconds to enter Runtime D3 (RTD3).

Implementations that are compliant with NVMe specification version 1.2 or later, will report a non-zero value in this field.

### `OAES`

An Optional Asynchronous Events Supported (OAES) structure containing fields that indicate whether optional asynchronous events are supported by the controller.

A controller should not send optional asynchronous events before they are enabled by host software.

### `OAES.Reserved0`

Bits 10:31 of the **OAES** structure are reserved.

### `OAES.NamespaceAttributeChanged`

Bit 8 of the **OAES** structure.

When this value is set to `1`, the controller supports sending the Namespace Attribute Changed event. When this value is cleared to `0`, the controller does not support the Namespace Attribute Changed event.

### `OAES.FirmwareActivation`

Bit 9 of the **OAES** structure.

When this value is set to `1`, the controller supports sending the Firmware Activation event. When this value is cleared to `0`, the controller does not support the Firmware Activation event.

### `OAES.Reserved1`

Bits 0:7 of the **OAES** structure are reserved.

### `CTRATT`

A Controller Attributes (CTRATT) structure containing controller attribute information.

### `CTRATT.HostIdentifier128Bit`

Bit 32 of the **CTRATT** structure containing a 128bit host identifier.

### `CTRATT.NOPSPMode`

Bit 31 of the **CTRATT** structure containing information about the Non-Operational Power State (NOPS).

### `CTRATT.NVMSets`

Bit 30 of the **CTRATT** structure containing information about NVM command sets.

### `CTRATT.ReadRecoveryLevels`

Bit 29 of the **CTRATT** structure containing information about Read recovery levels.

### `CTRATT.EnduranceGroups`

Bit 28 of the **CTRATT** structure containing information about endurance groups levels.

### `CTRATT.Reserved0`

Bits 0:27 of the **CTRATT** structure are reserved.

### `Reserved0`

A reserved field of 140 bytes.

### `ReservedForManagement`

Reserved for NVMe Management.

### `OACS`

An Optional Admin Command Support (OACS) structure containing fields that indicate the optional [Admin Commands](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_admin_commands) supported by the controller.

### `OACS.SecurityCommands`

Bit 0 of the **OACS** structure indicates whether the controller supports the Security Send and Security Receive commands.

When this value is set to `1`, the controller supports the Security Send and Security Receive commands. When this value is cleared to `0`, the controller does not support the Security Send and Security Receive commands.

### `OACS.FormatNVM`

Bit 1 of the **OACS** structure indicates whether the controller supports the Format NVM command.

When this value is set to `1`, the controller supports the Format NVM command. When this value is cleared to `0`, the controller does not support the Format NVM command.

### `OACS.FirmwareCommands`

Bit 2 of the **OACS** structure indicates whether the controller supports the Firmware Commit and Firmware Image Download commands.

When this value is set to `1`, the controller supports the Firmware Commit and Firmware Image Download commands. When this value is cleared to `0`, the controller does not support the Firmware Commit and Firmware Image Download commands.

### `OACS.NamespaceCommands`

Bit 3 of the **OACS** structure indicates whether the controller supports the Namespace Management and Namespace Attachment commands.

When this value is set to `1`, the controller supports the Namespace Management and Namespace Attachment commands. When this value is cleared to `0`, the controller does not support the Namespace Management and Namespace Attachment commands.

### `OACS.DeviceSelfTest`

Bit 4 of the **OACS** structure indicates whether the controller supports the Device Self Test command.

### `OACS.Directives`

Bit 5 of the **OACS** structure indicates whether the controller supports the Directive Send and Directive Receive commands.

### `OACS.Reserved`

Bits 6:15: are reserved.

### `ACL`

Indicates the maximum number of concurrently outstanding [Abort](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_abort) commands supported by the controller.

This is a 0’s based value. Implementations should support a minimum of four outstanding Abort commands simultaneously.

### `AERL`

Indicates the maximum number of concurrently outstanding [Asynchronous Event Request](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_async_event_types) commands supported by the controller.

This is a 0’s based value. Implementations should support a minimum of four outstanding Asynchronous Event Request commands simultaneously.

### `FRMW`

A Firmware Updates (FRMW) structure containing fields that indicate capabilities regarding firmware updates.

### `FRMW.Slot1ReadOnly`

Bit 0 of the **FRMW** structure indicates whether the first firmware slot (slot 1) is read only.

When this value is set to `1`, the first firmware slot (slot 1) is read only. When this value is cleared to `0`, the first firmware slot (slot 1) is read/write. Implementations may choose to have a baseline read only firmware image.

### `FRMW.SlotCount`

Bits 1:3 of the **FRMW** structure indicate the number of firmware slots that the controller supports.

This field specifies a value between one and seven, indicating that at least one firmware slot is supported and up to seven maximum. This corresponds to firmware slots 1 through 7.

### `FRMW.ActivationWithoutReset`

Bit 4 of the **FRMW** structure indicates whether the controller supports firmware activation without a reset.

When this value is set to `1`, the controller supports firmware activation without a reset. When this value is cleared to `0`, the controller requires a reset for firmware to be activated.

### `FRMW.Reserved`

Bits 5:7 of the **FRMW** structure are reserved.

### `LPA`

A Log Page Attributes (LPA) structure containing fields that indicate optional attributes for log pages that are accessed by using the [Get Log Page](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page) command.

### `LPA.SmartPagePerNamespace`

Bit 0 of the **LPA** structure indicates whether the controller supports the SMART / Health information log page on a per namespace basis.

When this value is set to `1`, the controller supports the SMART / Health information log page on a per namespace basis. When this value is cleared to `0`, the controller does not support the SMART / Health information log page on a per namespace basis.

### `LPA.CommandEffectsLog`

Bit 1 of the **LPA** structure indicates whether the controller supports the Command Effects log page.

When this value is set to `1`, the controller supports the Command Effects log page. When this value is cleared to `0`, the controller does not support the Command Effects log page.

### `LPA.LogPageExtendedData`

Bit 2 of the **LPA** structure indicates whether the controller supports Log Page Extended Data.

### `LPA.TelemetrySupport`

Bit 3 of the **LPA** structure indicates whether the controller supports Telemetry Support.

### `LPA.Reserved`

Bits 4:7 of the **LPA** structure are reserved.

### `ELPE`

Indicates the number of Error Information log entries that are stored by the controller. This field is a 0’s based value.

### `NPSS`

Indicates the number of NVM Express power states supported by the controller. This is a 0’s based value.

Power states are numbered sequentially starting at power state 0. A controller must support at least one power state (for example, power state 0), and may support up to 31 additional power states, for a total of 32.

### `AVSCC`

An Admin Vendor Specific Command Configuration (AVSCC) structure containing fields that indicate the configuration settings for Admin Vendor Specific command handling.

### `AVSCC.CommandFormatInSpec`

Bit 0 of the **AVSCC** structure indicates whether all Admin Vendor Specific Commands use the command format defined in the [NVME_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

When this value is cleared to `0`, it indicates that the format of all Admin Vendor Specific Commands are vendor specific.
When this value is set to `1`, it indicates that all Admin Vendor Specific Commands will use the [NVME_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

### `AVSCC.Reserved`

Bits 1:7 of the **AVSCC** structure are reserved.

### `APSTA`

An Autonomous Power State Transition Attributes (APSTA) structure containing fields that indicate the attributes of the [autonomous power state transition feature](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_feature_auto_power_state_transition).

### `APSTA.Supported`

Bit 0 of the **APSTA** structure indicates whether the controller supports autonomous power state transitions.

When this value is set to `1`, the controller supports autonomous power state transitions. When this value is cleared to `0`, the controller does not support autonomous power state transitions.

### `APSTA.Reserved`

Bits 1:7 of the **APSTA** structure are reserved.

### `WCTEMP`

Indicates the minimum Composite Temperature field value (reported in the [SMART / Health Information](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_health_info_log) log) that indicates an overheating condition during which controller operation continues.

Immediate remediation is recommended (for example, additional cooling or workload reduction). The platform should strive to maintain a composite temperature below this value.

A value of `0h` in this field indicates that no warning temperature threshold value is reported by the controller. Implementations compliant to NVMe Spec version 1.2 or later should report a non-zero value in this field. It is recommended that implementations report a value of `0157h` in this field.

### `CCTEMP`

Indicates the minimum Composite Temperature field value (reported in the [SMART / Health Information](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_health_info_log.md log) that indicates a critical overheating condition. For example, a condition that may prevent continued normal operation, possibility of data loss, automatic device shutdown, extreme performance throttling, or permanent damage.

A value of `0h` in this field indicates that no critical temperature threshold value is reported by the controller. Implementations compliant to NVMe Spec version 1.2 or later should report a non-zero value in this field.

### `MTFA`

Indicates the maximum time the controller temporarily stops processing commands to activate the firmware image.

This field is valid if the controller supports firmware activation without a reset. The **MFTA** value is specified in 100 millisecond units. A value of `0h` indicates that the maximum time is undefined.

### `HMPRE`

Indicates the preferred size that the host should allocate for the [Host Memory Buffer](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_feature_host_memory_buffer) feature in 4KB units.

This value must be larger than or equal to the Host Memory Buffer Minimum Size (**HMMIN**).

If this field is non-zero, then the Host Memory Buffer feature is supported. When this value is cleared to `0h`, the Host Memory Buffer feature is not supported.

### `HMMIN`

Indicates the minimum size that the host should allocate for the Host Memory Buffer feature in 4KB units.

When this value is cleared to `0`, the host is requested to allocate any amount of host memory possible up to the **HMPRE** value.

### `TNVMCAP`

Indicates the total NVM capacity, in bytes, of the NVM subsystem.

This field is supported if the Namespace Management and Namespace Attachment commands are supported.

### `UNVMCAP`

Indicates the unallocated NVM capacity, in bytes, of the NVM subsystem.

This field is supported if the Namespace Management and Namespace Attachment commands are supported.

### `RPMBS`

A Replay Protected Memory Block Support (RPMBS) structure containing fields that indicate whether the controller supports one or more Replay Protected Memory Blocks (RPMBs) and the associated capabilities.

### `RPMBS.RPMBUnitCount`

Indicates the number of RPMB targets the controller supports.

All supported (Protected Memory Block) PMB targets have the same capabilities as defined in the **RPMBS** field. A value of `0h` indicates the controller does not support RPMBs. If this value is non-zero, then the controller supports the Security Send and Security Receive commands.

### `RPMBS.AuthenticationMethod`

Indicates the authentication method used to access all Replay Protected Memory Blocks (RPMBs) in the controller. The values for this field are:

| Value | Definition |
|------------|--------------|
| 000b | HMAC SHA-256 |
| 001b-111b | Reserved |

### `RPMBS.Reserved0`

A reserved field.

### `RPMBS.TotalSize`

Indicates the total size of each RPMB supported in the controller in 128KB units. This is a 0’s based value. A value of `0h` indicates a size of 128KB.

### `RPMBS.AccessSize`

Indicates the size that may be read or written per RPMB access by the Security Send or Security Receive commands for this controller in 512B units.

This is a 0’s based value. A value of `0h` indicates a size of 512B.

### `EDSTT`

Indicates the Extended Device Self-test Time (EDSTT).

### `DSTO`

Indicates the Device Self-test Options (DSTO).

### `FWUG`

Indicates the Firmware Update Granularity (FWUG).

### `KAS`

Indicates the Keep Alive Support (KAS).

### `HCTMA`

A Host Controlled Thermal Management Attributes (HCTMA) structure.

### `HCTMA.Supported`

Indicates whether Host Controlled Thermal Management attributes are supported.

### `HCTMA.Reserved`

This **HCTMA** structure field is reserved.

### `MNTMT`

Minimum Thermal Management Temperature (MNTMT)

### `MXTMT`

Maximum Thermal Management Temperature (MXTMT)

### `SANICAP`

Sanitize Capabilities (SANICAP)

### `SANICAP.CryptoErase`

Controller supports Crypto Erase Sanitize

### `SANICAP.BlockErase`

Controller supports Block Erase Sanitize

### `SANICAP.Overwrite`

Controller supports Overwrite Santize

### `SANICAP.Reserved`

### `NSETIDMAX`

NVM Set Identifier Maximum

### `Reserved1`

A reserved field.

### `SQES`

A Submission Queue Entry Size (SQES) structure containing fields that indicate the required and maximum Submission Queue entry size when using the NVM Command Set.

### `SQES.RequiredEntrySize`

Bits 0:3 of the **SQES** structure indicate the required Submission Queue Entry size when using the NVM Command Set.

This is the minimum entry size that can be used. The value is in bytes and is reported as a power of two (2^n). The required value is 6, which corresponds to 64 bytes.

### `SQES.MaxEntrySize`

Bits 4:7 of the **SQES** structure indicate the maximum Submission Queue entry size when using the NVM Command Set.

This value is larger than or equal to the **SQES.RequiredEntrySize** value. The value is in bytes and is reported as a power of two (2^n). The recommended value is 6, corresponding to a standard NVM Command Set SQ entry size of 64 bytes. Controllers that implement proprietary extensions may support a larger value.

### `CQES`

A Completion Queue Entry Size (CQES) structure containing fields that indicate the required and maximum Completion Queue entry size when using the NVM Command Set.

### `CQES.RequiredEntrySize`

Bits 0:3 of the **CQES** structure indicate the required Completion Queue entry size when using the NVM Command Set.

This is the minimum entry size that can be used. The value is in bytes and is reported as a power of two (2^n). The required value is 4, which corresponds to 16 bytes.

### `CQES.MaxEntrySize`

Bits 4:7 of the **CQES** structure indicate the maximum Completion Queue entry size when using the NVM Command Set.

This value is larger than or equal to the required CQ entry size. The value is in bytes and is reported as a power of two (2^n). The recommended value is 4, corresponding to a standard NVM Command Set CQ entry size of 16 bytes. Controllers that implement proprietary extensions may support a larger value.

### `Reserved2`

### `NN`

Indicates the number of valid namespaces present for the controller.

### `ONCS`

An Optional NVM Command Support (ONCS) structure containing fields that indicate the optional [NVM commands](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_nvm_commands) and features supported by the controller.

### `ONCS.Compare`

Bit 0 of the **ONCS** structure indicates whether the controller supports the Compare command.

When this value is set to `1`, the controller supports the Compare command. When this value is cleared to `0`, the controller does not support the Compare command.

### `ONCS.WriteUncorrectable`

Bit 1 of the **ONCS** structure indicates whether the controller supports the Write Uncorrectable command.

When this value is set to `1`, the controller supports the Write Uncorrectable command. When this value is cleared to `0`, the controller does not support the Write Uncorrectable command.

### `ONCS.DatasetManagement`

Bit 2 of the **ONCS** structure indicates whether the controller supports the Dataset Management command.

When this value is set to `1`, the controller supports the Dataset Management command. When this value is cleared to `0`, the controller does not support the Dataset Management command.

### `ONCS.WriteZeroes`

Bit 3 of the **ONCS** structure indicates whether the controller supports the Write Zeroes command.

When this value is set to `1`, the controller supports the Write Zeroes command. When this value is cleared to `0`, the controller does not support the Write Zeroes command.

### `ONCS.FeatureField`

Bit 4 of the **ONCS** structure indicates whether the controller supports the Save field in the Set Features command and the Select field in the Get Features command.

When this value is set to `1`, the controller supports the Save field in the Set Features command and the Select field in the Get Features command.
When this value is cleared to `0`, the controller does not support the Save field in the Set Features command and the Select field in the Get Features command.

### `ONCS.Reservations`

Bit 5 of the **ONCS** structure indicates whether the controller supports reservations.

When this value is set to `1`, the controller supports reservations and also supports the following commands associated with reservations:

- Reservation Report
- Reservation Register
- Reservation Acquire
- Reservation Release

When this value is cleared to `0`, the controller does not support reservations.

### `ONCS.Timestamp`

Bit 6 of the **ONCS** structure indicates whether the controller supports the [Timestamp (NVME_FEATURE_TIMESTAMP)](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_features) feature.

### `ONCS.Reserved`

Bits 7:15 of the **ONCS** structure are reserved.

### `FUSES`

A Fused Operation Support (FUSES) structure containing fields that indicate the fused operations that the controller supports.

### `FUSES.CompareAndWrite`

Bit 0 of the **FUSES** structure indicates whether the controller supports the Compare and Write fused operation.

When this value is cleared to `0`, the controller does not support the Compare and Write fused operation. Compare will be the [first command in the sequence](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_fused_operation_codes).

### `FUSES.Reserved`

Bits 15:1 of the **FUSES** structure are reserved.

### `FNA`

A Format NVM Attributes (FNA) structure containing fields that indicate attributes for the [Format NVM](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_format_nvm) command.

### `FNA.FormatApplyToAll`

Bit 0 of the **FNA** structure indicates whether the format operation applies to all namespaces or is specific to a particular namespace.

When this value is set to `1`, all namespaces are configured with the same attributes and a format of any namespace results in a format of all namespaces.
When this value is cleared to `0`, the controller supports format on a per namespace basis.

### `FNA.SecureEraseApplyToAll`

Bit 1 of the **FNA** structure indicates whether cryptographic erase and user data erase functionality apply to all namespaces or is specific to a particular namespace.

When this value is set to `1`, a cryptographic erase of a particular namespace as part of a format results in a cryptographic erase of all namespaces, and a user data erase of a particular namespace as part of a format results in a user data erase of all namespaces.
When this value is cleared to `0`, a cryptographic erase or user data erase as part of a format is performed on a per namespace basis.

### `FNA.CryptographicEraseSupported`

Bit 2 of the **FNA** structure indicates whether cryptographic erase is supported as part of the secure erase functionality.

When this value is set to `1`, cryptographic erase is supported. When this value is cleared to `0`, cryptographic erase is not supported.

### `FNA.Reserved`

Bits 7:3 of the **FNA** structure are reserved.

### `VWC`

A Volatile Write Cache (VWC) structure containing fields that indicate attributes related to the presence of a volatile write cache in the implementation.

### `VWC.Present`

Bit 0 of the **VWC** structure indicates that a volatile write cache is present.

When this value is set to `1`, a volatile write cache is present and the host may issue Flush commands, and control whether the volatile write cache is enabled with the [Set Features](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_set_features) command specifying the [NVME_FEATURE_VOLATILE_WRITE_CACHE](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_features#field-nvme-feature-volatile-write-cache) feature identifier.

When this value is cleared to `0`, a volatile write cache is not present.

When a volatile write cache is not present, Flush commands complete successfully and have no effect, and the Set Features command with the **NVME_FEATURE_VOLATILE_WRITE_CACHE** identifier set will fail with a status of [NVME_STATUS_INVALID_FIELD_IN_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_generic_command_codes), and [Get Features](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_features) with the **NVME_FEATURE_VOLATILE_WRITE_CACHE** identifier set will fail with a status of **NVME_STATUS_INVALID_FIELD_IN_COMMAND**.

### `VWC.Reserved`

Bits 1:7 of the **VWC** structure are reserved.

### `AWUN`

Indicates the size of the write operation guaranteed to be written atomically to the NVM across all namespaces with any supported namespace format during normal operation. This field is specified in logical blocks and is a 0’s based value.

If a specific namespace guarantees a larger size than is reported in this field, then this namespace specific size is reported in the **NAWUN** field of the [Identify Namespace](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data) data structure.

If a write command is submitted with size less than or equal to the **AWUN** value, the host is guaranteed that the write command is atomic to the NVM with respect to other read or write commands. If a write command is submitted with size greater than the **AWUN** value, then there is no guarantee of command atomicity.

The **AWUN** value does not have any applicability to write errors caused by power failure. For more information, see the Atomic Write Unit Power Fail (**AWUPF**) field.

A value of `FFFFh` indicates all commands are atomic as this is the largest command size. Implementations should support a minimum of 128KB, appropriately scaled based on the Logical Block Access (LBA) size.

### `AWUPF`

Indicates the size of the write operation guaranteed to be written atomically to the NVM across all namespaces with any supported namespace format during a power fail or error condition. This field is specified in logical blocks and is a 0’s based value.

If a specific namespace guarantees a larger size than is reported in this field, then this namespace specific size is reported in the **NAWUPF** field in the [Identify Namespace](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data) data structure. The **AWUPF** value must be less than or equal to the **AWUN** value.

If a write command is submitted with size less than or equal to the **AWUPF** value, the host is guaranteed that the write is atomic to the NVM with respect to other read or write commands. If a write command is submitted that is greater than this size, there is no guarantee of command atomicity. If the write size is less than or equal to the **AWUPF** value and the write command fails, then subsequent read commands for the associated logical blocks will return data from the previous successful write command.

If a write command is submitted with size greater than the **AWUPF** value, then there is no guarantee of data returned on subsequent reads of the associated logical blocks.

### `NVSCC`

A NVM Vendor Specific Command Configuration (NVSCC) structure containing fields that indicate the configuration settings for NVM Vendor Specific command handling.

### `NVSCC.CommandFormatInSpec`

Bit 0 of the **NVSCC** structure indicates whether all NVM Vendor Specific Commands use the format defined in Figure 13.

When this value is set to `1`, all NVM Vendor Specific Commands use the format defined in Figure 13. When this value is cleared to `0`, it indicates that the format of all NVM Vendor Specific Commands are vendor specific.

### `NVSCC.Reserved`

Bits 1:7 of the **NVSCC** structure are reserved.

### `Reserved3`

A reserved field.

### `ACWU`

Indicates the size of the write operation guaranteed to be written atomically to the NVM across all namespaces with any supported namespace format for a Compare and Write fused operation.

If a specific namespace guarantees a larger size than is reported in this field, then this namespace specific size is reported in the **NACWU** field in the [Identify Namespace](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data) data structure.

This field will be supported if the Compare and Write fused command is supported. This field is specified in logical blocks and is a 0’s based value. If a Compare and Write is submitted that requests a transfer size larger than this value, the controller may fail the command with a status of [NVME_STATUS_INVALID_FIELD_IN_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_generic_command_codes).

If Compare and Write is not a supported fused command, the value of this field will be `0h`.

### `Reserved4`

A reserved field.

### `SGLS`

A SGL Support (SGLS) structure containing fields that specify whether Scatter Gather Lists (SGL) are supported for the NVM Command Set and the supported SGL types.

### `SGLS.SGLSupported`

When this value is set to `1`, the controller supports SGLs for the NVM Command Set including the SGL Data Block, SGL Segment, and SGL Last Segment descriptor types. When this value is cleared to `0`, the controller does not support SGLs for the NVM Command Set and all other bits in this field will be cleared to `0`.

### `SGLS.Reserved0`

A reserved field.

### `SGLS.BitBucketDescrSupported`

When this value is set to `1`, the SGL Bit Bucket descriptor is supported. When this value is cleared to `0`, the SGL Bit Bucket descriptor is not supported.

### `SGLS.ByteAlignedContiguousPhysicalBuffer`

When this value is set to `1`, the use of a byte aligned contiguous physical buffer of metadata (the Metadata Pointer field in Figure 12) is supported. When this value is cleared to `0`, the use of a byte aligned contiguous physical buffer of metadata is not supported.

### `SGLS.SGLLengthLargerThanDataLength`

When this value is set to `1`, the controller supports commands that contain a data or metadata SGL of a length larger than the amount of data to be
transferred. When this value is cleared to `0`, the SGL length will be equal to the amount of data to be transferred.

### `SGLS.Reserved1`

A reserved field.

### `Reserved5`

Bytes 540:703 are reserved.

### `Reserved6`

Bytes 704:2047 are reserved for I/O Command Set Attributes.

### `PDS`

Contains an array of 32 Power State Descriptors. Each member of the array is a 32 bit field that indicates the characteristics of a Power State Descriptor. The format of this field is defined in the [NVME_POWER_STATE_DESC](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_power_state_desc) structure.

The zero-based position of a structure in the array corresponds to the name of the Power State Descriptor, such that Power State 0 Descriptor (PSD0) is in position 0, Power State 1 Descriptor (PSD1) is in position 1, and so on, up to Power State 31 Descriptor (PSD31) in position 31.

### `VS`

Bytes 3072:4095 are allocated for vendor specific usage.

## Remarks

The values of the **VID**, **SN**, and **MN** fields may be combined to form a globally unique value that identifies the NVM subsystem.

## See also