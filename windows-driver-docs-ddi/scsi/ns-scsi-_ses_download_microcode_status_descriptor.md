# _SES_DOWNLOAD_MICROCODE_STATUS_DESCRIPTOR structure (scsi.h)

## Description

The **SES_DOWNLOAD_MICROCODE_STATUS_DESCRIPTOR** structure specifies the status and additional status of a download microcode.

## Members

### `Reserved1`

Reserved for future use.

### `SubEnclosureId`

Specifies the subenclosure to which the download microcode
status descriptor applies to.

### `Status`

 Specifies the status of download microcode
operations for the subenclosure. After reporting a code indicating completion, the
enclosure services process shall set this field to 0x00 and shall
set the *AdditionalStatus* field to 0x00. Status may can contain one of the following values:

| Value | Meaning |
| --- | --- |
| 0x00 | No download microcode operation is in progress. |
| 0x01 | Download microcode operation is in progress. The enclosure services process has received one or more Download Microcode Control diagnostic pages and is awaiting additional microcode data. |
| 0x02 | Download microcode operation data transfer is complete, currently updating nonvolatile storage. |
| 0x03 | The enclosure services process is currently updating nonvolatile storage with deferred microcode. |
| 0x04 to 0x0F | Reserved for codes indicating interim status |
| 0x10 | Download microcode operation complete with no error. The enclosure services process begins using the new microcode after returning this status. |
| 0x11 | Download microcode operation complete with no error. The enclosure services process (e.g., a standalone enclosure services process) begins using the new microcode after the next hard reset or power on. |
| 0x12 | Download microcode operation complete with no error. The enclosure services process (e.g., an attached enclosure services process) begins using the new microcode after the next power on. |
| 0x13 | Download microcode operation complete with no error. The enclosure services process (e.g., an attached enclosure services process) begins using the new microcode after either processing a [SES_DOWNLOAD_MICROCODE_CONTROL_DIAGNOSTIC_PAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_ses_download_microcode_control_diagnostic_page) specifying the activate deferred microcode mode, hard reset, or power on. |
| 0x14 to 0x6F | Reserved for codes indicating no error. |
| 0x70 to 0x7F | Vendor specific |
| 0x80 | Error in one or more of the Download Microcode Control diagnostic page fields. |
| 0x81 | Specifies a Microcode image error. |
| 0x82 | Download microcode timeout. The enclosure services process may discard microcode data after a vendor specific amount of time, if it does not receive the entire microcode image. |
| 0x83 | Internal error in the download microcode operation. New microcode image is needed before a hard reset or power on |
| 0x84 | Internal error in the download microcode operation. Hard reset and power on safe |
| 0x00 | Processed a [SES_DOWNLOAD_MICROCODE_CONTROL_DIAGNOSTIC_PAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_ses_download_microcode_control_diagnostic_page) with the *Mode* field set to 0x0F (i.e., activate deferred microcode), if there is no deferred microcode. |
| 0x86 to 0x0EF | Reserved for codes indicating errors. |
| 0xF0 to 0xFF | Vendor Specific |

### `AdditionalStatus`

Provides an additional status value for certain
values of *Status* .

### `MaximumImageSize`

Indicates the maximum size in bytes of the
microcode image that the enclosure services process accepts. The image may be delivered using one or
more [SES_DOWNLOAD_MICROCODE_CONTROL_DIAGNOSTIC_PAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_ses_download_microcode_control_diagnostic_page).

### `Reserved2`

Reserved for future use.

### `ExpectedBufferId`

Indicates the next value that the
enclosure services process expects in the *BufferId* field in [SES_DOWNLOAD_MICROCODE_CONTROL_DIAGNOSTIC_PAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_ses_download_microcode_control_diagnostic_page).

### `ExpectedBufferOffset`

Indicates the next value that the
enclosure services process expects in the *BufferOffset* field in [SES_DOWNLOAD_MICROCODE_CONTROL_DIAGNOSTIC_PAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_ses_download_microcode_control_diagnostic_page). If the enclosure services process accepts arbitrary *BufferOffset* values, then it shall set *ExpectedBufferOffset* to 0xFFFFFFFF.

## See also

[SES_DOWNLOAD_MICROCODE_CONTROL_DIAGNOSTIC_PAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_ses_download_microcode_control_diagnostic_page)