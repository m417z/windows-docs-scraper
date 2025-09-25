# NVME_CDW12_DIRECTIVE_SEND structure

## Description

Contains a parameter for enabling a directive for the Directive Send command.

This structure is used as the value of the **CDW12** parameter in the **DIRECTIVESEND** field of the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `EnableDirective`

A [NVME_CDW12_DIRECTIVE_SEND_IDENTIFY_ENABLE_DIRECTIVE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_directive_send_identify_enable_directive) structure that specifies the directive type and whether it is enabled.

### `AsUlong`

## Remarks

## See also

- [NVME_CDW10_DIRECTIVE_SEND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_directive_send)
- [NVME_CDW11_DIRECTIVE_SEND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_directive_send)