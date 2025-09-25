# _SES_DOWNLOAD_MICROCODE_STATUS_DIAGNOSTIC_PAGE structure (scsi.h)

## Description

The Download Microcode Status diagnostic page includes information about the status of one or more
download microcode operations.

## Members

### `PageCode`

Indicates the diagnostic page being sent or requested. . The value of this is 0x0E.

### `NumberOfSecondarySubEnclosures`

Indicates the number of download microcode status
descriptors in *Descriptors*, not including the primary [SES_DOWNLOAD_MICROCODE_STATUS_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_ses_download_microcode_status_descriptor). This value shall
be set to the same value as the *NumberOfSecondarySubEnclosures* field in the [SES_CONFIGURATION_DIAGNOSTIC_PAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_ses_configuration_diagnostic_page) structure.

### `PageLength`

Indicates the number of bytes that follow in the diagnostic page.

### `GenerationCode`

Indicates the value of the generation code

### `Descriptors`

Contains a [SES_DOWNLOAD_MICROCODE_STATUS_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_ses_download_microcode_status_descriptor) for each
download microcode operation where status is being reported.