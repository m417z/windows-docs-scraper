# _FAULT_INFORMATION_ARM64_FLAGS structure

## Description

Defines fault information. These values are used by the [**FAULT_INFORMATION_ARM64**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_fault_information_arm64) structure.

## Members

### `WriteNotRead`

Indicates if write permission was requested.

### `InstructionNotData`

Indicates if execute permission was requested.

### `Privileged`

Indicates if supervisor privilege was requested by the faulted request.

### `FaultAddressValid`

Indicates if the fault address is valid.

### `Reserved`

Reserved.

## Remarks

## See also