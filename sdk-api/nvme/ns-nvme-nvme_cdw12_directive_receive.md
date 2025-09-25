# NVME_CDW12_DIRECTIVE_RECEIVE structure

## Description

Contains a parameter for allocating stream resources for the Directive Receive command.

This structure is used as the value of the **CDW12** parameter in the **DIRECTIVERECEIVE** field of the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `AllocateResources`

A [NVME_CDW12_DIRECTIVE_RECEIVE_STREAMS_ALLOCATE_RESOURCES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_directive_receive_streams_allocate_resources) structure that specifies the number of namespace streams requested.

### `AsUlong`

## Remarks

## See also

- [NVME_CDW10_DIRECTIVE_RECEIVE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_directive_receive)
- [NVME_CDW11_DIRECTIVE_RECEIVE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_directive_receive)