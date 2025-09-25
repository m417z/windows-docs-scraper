# NVME_NVM_SUBSYSTEM_RESET structure

## Description

Specifies a parameter that provides host software with the capability to initiate an NVM Subsystem Reset.

This structure is used in the **NSSR** field of the [NVME_CONTROLLER_REGISTERS](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_registers) structure.

## Members

### `NSSRC`

A read/write value that initiates an NVM Subsystem Reset.

Writing the value `4E564D65h` ("NVMe") to this field initiates an NVM Subsystem Reset. Writing any other value has no functional effect on the operation of the NVM subsystem.

This field returns the value `0h` when read.

## Remarks

## See also