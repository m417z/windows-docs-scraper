## Description

The **ACX_TARGET_CIRCUIT_CONFIG_INIT** function initializes an ACX target circuit config structure.

## Parameters

### `Config`

A pointer to the [ACX_TARGET_CIRCUIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/ns-acxtargets-acx_target_circuit_config) structure that will be initialized.

## Remarks

### Example

```cpp
    ACX_TARGET_CIRCUIT_CONFIG   targetCfg;

    //
    // Create a target circuit.
    //
    ACX_TARGET_CIRCUIT_CONFIG_INIT(&targetCfg);
    targetCfg.SymbolicLinkName  = m_TargetName;
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)