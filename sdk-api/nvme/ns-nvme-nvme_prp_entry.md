# NVME_PRP_ENTRY structure

## Description

Contains fields that specify the Page Base Address and Offset (PBAO) of a pointer to a physical memory page.

A Physical Region Page (PRP) Entry is a pointer to a physical memory page. PRPs are used as a scatter/gather mechanism for data transfers between the controller and memory. To enable efficient out of order data transfers between the controller and the host, PRP entries are a fixed size.

The size of the physical memory page is configured by host software in the **MPS** field of the [Controller Configuration](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_configuration) structure, and the size of the Offset field is determined by the **MPS** value.

This structure is used in the **PRP1** and **PRP2** fields of the [NVME_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.Reserved0`

A reserved field.

### `DUMMYSTRUCTNAME.PBAO`

Indicates the 64-bit physical memory page address.

The lower bits (n:2) of this field indicate the offset within the memory page. If the memory page size is 4KB, then bits 02:11 form the Offset; if the memory page size is 8KB, then bits 02:12 form the Offset, and so on.

If this entry is not the first PRP entry in the command or a PRP List pointer in a command, then the Offset portion of this field should be cleared to `0h`.

### `AsUlonglong`

## Remarks

## See also