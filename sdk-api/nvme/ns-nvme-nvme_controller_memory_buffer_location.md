# NVME_CONTROLLER_MEMORY_BUFFER_LOCATION structure

## Description

Defines the location of the optional Controller Memory Buffer Location register in the **CMBLOC** field of the [NVME_CONTROLLER_REGISTERS](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_registers) structure.

If the Controller Memory Buffer Size **CMBSZ** field of **NVME_CONTROLLER_REGISTERS** has a value of `0`, this register is reserved.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.BIR`

Indicates the Base Address Register (BAR) that contains the Controller Memory Buffer. For a 64-bit BAR, the BAR for the lower 32-bits of the address is specified.

Valid values for this field are: `0h`, `2h`, `3h`, `4h`, and `5h`.

### `DUMMYSTRUCTNAME.Reserved`

### `DUMMYSTRUCTNAME.OFST`

Indicates the offset of the Controller Memory Buffer in multiples of the Size Unit specified in the **CMBSZ** field of the **NVME_CONTROLLER_REGISTERS** structure. This value is 4KB aligned.

### `AsUlong`

## Remarks

## See also

- [NVME_CONTROLLER_REGISTERS](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_registers)
- [NVME_CONTROLLER_MEMORY_BUFFER_SIZE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_memory_buffer_size)