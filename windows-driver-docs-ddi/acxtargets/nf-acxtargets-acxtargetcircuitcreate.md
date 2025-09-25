## Description

The **AcxTargetCircuitCreate** function is used to create an ACX target circuit.

## Parameters

### `Device`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that is associated with the specified ACXCIRCUIT.

### `Attributes`

Additional Attributes defined using a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that are used to set various object's values: cleanup and destroy callbacks, context type, and to specify its parent object.

### `Config`

An initialized [ACX_TARGET_CIRCUIT_CONFIG structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/ns-acxtargets-acx_target_circuit_config) that describes the configuration of the target circuit.

### `TargetCircuit`

A pointer to a location that receives a handle to the new ACXTARGETCIRCUIT Object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

```cpp
    ACX_TARGET_CIRCUIT_CONFIG targetCfg;
    ACX_TARGET_CIRCUIT_CONFIG_INIT(&targetCfg);
    targetCfg.SymbolicLinkName = link;

    WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
    attributes.ParentObject = Circuit;

    RETURN_NTSTATUS_IF_FAILED(AcxTargetCircuitCreate(AcxCircuitGetWdfDevice(Circuit), &attributes, &targetCfg, TargetCircuit));
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)