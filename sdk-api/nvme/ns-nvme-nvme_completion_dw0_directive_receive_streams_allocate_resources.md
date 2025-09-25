# NVME_COMPLETION_DW0_DIRECTIVE_RECEIVE_STREAMS_ALLOCATE_RESOURCES structure

## Description

Contains information about the number of allocated stream resources in a Directive Receive command.

This structure is posted to the Admin Completion Queue in the **DW0** field of the [NVME_COMPLETION_ENTRY](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_completion_entry).

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.NSA`

The number of allocated Namespace Streams.

### `DUMMYSTRUCTNAME.Reserved`

### `AsUlong`

## Remarks

## See also

- [NVME_CDW12_DIRECTIVE_RECEIVE_STREAMS_ALLOCATE_RESOURCE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_directive_receive_streams_allocate_resources)
- [NVME_CDW12_DIRECTIVE_RECEIVE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_directive_receive)