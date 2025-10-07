# SENSE\_DATA structure

Used to report status or error information in response to a SCSI **Request Sense** command.

## Members

**ErrorCode**

The report type.

| Value | Meaning |
|---------------------------------------------------------------------------------|-----------------------------|
| 0x70 | Current errors.<br> |
| 0x71 | Deferred errors.<br> |

**Valid**

1 if the **Information** field is defined in a standard; otherwise the **Information** field is vendor-specific and not defined by a standard.

**SegmentNumber**

Obsolete.

**SenseKey**

Indicates the category of error.

**No Sense** (0x0)

**Recovered Error** (0x1)

**Not Ready** (0x2)

**Medium Error** (0x3)

**Hardware Error** (0x4)

**Illegal Request** (0x5)

**Unit Attention** (0x6)

**Data Protect** (0x7)

**Firmware Error** (0x9)

**Aborted Command** (0xB)

**Equal** (0xC)

**Volume Overflow** (0xD)

**Miscompare** (0xE)

**Reserved**

Reserved.

**IncorrectLength**

1 if the requested logical block length does not match the logical block length of the data on the media.

**EndOfMedia**

1 if a sequential-access device has reached end-of-media, or a printer is out of paper.

**FileMark**

1 if the current command has reached a filemark or setmark. Only valid for sequential-access devices.

**Information**

Device-type or command specific data.

**AdditionalSenseLength**

The length in bytes of the remainder of the structure. The total length minus 7.

**CommandSpecificInformation**

Command-specific data. Values are defined in the appropriate command standard.

**AdditionalSenseCode**

Device specific code that describes the error reported in the **SenseKey** field.

**AdditionalSenseCodeQualifier**

Can contain additional detail about the **AdditionalSenseCode** field.

**FieldReplaceableUnitCode**

Vendor-specific information about the component associated with this sense data.

**SenseKeySpecific**

The content and format of the sense key specific information is determined by the value of the **SenseKey** field.

## Remarks

For more information about the sense data format, see [SCSI Request Sense Command](https://wikipedia.org/wiki/SCSI_command) (https://wikipedia.org/wiki/SCSI_command).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Scsi.h |

## See also

[iSCSI Target Pass-Through](https://learn.microsoft.com/powershell/module/iscsi)

[SCSI\_PASS\_THROUGH\_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct)

