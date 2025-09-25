# NVME_COMMAND structure

## Description

Contains the parameters for all commands in the Admin Command and NVM Command sets.

## Members

### `CDW0`

A [NVME_COMMAND_DWORD0](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_dword0) structure containing parameters that are common for all Admin and NVM commands.

### `NSID`

The namespace ID that this command applies to.

If the namespace ID is not used for the command, then this field should cleared to `0h`. If a command is applied to all namespaces accessible by this controller, then this field should be set to `FFFFFFFFh`.

Unless otherwise noted, specifying an inactive namespace ID in a command that uses the namespace ID will cause the controller to abort the command with the status [NVME_STATUS_INVALID_FIELD_IN_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_generic_command_codes#-field-nvme-status-invalid-field-in-command). Specifying an invalid namespace ID in a command that uses the namespace ID will cause the controller to abort the command with the status [NVME_STATUS_INVALID_NAMESPACE_OR_FORMAT](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_generic_command_codes#-field-nvme-status-invalid-namespace-or-format).

### `Reserved0`

### `MPTR`

The address of a contiguous physical buffer of metadata.

This field is only used if metadata is not interleaved with the logical block data, as specified in the **MS** field of the [NVME_CDW10_FORMAT_NVM](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_format_nvm) command structure. This field is Dword aligned.

### `PRP1`

A [NVME_PRP_ENTRY](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_prp_entry) structure that contains the first PRP entry for the command or a PRP List pointer depending on the command.

### `PRP2`

This field is reserved if the data transfer does not cross a memory page boundary. Otherwise, it contains a [NVME_PRP_ENTRY](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_prp_entry) structure that:

1. Specifies the Page Base Address of the second memory page if the data transfer crosses exactly one memory page boundary. For example, in one of the following situations:

   - The command data transfer length is equal in size to one memory page and the offset portion of the Page Base Address and Offset (**PBAO**) field of **PRP1** is non-zero.
   - The Offset portion of the **PBAO** field of **PRP1** is equal to zero and the command data transfer length is greater than one memory page and less than or equal to two memory pages in size.

2. Is a PRP List pointer if the data transfer crosses more than one memory page boundary. For example, in one of the following situations:

   - The command data transfer length is greater than or equal to two memory pages in size but the offset portion of the **PBAO** field of **PRP1** is non-zero.
   - The command data transfer length is equal in size to more than two memory pages and the Offset portion of the **PBAO** field of **PRP1** is equal to zero.

### `u`

A union of all the command structures.

### `u.GENERAL`

A structure containing data fields for General commands.

### `u.GENERAL.CDW10`

Command DWord 10 data fields for General commands.

### `u.GENERAL.CDW11`

Command DWord 11 data fields for General commands.

### `u.GENERAL.CDW12`

Command DWord 12 data fields for General commands.

### `u.GENERAL.CDW13`

Command DWord 13 data fields for General commands.

### `u.GENERAL.CDW14`

Command DWord 14 data fields for General commands.

### `u.GENERAL.CDW15`

Command DWord 15 data fields for General commands.

### `u.IDENTIFY`

A structure containing parameters for the Identify Command. An Admin command that returns a data buffer describing information about the NVM subsystem, the controller or the namespace(s).

The Identify command uses the PRP Entry 1 (**PRP1**), PRP Entry 2 (**PRP2**), Command Dword 10 (**CDW10**), and Command Dword 11 (**CDW11**) fields. All other command specific fields are reserved.

### `u.IDENTIFY.CDW10`

A [NVME_CDW10_IDENTIFY](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_identify) structure containing Command DWord 10 parameters for the Identify Command.

### `u.IDENTIFY.CDW11`

A [NVME_CDW11_IDENTIFY](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_identify) structure containing Command DWord 11 parameters for the Identify Command.

### `u.IDENTIFY.CDW12`

Command DWord 12 data fields for the Identify Command.

### `u.IDENTIFY.CDW13`

Command DWord 13 data fields for the Identify Command.

### `u.IDENTIFY.CDW14`

Command DWord 14 data fields for the Identify Command.

### `u.IDENTIFY.CDW15`

Command DWord 15 data fields for the Identify Command.

### `u.ABORT`

A structure containing parameters for the Abort Command. An Admin command that is used to abort a specific command previously submitted to the Admin Submission Queue or an I/O Submission Queue.

The Abort command uses Command Dword 10 (**CDW10**) fields. All other command specific fields are reserved.

### `u.ABORT.CDW10`

A [NVME_CDW10_ABORT](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_abort) structure containing Command DWord 10 parameters for the Abort Command.

### `u.ABORT.CDW11`

Command DWord 11 data fields for the Abort Command.

### `u.ABORT.CDW12`

Command DWord 12 data fields for the Abort Command.

### `u.ABORT.CDW13`

Command DWord 13 data fields for the Abort Command.

### `u.ABORT.CDW14`

Command DWord 14 data fields for the Abort Command.

### `u.ABORT.CDW15`

Command DWord 15 data fields for the Abort Command.

### `u.GETFEATURES`

A structure containing parameters for the Get Features Command. An Admin command that retrieves the attributes of a specified feature.

The Get Features command uses the PRP Entry 1 (**PRP1**), PRP Entry 2 (**PRP2**), Command Dword 10 (**CDW10**), and Command Dword 11 (**CDW11**) fields. All other command specific fields are reserved.

### `u.GETFEATURES.CDW10`

A [NVME_CDW10_GET_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_features) structure containing Command DWord 10 parameters for the Get Features command.

### `u.GETFEATURES.CDW11`

A [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features) structure containing Command DWord 11 parameters for the Get Features command.

### `u.GETFEATURES.CDW12`

Command DWord 12 data fields for the Get Features command.

### `u.GETFEATURES.CDW13`

Command DWord 13 data fields for the Get Features command.

### `u.GETFEATURES.CDW14`

Command DWord 14 data fields for the Get Features command.

### `u.GETFEATURES.CDW15`

Command DWord 15 data fields for the Get Features command.

### `u.SETFEATURES`

A structure containing parameters for the Set Features Command. An Admin command that sets the attributes of a specified feature.

The Set Features command uses the PRP Entry 1 (**PRP1**), PRP Entry 2 (**PRP2**), Command Dword 10 (**CDW10**), Command Dword 11 (**CDW11**), Command Dword 12 (**CDW12**), Command Dword 13 (**CDW13**), Command Dword 14 (**CDW14**), and Command Dword 15 (**CDW15**) fields. All other command specific fields are reserved.

### `u.SETFEATURES.CDW10`

A [NVME_CDW10_SET_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_set_features) structure containing Command DWord 10 parameters for the Set Features command.

### `u.SETFEATURES.CDW11`

A [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features) structure containing Command DWord 11 parameters for the Set Features command.

### `u.SETFEATURES.CDW12`

A [NVME_CDW12_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_features) structure containing Command DWord 12 parameters for the Set Features command.

### `u.SETFEATURES.CDW13`

A [NVME_CDW13_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw13_features) structure containing Command DWord 13 parameters for the Set Features command.

### `u.SETFEATURES.CDW14`

A [NVME_CDW14_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw14_features) structure containing Command DWord 14 parameters for the Set Features command.

### `u.SETFEATURES.CDW15`

A [NVME_CDW15_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw15_features) structure containing Command DWord 15 parameters for the Set Features command.

### `u.GETLOGPAGE`

A structure containing parameters for the Get Log Page Command. An Admin command that returns a data buffer containing the requested log page.

The Get Log Page command uses the PRP Entry 1 (**PRP1**), PRP Entry 2 (**PRP2**), Command Dword 10 (**CDW10** and **CDW10_V13**), Command Dword 11 (**CDW11**), Command Dword 12 (**CDW12**), and Command Dword 13 (**CDW13**) fields. All other command specific fields are reserved.

### `u.GETLOGPAGE.CDW10`

A [NVME_CDW10_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page) structure containing Command DWord 10 parameters for the Get Log Page command that conform to NVMe Specifications prior to version 1.3.

### `u.GETLOGPAGE.CDW10_V13`

A [NVME_CDW10_GET_LOG_PAGE_V13](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page_v13) structure containing Command DWord 10 parameters for the Get Log Page command that conform to NVMe Specification version 1.3 or later.

### `u.GETLOGPAGE.CDW11`

A [NVME_CDW11_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_get_log_page) structure containing Command DWord 11 parameters for the Get Log Page command.

### `u.GETLOGPAGE.CDW12`

A [NVME_CDW12_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_get_log_page) structure containing Command DWord 12 parameters for the Get Log Page command.

### `u.GETLOGPAGE.CDW13`

A [NVME_CDW13_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw13_get_log_page) structure containing Command DWord 13 parameters for the Get Log Page command.

### `u.GETLOGPAGE.CDW14`

Command DWord 14 data fields for the Get Log Page command.

### `u.GETLOGPAGE.CDW15`

Command DWord 15 data fields for the Get Log Page command.

### `u.CREATEIOCQ`

A structure containing parameters for the Create IO Completion Queue Command. An Admin command that is used to create all I/O Completion Queues with the exception of the Admin Completion Queue.

The Create IO Completion Queue command uses the PRP Entry 1 (**PRP1**), Command Dword 10 (**CDW10**), and Command Dword 11 (**CDW11**) fields. All other command specific fields are reserved.

### `u.CREATEIOCQ.CDW10`

A [NVME_CDW10_CREATE_IO_QUEUE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_create_io_queue) structure containing Command DWord 10 parameters for the Create IO Completion Queue command.

### `u.CREATEIOCQ.CDW11`

A [NVME_CDW11_CREATE_IO_CQ](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_create_io_cq) structure containing Command DWord 11 parameters for the Create IO Completion Queue command.

### `u.CREATEIOCQ.CDW12`

Command DWord 12 data fields for the Create IO Completion Queue command.

### `u.CREATEIOCQ.CDW13`

Command DWord 13 data fields for the Create IO Completion Queue command.

### `u.CREATEIOCQ.CDW14`

Command DWord 14 data fields for the Create IO Completion Queue command.

### `u.CREATEIOCQ.CDW15`

Command DWord 15 data fields for the Create IO Completion Queue command.

### `u.CREATEIOSQ`

A structure containing parameters for the Create IO Submission Queue Command. An Admin command that is used to create I/O Submission Queues.

The Create IO Submission Queue command uses the PRP Entry 1 (**PRP1**), Command Dword 10 (**CDW10**), and Command Dword 11 (**CDW11**) fields. All other command specific fields are reserved.

### `u.CREATEIOSQ.CDW10`

A [NVME_CDW10_CREATE_IO_QUEUE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_create_io_queue) structure containing Command DWord 10 parameters for the Create IO Submission Queue command.

### `u.CREATEIOSQ.CDW11`

A [NVME_CDW11_CREATE_IO_SQ](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_create_io_sq) structure containing Command DWord 11 parameters for the Create IO Submission Queue command.

### `u.CREATEIOSQ.CDW12`

Command DWord 12 data fields for the Create IO Submission Queue command.

### `u.CREATEIOSQ.CDW13`

Command DWord 13 data fields for the Create IO Submission Queue command.

### `u.CREATEIOSQ.CDW14`

Command DWord 14 data fields for the Create IO Submission Queue command.

### `u.CREATEIOSQ.CDW15`

Command DWord 15 data fields for the Create IO Submission Queue command.

### `u.DATASETMANAGEMENT`

A structure containing parameters for the Dataset Management Command. An NVM command that is used by the host to indicate attributes for ranges of logical blocks.

The Dataset Management command uses Command Dword 10 (**CDW10**) and Command Dword 11 (**CDW11**) fields. If the command uses PRPs for the data transfer, then the PRP Entry 1 (**PRP1**) and PRP Entry 2 (**PRP2**) fields are used. All other command specific fields are reserved.

### `u.DATASETMANAGEMENT.CDW10`

A [NVME_CDW10_DATASET_MANAGEMENT](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_dataset_management) structure containing Command DWord 10 parameters for the Dataset Management command.

### `u.DATASETMANAGEMENT.CDW11`

A [NVME_CDW11_DATASET_MANAGEMENT](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_dataset_management) structure containing Command DWord 11 parameters for the Dataset Management command.

### `u.DATASETMANAGEMENT.CDW12`

Command DWord 12 data fields for the Dataset Management command.

### `u.DATASETMANAGEMENT.CDW13`

Command DWord 13 data fields for the Dataset Management command.

### `u.DATASETMANAGEMENT.CDW14`

Command DWord 14 data fields for the Dataset Management command.

### `u.DATASETMANAGEMENT.CDW15`

Command DWord 15 data fields for the Dataset Management command.

### `u.SECURITYSEND`

A structure containing parameters for the Security Send Command. An Admin command that is used to transfer security protocol data to the controller.

The Security Send command uses PRP Entry 1 (**PRP1**), PRP Entry 2 (**PRP2**), Command Dword 10 (**CDW10**), and Command Dword 11 (**CDW11**) fields. All other command specific fields are reserved.

### `u.SECURITYSEND.CDW10`

A [NVME_CDW10_SECURITY_SEND_RECEIVE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_security_send_receive) structure containing Command DWord 10 parameters for the Security Send command.

### `u.SECURITYSEND.CDW11`

A [NVME_CDW11_SECURITY_SEND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_security_send) structure containing Command DWord 11 parameters for the Security Send command.

### `u.SECURITYSEND.CDW12`

Command DWord 12 data fields for the Security Send command.

### `u.SECURITYSEND.CDW13`

Command DWord 13 data fields for the Security Send command.

### `u.SECURITYSEND.CDW14`

Command DWord 14 data fields for the Security Send command.

### `u.SECURITYSEND.CDW15`

Command DWord 15 data fields for the Security Send command.

### `u.SECURITYRECEIVE`

A structure containing parameters for the Security Receive Command. An Admin command that transfers the status and data result of one or more [Security Send](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command#-field-u.securitysend) commands that were previously submitted to the controller.

The Security Receive command uses PRP Entry 1 (**PRP1**), PRP Entry 2 (**PRP2**), Command Dword 10 (**CDW10**), and Command Dword 11 (**CDW11**) fields. All other command specific fields are reserved.

### `u.SECURITYRECEIVE.CDW10`

A [NVME_CDW10_SECURITY_SEND_RECEIVE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_security_send_receive) structure containing Command DWord 10 parameters for the Security Receive command.

### `u.SECURITYRECEIVE.CDW11`

A [NVME_CDW11_SECURITY_RECEIVE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_security_receive) structure containing Command DWord 11 parameters for the Security Receive command.

### `u.SECURITYRECEIVE.CDW12`

Command DWord 12 data fields for the Security Receive command.

### `u.SECURITYRECEIVE.CDW13`

Command DWord 13 data fields for the Security Receive command.

### `u.SECURITYRECEIVE.CDW14`

Command DWord 14 data fields for the Security Receive command.

### `u.SECURITYRECEIVE.CDW15`

Command DWord 15 data fields for the Security Receive command.

### `u.FIRMWAREDOWNLOAD`

A structure containing parameters for the Firmware Image Download Command. An Admin command that is used to copy a new firmware image (in whole or in part) to the controller.

The Firmware Image Download command uses the PRP Entry 1 (**PRP1**), PRP Entry 2 (**PRP2**), Command Dword 10 (**CDW10**), and Command Dword 11 (**CDW11**) fields. All other command specific fields are reserved.

### `u.FIRMWAREDOWNLOAD.CDW10`

A [NVME_CDW10_FIRMWARE_DOWNLOAD](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_firmware_download) structure containing Command DWord 10 parameters for the Firmware Image Download command.

### `u.FIRMWAREDOWNLOAD.CDW11`

A [NVME_CDW11_FIRMWARE_DOWNLOAD](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_firmware_download) structure containing Command DWord 11 parameters for the Firmware Image Download command.

### `u.FIRMWAREDOWNLOAD.CDW12`

Command DWord 12 data fields for the Firmware Image Download command.

### `u.FIRMWAREDOWNLOAD.CDW13`

Command DWord 13 data fields for the Firmware Image Download command.

### `u.FIRMWAREDOWNLOAD.CDW14`

Command DWord 14 data fields for the Firmware Image Download command.

### `u.FIRMWAREDOWNLOAD.CDW15`

Command DWord 15 data fields for the Firmware Image Download command.

### `u.FIRMWAREACTIVATE`

A structure containing parameters for the Firmware Commit Command. An Admin command that is used to verify that a valid firmware image has been downloaded and to commit that revision to a specific firmware slot.

> [!NOTE]
> The Firmware Commit command was called Firmware Activate in previous versions of NVM Express.

The Firmware Commit command uses the Command Dword 10 (**CDW10**) field. All other command specific fields are reserved.

### `u.FIRMWAREACTIVATE.CDW10`

A [NVME_CDW10_FIRMWARE_ACTIVATE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_firmware_activate) structure containing Command DWord 10 parameters for the Firmware Commit command.

### `u.FIRMWAREACTIVATE.CDW11`

Command DWord 11 data fields for the Firmware Commit command.

### `u.FIRMWAREACTIVATE.CDW12`

Command DWord 12 data fields for the Firmware Commit command.

### `u.FIRMWAREACTIVATE.CDW13`

Command DWord 13 data fields for the Firmware Commit command.

### `u.FIRMWAREACTIVATE.CDW14`

Command DWord 14 data fields for the Firmware Commit command.

### `u.FIRMWAREACTIVATE.CDW15`

Command DWord 15 data fields for the Firmware Commit command.

### `u.FORMATNVM`

A structure containing parameters for the Format NVM Command. An Admin command that is used to low level format the NVM media.

The Format NVM command uses the Command Dword 10 (**CDW10**) field. All other command specific fields are reserved.

### `u.FORMATNVM.CDW10`

A [NVME_CDW10_FORMAT_NVM](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_format_nvm) structure containing Command DWord 10 parameters for the Format NVM command.

### `u.FORMATNVM.CDW11`

Command DWord 11 data fields for the Format NVM command.

### `u.FORMATNVM.CDW12`

Command DWord 12 data fields for the Format NVM command.

### `u.FORMATNVM.CDW13`

Command DWord 13 data fields for the Format NVM command.

### `u.FORMATNVM.CDW14`

Command DWord 14 data fields for the Format NVM command.

### `u.FORMATNVM.CDW15`

Command DWord 15 data fields for the Format NVM command.

### `u.DIRECTIVERECEIVE`

A structure containing parameters for the Admin Command Directive Receive.

The Directive Receive command uses the Command Dword 10 (**CDW10**), Command Dword 11 (**CDW11**), and Command Dword 12 (**CDW12**) fields. All other command specific fields are reserved.

### `u.DIRECTIVERECEIVE.CDW10`

A [NVME_CDW10_DIRECTIVE_RECEIVE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_directive_receive) structure containing Command DWord 10 parameters for the Directive Receive command.

### `u.DIRECTIVERECEIVE.CDW11`

A [NVME_CDW11_DIRECTIVE_RECEIVE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_directive_receive) structure containing Command DWord 11 parameters for the Directive Receive command.

### `u.DIRECTIVERECEIVE.CDW12`

A [NVME_CDW12_DIRECTIVE_RECEIVE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_directive_receive) structure containing Command DWord 12 parameters for the Directive Receive command.

### `u.DIRECTIVERECEIVE.CDW13`

Command DWord 13 data fields for the Directive Receive command.

### `u.DIRECTIVERECEIVE.CDW14`

Command DWord 14 data fields for the Directive Receive command.

### `u.DIRECTIVERECEIVE.CDW15`

Command DWord 15 data fields for the Directive Receive command.

### `u.DIRECTIVESEND`

A structure containing parameters for the Admin Command Directive Send.

The Directive Send command uses the Command Dword 10 (**CDW10**), Command Dword 11 (**CDW11**), and Command Dword 12 (**CDW12**) fields. All other command specific fields are reserved.

### `u.DIRECTIVESEND.CDW10`

A [NVME_CDW10_DIRECTIVE_SEND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_directive_send) structure containing Command DWord 10 parameters for the Directive Send command.

### `u.DIRECTIVESEND.CDW11`

A [NVME_CDW11_DIRECTIVE_SEND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_directive_send) structure containing Command DWord 11 parameters for the Directive Send command.

### `u.DIRECTIVESEND.CDW12`

A [NVME_CDW12_DIRECTIVE_SEND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_directive_send) structure containing Command DWord 12 parameters for the Directive Send command.

### `u.DIRECTIVESEND.CDW13`

Command DWord 13 data fields for the Directive Send command.

### `u.DIRECTIVESEND.CDW14`

Command DWord 14 data fields for the Directive Send command.

### `u.DIRECTIVESEND.CDW15`

Command DWord 15 data fields for the Directive Send command.

### `u.READWRITE`

A structure containing parameters for the NVME Read and NVME Write commands that read or write data and metadata, if applicable, to and from the NVM controller for the specified Logical Block Addresses (LBA).

The NVME Read and NVME Write commands use the Command Dword 12 (**CDW12**), Command Dword 13 (**CDW13**), and Command Dword 14 (**CDW14**) fields.

### `u.READWRITE.LBALOW`

The low LBA.

### `u.READWRITE.LBAHIGH`

The high LBA.

### `u.READWRITE.CDW12`

A [NVME_CDW12_READ_WRITE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_read_write) structure containing Command DWord 12 parameters for the NVME Read and NVME Write commands.

### `u.READWRITE.CDW13`

A [NVME_CDW13_READ_WRITE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw13_read_write) structure containing Command DWord 13 parameters for the NVME Read and NVME Write commands.

### `u.READWRITE.CDW14`

Command DWord 14 data fields for the NVME Read and NVME Write commands.

### `u.READWRITE.CDW15`

A [NVME_CDW15_READ_WRITE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw15_read_write) structure containing Command DWord 15 parameters for the NVME Read and NVME Write commands.

## Remarks

The Admin Command Set defines the commands that may be submitted to the Admin Submission Queue.

For all Admin commands, DWord 14 and DWord 15 are I/O Command Set specific.

## See also