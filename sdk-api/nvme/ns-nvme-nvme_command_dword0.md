# NVME_COMMAND_DWORD0 structure

## Description

Contains parameters that are common for all Admin commands and NVM commands.

This structure is used in the **CDW0** field of the [NVME_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.OPC`

Specifies the Opcode (OPC) of the command to be executed.

### `DUMMYSTRUCTNAME.FUSE`

An [NVME_FUSED_OPERATION_CODES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_fused_operation_codes) value that specifies whether this command is part of a fused operation and if so, which command it is in the sequence.

In a fused operation, a complex command is created by *fusing* together two simpler commands.

### `DUMMYSTRUCTNAME.Reserved0`

### `DUMMYSTRUCTNAME.PSDT`

Specifies whether Physical Region Pages (PRPs) or Scatter Gather Lists (SGLs) are used for any data transfer associated with the command. PRPs are used for all Admin commands.

This field uses the following values:

| Value | Definition |
|-------|----------------------------------|
| 00b | PRPs are used for this transfer. |
| 01b | SGLs are used for this transfer. |
| 10b | SGLs are used for this transfer. |
| 11b | Reserved |

If there is metadata that is not interleaved with the logical block data, as specified in the [Format NVM command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command#-field-u.formatnvm), then the Metadata Pointer (**MPTR**) field in the [NVME_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure is used to point to the metadata. The definition of the **MPTR** field is dependent on the setting in this field.

### `DUMMYSTRUCTNAME.CID`

Specifies a unique identifier for the command when combined with the Submission Queue identifier (**SQID**) in the [command completion entry](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_completion_entry).

### `AsUlong`

## Remarks

## See also