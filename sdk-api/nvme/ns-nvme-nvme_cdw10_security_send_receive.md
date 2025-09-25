# NVME_CDW10_SECURITY_SEND_RECEIVE structure

## Description

Contains parameters that are used in the Admin commands Security Send and Security Receive.

The Security Send command transfers security protocol data to the controller by using the **NVME_CDW10_SECURITY_SEND_RECEIVE** structure that contains security protocol specific commands to be performed by the controller. The structure may also contain data or parameters associated with the security protocol commands.

Status and data that is to be returned to the host for the security protocol commands submitted by a Security Send command are retrieved with the Security Receive command. The Security Receive command transfers the status and data result of one or more Security Send commands that were previously submitted to the controller. Each Security Receive command returns the appropriate data corresponding to a Security Send command as defined by the rules of the Security Protocol. The Security Receive command data may not be retained if there is a loss of communication between the controller and host, or if a controller reset occurs.

The association between a Security Send command and the subsequent Security Receive command is dependent on the Security Protocol **SECP** field. The format of the data to be transferred is dependent on the Security Protocol as defined in [SPC-4](https://nvmexpress.org/wp-content/uploads/NVM_Express_-_SCSI_Translation_Reference-1_5_20150624_Gold.pdf).

The **NVME_CDW10_SECURITY_SEND_RECEIVE** structure is used in the **CDW10** field of the **SECURITYSEND** and **SECURITYRECEIVE** parameters of the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.Reserved0`

### `DUMMYSTRUCTNAME.SPSP`

The value of the SP Specific (SPSP) field is specific to the Security Protocol as defined in SPC-4.

### `DUMMYSTRUCTNAME.SECP`

The Security Protocol (SECP) field specifies the security protocol as defined in SPC-4.

If a reserved value of the Security Protocol is specified, the controller will fail the command with the status [NVME_STATUS_INVALID_FIELD_IN_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_generic_command_codes).

### `AsUlong`

## Remarks

## See also

- [NVME_CDW11_SECURITY_SEND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_security_send)
- [NVME_CDW11_SECURITY_RECEIVE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_security_receive)