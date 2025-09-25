## Description

The **AcxFactoryCircuitInitFree** function deletes the factory circuit initialization object.

## Parameters

### `FactoryInit`

An ACXFACTORYCIRCUIT_INIT structure that is used for circuit factory initialization. This is an opaque structure that is used to store ACX Circuit factory initialization information and associate the factory with a WDF device.

Use the [AcxFactoryCircuitInitAllocate function](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxfactorycircuitinitallocate) to initialize the ACXFACTORYCIRCUIT_INIT structure.

## Remarks

This function does not return a value.

The driver is responsible for deleting the ACXFACTORYCIRCUIT_INIT object using this DDI if the AcxFactoryCircuitCreate is not invoked or returns an error.

### Example

Example usage is shown below.

```cpp
// Get a FactoryCircuitInit structure

  ctrlInit = AcxFactoryCircuitInitAllocate(Device);

...

// Example exit routine that shows freeing an example init structure

exit:
    if (!NT_SUCCESS(status))
    {
        if (ctrlInit)
        {
            AcxFactoryCircuitInitFree(ctrlInit);
            ctrlInit = nullptr;
        }
    }
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)