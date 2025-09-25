# CDROM_READ_TOC_EX structure

## Description

When drivers query a target CD-ROM device with [IOCTL_CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_toc_ex) they must define the query with this structure.

## Members

### `Format`

Specifies table of contents read operation, as follows:

| Operation | Description |
| --------- | ----------- |
| CDROM_READ_TOC_EX_FORMAT_TOC | Query the device for the table of contents for the specified session(s). The **SessionTrack** member of the structure specifies the starting track number of the session for which the data will be returned. For multi-session CD-ROMs, this command will return the table of contents data for all sessions. For track number 0xAA, it returns the lead-out area of the last complete session. The output data is reported in a [CDROM_TOC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc) structure. |
| CDROM_READ_TOC_EX_FORMAT_SESSION | Query the device for the first complete session number, the last complete session number, and the last complete session starting address. The output data is reported in a [CDROM_TOC_SESSION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_session_data) structure. With this format, the **SessionTrack** member is reserved and must be set to zero. This format provides the initiator with quick access to the last finalized session starting address. |
| CDROM_READ_TOC_EX_FORMAT_FULL_TOC | Query the device for all Q subcode data in the lead-in table of contents areas starting from the session number specified in the **SessionTrack** member. The output data is reported in a header structure, [CDROM_TOC_FULL_TOC_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_full_toc_data), followed by a series of track descriptors defined in [CDROM_TOC_FULL_TOC_DATA_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_full_toc_data_block). In this format, logical block addressing (LBA) is not defined, and the **Msf** member must be set to 1. |
| CDROM_READ_TOC_EX_FORMAT_PMA | Query the device for all Q subcode data in the *program memory area* (PMA). The output data is reported in a [CDROM_TOC_PMA_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_pma_data) structure. In this format, the **SessionTrack** member is reserved and must be set to zero. Logical block addressing (LBA) is not defined, and the **Msf** member must be set to 1. |
| CDROM_READ_TOC_EX_FORMAT_ATIP | Query the device for *absolute time in pregroove* (ATIP) data. The output data is reported in the [CDROM_TOC_ATIP_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_atip_data) structure. In this format, the **SessionTrack** member is reserved and must be set to zero. Logical block addressing (LBA) is not defined, and the **Msf** member must be set to 1. |
| CDROM_READ_TOC_EX_FORMAT_CDTEXT | Query the device for CD-TEXT information that is recorded in the lead-in area as R-W subchannel data. The output data is reported in a [CDROM_TOC_CD_TEXT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_cd_text_data) structure with an appended array of [CDROM_TOC_CD_TEXT_DATA_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_cd_text_data_block) structures. |

### `Reserved1`

Reserved.

### `Msf`

Indicates the minute-second-frame bit. When set to one, this bit indicates that minute-second-frame (MSF) addressing must be used. When zero, it indicates that logical block addressing (LBA) must be used.

### `SessionTrack`

Specifies the starting track number for which the data will be returned, the session for which the command is targeted, or a reserved field that drivers should set to zero. Which of these values **SessionTrack** takes depends on the value of the **Format** member.

### `Reserved2`

Reserved.

### `Reserved3`

Reserved.

## Remarks

For further information and definitions of terms used in this reference page and in the reference pages of related structures, see specification *T10/1363-D*, by National Committee for Information Technology Standards (NCITS).

## See also

[CDROM_TOC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc)

[CDROM_TOC_ATIP_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_atip_data)

[CDROM_TOC_CD_TEXT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_cd_text_data)

[CDROM_TOC_CD_TEXT_DATA_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_cd_text_data_block)

[CDROM_TOC_FULL_TOC_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_full_toc_data)

[CDROM_TOC_FULL_TOC_DATA_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_full_toc_data_block)

[CDROM_TOC_PMA_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_pma_data)

[CDROM_TOC_SESSION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_session_data)

[IOCTL_CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_toc_ex)