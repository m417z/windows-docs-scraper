## Description

The **ACX_TARGET_FACTORY_CIRCUIT_CONFIG** structure is used to define the target factory circuit configuration.

## Members

### `Size`

The length, in bytes, of this structure.

### `Flags`

Target factory circuit configuration flags defined by the [ACX_TARGET_FACTORY_CIRCUIT_CONFIG_FLAGS enum](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/ne-acxtargets-acx_target_factory_circuit_config_flags).

No flag bits are currently defined. Set this member to zero - AcxTargetFactoryCircuitConfigNoFlags

### `IoTarget`

An optional WDFIOTARGET object that is the IoTarget for the factory circuit. For more information about WDF IO targets see [Initializing a General I/O Target](https://learn.microsoft.com/windows-hardware/drivers/wdf/initializing-a-general-i-o-target).

### `SymbolicLinkName`

Pointer to a Unicode string that contains the name of the symbolic link for the circuit configuration.

## Remarks

### Example

```cpp
    ACX_TARGET_FACTORY_CIRCUIT_CONFIG targetCfg;

    ACX_TARGET_FACTORY_CIRCUIT_CONFIG_INIT(&targetCfg);
    targetCfg.SymbolicLinkName = m_SymbolicLinkName;
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)