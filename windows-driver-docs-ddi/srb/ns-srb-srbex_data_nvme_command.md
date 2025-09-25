## Description

The **SRBEX_DATA_NVME_COMMAND** structure enables the user to frame and issue a command in NVMe format. This structure is currently reserved for system use.

## Members

### `Type`

Command type. Currently this must be set to **SrbExDataTypeNvmeCommand**.

### `Length`

Size of this structure, in bytes.

### `ControllerHandle`

Miniport's handle for the NVMe controller.

### `Reserved0`

Reserved; do not use.

### `CommandDWORD0`

Command Dword 0 within the NVMe command (see the [NVMe specifications](https://nvmexpress.org/specifications/)).

### `CommandNSID`

Namespace identifier within the NVMe command (see the [NVMe specifications](https://nvmexpress.org/specifications/)).

### `Reserved1[2]`

Reserved; do not use.

### `CommandMPTR`

Metadata pointer within the NVMe command (see the [NVMe specifications](https://nvmexpress.org/specifications/)).

### `CommandPRP1`

Physical region page (PRP) Entry 1 within the NVMe command (see the [NVMe specifications](https://nvmexpress.org/specifications/)). To indicate that PRP information is present, the user must set the **SRBEX_DATA_NVME_COMMAND_FLAG_PRP_SET_ALREADY** flag of **[SRBEX_DATA_NVME_COMMAND_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ne-srb-srbex_data_nvme_command_flag)**.

### `CommandPRP2`

PRP Entry 2 within the NVMe command (see the [NVMe specifications](https://nvmexpress.org/specifications/)). To indicate that PRP information is present, the user must set the **SRBEX_DATA_NVME_COMMAND_FLAG_PRP_SET_ALREADY** flag of **[SRBEX_DATA_NVME_COMMAND_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ne-srb-srbex_data_nvme_command_flag)**.

### `CommandSGL1[2]`

Command-specific scatter gather list (SGL) Entry 1 field (see the [NVMe specifications](https://nvmexpress.org/specifications/)).

### `CommandCDW10`

Command-specific Dword 10 (see the [NVMe specifications](https://nvmexpress.org/specifications/)).

### `CommandCDW11`

Command-specific Dword 11 (see the [NVMe specifications](https://nvmexpress.org/specifications/)).

### `CommandCDW12`

Command-specific Dword 12 (see the [NVMe specifications](https://nvmexpress.org/specifications/)).

### `CommandCDW13`

Command-specific Dword 13 (see the [NVMe specifications](https://nvmexpress.org/specifications/)).

### `CommandCDW14`

Command-specific Dword 14 (see the [NVMe specifications](https://nvmexpress.org/specifications/)).

### `CommandCDW15`

Command-specific Dword 15 (see the [NVMe specifications](https://nvmexpress.org/specifications/)).

### `FabricsCommand`

**NVMEOF_FABRICS_COMMAND** in nvme.h

### `FabricsCommand.OPC`

Opcode (7Fh).

### `FabricsCommand.PSDT`

PRP or SGL for data transfer. (only bits 7:6 are used, the rest are reserved).

### `FabricsCommand.CID`

Fabrics command identifier.

### `FabricsCommand.FCTYPE`

Fabrics command type.

### `FabricsCommand.Reserved[35]`

Reserved; do not use.

### `FabricsCommand.Specific[24]`

Command type specific (see the [NVMe specifications](https://nvmexpress.org/specifications/)).

### `Command`

To reference command DW0 (see the [NVMe specifications](https://nvmexpress.org/specifications/)).

### `Command.OPC`

Opcode (OPC).

### `Command.FUSE`

Fused Operation (FUSE).

### `Command.Reserved`

Reserved; do not use.

### `Command.PSDT`

PRP or SGL for data transfer.

### `Command.CID`

Command identifier.

### `Command.TypeSpecific[60]`

Command type specific (see the [NVMe specifications](https://nvmexpress.org/specifications/)).

### `CommandType`

A **[SRBEX_DATA_NVME_COMMAND_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ne-srb-srbex_data_nvme_command_type)** value that specifies the NVMe command type.

### `Reserved2`

Reserved; do not use.

### `CommandFlags`

A **[SRBEX_DATA_NVME_COMMAND_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ne-srb-srbex_data_nvme_command_flag)** value that specifies the properties of this SRBEX data NVMe command.

### `ResponseFlags`

Defined in [SRBEX_DATA_NVME_RESPONSE_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ne-srb-srbex_data_nvme_response_flag).

### `CommandStatus`

Status field from the Completion Queue entry (see the [NVMe specifications](https://nvmexpress.org/specifications/)).

### `CommandStatus.DUMMYSTRUCTNAME`

Embedded structure.

### `CommandStatus.DUMMYSTRUCTNAME.P`

Phase tag (P).

### `CommandStatus.DUMMYSTRUCTNAME.SC`

Status code (SC).

### `CommandStatus.DUMMYSTRUCTNAME.SCT`

Status code type (SCT).

### `CommandStatus.DUMMYSTRUCTNAME.CRD`

Command retry delay (CRD).

### `CommandStatus.DUMMYSTRUCTNAME.M`

More (M).

### `CommandStatus.DUMMYSTRUCTNAME.DNR`

Do not retry (DNR).

### `CommandStatus.AsUshort`

### `QID`

User-specified queue ID (see the [NVMe specifications](https://nvmexpress.org/specifications/)). If unspecified, set this value to 0xFFFFFFFF.

### `CommandTag`

Unique, user-specified identifier for the command identifier to mark a specific command. A user can use **CommandTag** to trace the result of the command in an Event Tracing for Windows (ETW) trace (for example, in Event Viewer's Storage log).

### `CQEntryDW0`

Completion queue entry DW0.

### `CQEntryDW1`

Completion queue entry DW1.

### `Specific[8]`

Fabrics command specific response.

### `SQHD`

SQ head pointer in completion queue entry.

### `SQID`

SQ identifier.

## Remarks

## See also

- **[SRBEX_DATA_NVME_COMMAND_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ne-srb-srbex_data_nvme_command_flag)**
- **[SRBEX_DATA_NVME_COMMAND_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ne-srb-srbex_data_nvme_command_flag)**
- [NVMe specifications](https://nvmexpress.org/specifications/)