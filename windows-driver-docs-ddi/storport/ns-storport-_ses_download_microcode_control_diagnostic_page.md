# _SES_DOWNLOAD_MICROCODE_CONTROL_DIAGNOSTIC_PAGE structure (storport.h)

## Description

The **SES_DOWNLOAD_MICROCODE_CONTROL_DIAGNOSTIC_PAGE** structure contains a vendor specific microcode (i.e., firmware) image
for use by the enclosure services process.

## Members

### `PageCode`

Specifies the diagnostic page being sent or requested based on the value. For a Microcode Control diagnostic page, the value should be 0x0E.

### `SubEnclosureId`

Specifies the sub enclosure to which the application client is
sending the microcode image. If the value does not match a valid SUBENCLOSURE_IDENTIFIER field value found in the [SES_CONFIGURATION_DIAGNOSTIC_PAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_ses_configuration_diagnostic_page), then the enclosure services
process shall abort the download microcode operation with a status of 0x80.

### `PageLength`

Specifies the number of bytes that follow in the diagnostic page.

### `ExpectedGenerationCode`

Specifies the expected value of the generation code. If this parameter is not set to the current generation code, then the enclosure services
process shall abort the download microcode operation with a status of 0x80.

### `Mode`

Specifies which mode to download the microcode with.

| Value | Meaning |
| --- | --- |
| **Download microcode with offsets, save, and activate**<br><br>0x07 | After the last SEND DIAGNOSTIC command delivers a Download Microcode Control diagnostic page to the subenclosure completes, the enclosure services process shall verify the complete microcode image (e.g., perform a vendor specific checksum) and save the new microcode image into nonvolatile storage.<br><br> If there are no errors in the microcode image or in the save operation, then the enclosure services process shall perform one of the following actions:<br><br>* Set the *Status* field in [SES_DOWNLOAD_MICROCODE_STATUS_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_ses_download_microcode_status_descriptor) to 0x10, if   requested, and activate the new microcode image after either returning the Download Microcode Status diagnostic page, power on, or for standalone enclosure services processes, a hard reset.<br>* Set the *Status* field in [SES_DOWNLOAD_MICROCODE_STATUS_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_ses_download_microcode_status_descriptor) to 0x11, if   requested, and for standalone enclosure services processes only,   activate the new microcode image after either power on or hard reset.<br>* Set the *Status* field in [SES_DOWNLOAD_MICROCODE_STATUS_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_ses_download_microcode_status_descriptor) to 0x12, if   requested, and activate the new microcode image after power on. |
| **Download microcode with offsets, save, and defer activate**<br><br>0x0E | After the last SEND DIAGNOSTIC command delivering a **SES_DOWNLOAD_MICROCODE_CONTROL_DIAGNOSTIC_PAGE** to the subenclosure completes, the enclosure services process shall verify the complete microcode image (e.g., perform a vendor specific checksum), save the new microcode image into nonvolatile storage (e.g., flash ROM), and defer activation of the new microcode.<br><br>If there are no errors in the microcode image or in the save operation, then the enclosure services process shall set the *Status* field in [SES_DOWNLOAD_MICROCODE_STATUS_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_ses_download_microcode_status_descriptor) to 0x13 in the [SES_DOWNLOAD_MICROCODE_STATUS_DIAGNOSTIC_PAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_ses_download_microcode_status_diagnostic_page), if requested, and activate the new microcode after either:<br><br>* Processing this structure with the   *Mode* field set to 0x0F (i.e., Activate deferred   microcode)<br>* A power on<br>* A hard reset |
| **Activate deferred microcode**<br><br>0x0F | After the SEND DIAGNOSTIC command specifying this mode completes, the enclosure services process shall activate the deferred microcode image, if any. |
| **Reserved**<br><br>All other values | Reserved for future use. |

### `Reserved`

Reserved for future use.

### `BufferID`

Specifies a specific buffer within the enclosure services process to receive the microcode
image. The enclosure services process assigns vendor specific buffer ID codes to buffers (e.g., the main
firmware image may be stored in buffer 00h and a backup firmware image may be stored in buffer 01h). The
enclosure services process shall support a buffer ID value of 00h. If more than one buffer is supported, then
the enclosure services process shall assign additional buffer ID codes contiguously, beginning with 01h. If the
enclosure services process receives an unsupported buffer ID code, then it shall abort the download
microcode operation and set the *Status* field in [SES_DOWNLOAD_MICROCODE_STATUS_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_ses_download_microcode_status_descriptor) to 0x80 in the [SES_DOWNLOAD_MICROCODE_STATUS_DIAGNOSTIC_PAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_ses_download_microcode_status_diagnostic_page) structure.

### `BufferOffset`

Specifies the offset in bytes within the buffer to which the microcode data is written in multiples of four. The enclosure services process may require that this field be contiguously increasing in consecutive SEND DIAGNOSTIC commands.

### `ImageLength`

specifies the total number of bytes in the microcode image the application
intends to send to the specified *BufferID*.

### `DataLength`

Specifies the length of *Data*, in bytes.

### `Data`

Contains part of the vendor specific microcode image.