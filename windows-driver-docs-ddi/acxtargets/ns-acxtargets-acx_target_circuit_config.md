## Description

The **ACX_TARGET_CIRCUIT_CONFIG** structure is used to define the target circuit configuration.

## Members

### `Size`

The length, in bytes, of this structure.

### `Flags`

Target circuit configuration flags defined by the [ACX_TARGET_CIRCUIT_CONFIG enum](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/ne-acxtargets-acx_target_circuit_config_flags).

No flag bits are currently defined. Set this member to zero - AcxTargetCircuitConfigNoFlags

### `SymbolicLinkName`

Pointer to a Unicode string that contains the name of the symbolic link for the circuit configuration.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)