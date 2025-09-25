# NVME_CDW11_SECURITY_RECEIVE structure

## Description

Contains parameters that are used in the Security Receive command.

## Members

### `AL`

The value of the Allocation Length (AL) field is specific to the Security Protocol as defined in [SECURITY PROTOCOL IN (SPC-4)](https://nvmexpress.org/wp-content/uploads/NVM_Express_-_SCSI_Translation_Reference-1_5_20150624_Gold.pdf).

This field is supported and specifies the number of bytes to transfer if the INC_512 field is set to `0` in the SPC-4 Security Protocol.

## Remarks

## See also

- [NVME_CDW11_SECURITY_SEND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_security_send)
- [NVME_CDW10_SECURITY_SEND_RECEIVE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_security_send_receive)