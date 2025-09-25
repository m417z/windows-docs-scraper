## Description

The **AcxTargetCircuitGetTargetPin** function, given a valid pin index value, will return the associated *ACXTARGETPIN* object.

## Parameters

### `TargetCircuit`

An ACXTARGETCIRCUIT handle. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `PinIndex`

A valid pin index value.

## Return value

Returns a ACXTARGETELEMENT ACX Object that is associated with the specified circuit.

## Remarks

### Example

```cpp
    PDSP_CIRCUIT_CONTEXT circuitCtx;
    ACX_REQUEST_PARAMETERS  params;

    circuitCtx = GetDspCircuitContext(Circuit);

    for (ULONG pinIndex = 0; pinIndex < AcxTargetCircuitGetPinsCount(TargetCircuit); ++pinIndex)
    {
        ACXTARGETPIN targetPin = AcxTargetCircuitGetTargetPin(TargetCircuit, pinIndex);
        ULONG targetPinFlow = 0;
        ACX_REQUEST_PARAMETERS_INIT_PROPERTY(&params,
                                             KSPROPSETID_Pin,
                                             KSPROPERTY_PIN_DATAFLOW,
                                             AcxPropertyVerbGet,
                                             AcxItemTypePin,
                                             AcxTargetPinGetId(targetPin),
                                             nullptr, 0,
                                             &targetPinFlow,
                                             sizeof(targetPinFlow));
...

    }
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)