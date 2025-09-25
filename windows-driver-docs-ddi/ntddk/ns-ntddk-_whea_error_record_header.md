# _WHEA_ERROR_RECORD_HEADER structure

## Description

The WHEA_ERROR_RECORD_HEADER structure describes general information about a hardware error condition.

## Members

### `Signature`

The signature of the error record. This member contains the value 'REPC'.

### `Revision`

A [WHEA_REVISION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_revision) union that describes the revision level of the WHEA_ERROR_RECORD_HEADER structure.

### `SignatureEnd`

The end of the signature of the error record. This member contains the value 0xFFFFFFFF.

### `SectionCount`

The number of sections of error information that are contained in the error record.

### `Severity`

A [WHEA_ERROR_SEVERITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_error_severity)-typed value that indicates the severity of the error condition described by the error record.

### `ValidBits`

A [WHEA_ERROR_RECORD_HEADER_VALIDBITS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_header_validbits) union that specifies which members of the WHEA_ERROR_RECORD_HEADER structure contain valid data.

### `Length`

The length, in bytes, of the error record.

### `Timestamp`

A [WHEA_TIMESTAMP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_timestamp) union that indicates the time that the error was reported to the operating system. This member contains valid data only if the **ValidBits.Timestamp** bit is set.

### `PlatformId`

A GUID that identifies the platform on which the hardware error occurred. This member contains valid data only if the **ValidBits.PlatformId** bit is set.

### `PartitionId`

A GUID that identifies the partition on which the hardware error occurred. This member contains valid data only if the **ValidBits.PartitionId** bit is set.

### `CreatorId`

A GUID that identifies the entity that created the error record. When the Windows kernel creates an error record, it sets this member to WHEA_RECORD_CREATOR_GUID.

### `NotifyType`

A GUID that identifies the notification mechanism by which an error condition is reported to the operating system. The following are the GUIDs for the standard notification types:

#### CMC_NOTIFY_TYPE_GUID

Corrected Machine Check (CMC)

#### CPE_NOTIFY_TYPE_GUID

Corrected Platform Error (CPE)

#### MCE_NOTIFY_TYPE_GUID

Machine Check Exception (MCE)

#### PCIe_NOTIFY_TYPE_GUID

PCI Express (PCIe) Error

#### INIT_NOTIFY_TYPE_GUID

INIT Error Record (INIT)

#### NMI_NOTIFY_TYPE_GUID

Nonmaskable Interrupt (NMI)

#### BOOT_NOTIFY_TYPE_GUID

Boot Error Record (BOOT)

For error notification types that do not conform to one of the standard types in the previous list, a platform-specific GUID can be defined to identify the notification mechanism. If the notification type does not correspond to any of the standard notification types or any platform-specific notification types, this member is set to GENERIC_NOTIFY_TYPE_GUID.

### `RecordId`

The identifier of the error record. This identifier is unique only on the system that created the error record.

### `Flags`

A [**WHEA_ERROR_RECORD_HEADER_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-whea_error_record_header_flags) union that describes the error condition.

### `PersistenceInfo`

A [WHEA_PERSISTENCE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_persistence_info) union that is used by the error record persistence interface.

### `Reserved`

Reserved for system use.

### `OsBuildNumber`

### `Reserved2`

## Remarks

A WHEA_ERROR_RECORD_HEADER structure is contained within the [WHEA_ERROR_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record) structure. The WHEA_ERROR_RECORD_HEADER structure describes general information about the hardware error condition that is described by the error record.

## See also

[WHEA_ERROR_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record)

[WHEA_ERROR_RECORD_HEADER_VALIDBITS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_header_validbits)

[WHEA_ERROR_SEVERITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_error_severity)

[WHEA_PERSISTENCE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_persistence_info)

[WHEA_REVISION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_revision)

[WHEA_TIMESTAMP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_timestamp)