## Description

The **AcxTargetCircuitGetTargetElement** function, given a valid element index value, will return the associated ACXTARGETELEMENT object.

## Parameters

### `TargetCircuit`

An ACXTARGETCIRCUIT handle. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `ElementIndex`

A valid element index value.

## Return value

Returns a ACXTARGETELEMENT ACX Object that is associated with the specified circuit.

## Remarks

### Example

```cpp
    // Search the target circuit for a volume element.
    // This sample code doesn't support downstream audioengine elements.
    //
    for (ULONG elementIndex = 0; elementIndex < AcxTargetCircuitGetElementsCount(TargetCircuit); ++elementIndex)
    {
        ACXTARGETELEMENT targetElement = AcxTargetCircuitGetTargetElement(TargetCircuit, elementIndex);
        GUID elementType = AcxTargetElementGetType(targetElement);

        if (IsEqualGUID(elementType, KSNODETYPE_VOLUME) &&
            circuitCtx->TargetVolumeHandler == nullptr)
        {
            // Found Volume
            circuitCtx->TargetVolumeHandler = targetElement;
        }
    }
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)