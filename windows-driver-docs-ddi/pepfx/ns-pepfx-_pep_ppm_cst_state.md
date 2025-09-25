# _PEP_PPM_CST_STATE structure (pepfx.h)

## Description

The **PEP_PPM_CST_STATE** structure specifies the properties of a C state (ACPI processor power state).

## Members

### `Type`

The C-state type (0 = C0, 1 = C1, 2 = C2, and so on).

### `Latency`

The worst-case latency, in microseconds, to enter and exit this C state. There are no restrictions on latency size.

### `Power`

The average power consumption, in milliwatts, of the processor when in this C state.

### `AddressSpaceId`

The register address space ID (_ASI) for this C state. This member specifies the address space in which the register for this C state is located. The following IDs are defined for this member.

| ID | Meaning |
| --- | --- |
| 0x00 | System memory space |
| 0x01 | System I/O space |
| 0x02 | PCI configuration space |
| 0x03 | Embedded controller |
| 0x04 | SMBus address |
| 0x0A | Platform communications channel (PCC) |
| 0x7F | Functional fixed hardware |

### `BitWidth`

The register bit width (_RBW) for this C state. This member specifies the width, in bits, of the register for this C state.

### `BitOffset`

The register bit offset (_RBO) for this C state. This member specifies the offset, in bits, from the register address specified in the **Address** member to the start of the register for this C state.

### `AccessSize`

The register access size (_ASZ) code for this C state. This member specifies the number of bytes to read during an access of the register for this C state. Valid access size codes are shown in the following table.

| Access size code | Meaning |
| --- | --- |
| 0 | Undefined |
| 1 | BYTE (1 byte) |
| 2 | WORD (2 bytes) |
| 3 | DWORD (4 bytes) |
| 4 | QWORD (8 bytes) |

### `Address`

The register address (_ADR) for this C state.

## Remarks

This structure is used in conjunction with the [PEP_NOTIFY_PPM_CST_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_cst_states) notification. The **IdleStates** member of the [PEP_PPM_CST_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_cst_states) structure is a pointer to an array of **PEP_PPM_CST_STATE** structures. The **Type** member in each element of the array should equal the array index of this member.

The values in the **PEP_PPM_CST_STATE** structure are obtained from the parameters that are specified for this C state in the _CST object in the ACPI namespace for the processor.

## See also

[PEP_NOTIFY_PPM_CST_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_cst_states)

[PEP_PPM_CST_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_cst_states)