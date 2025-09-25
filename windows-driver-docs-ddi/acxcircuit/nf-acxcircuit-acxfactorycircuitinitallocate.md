## Description

The **AcxFactoryCircuitInitAllocate** function is used to initialize the opaque ACXFACTORYCIRCUIT_INIT structure that is used by the [AcxFactoryCircuitCreate function](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxfactorycircuitcreate).

## Parameters

### `Device`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that is associated with the ACX circuit.

## Return value

A pointer to an initialized ACXFACTORYCIRCUIT_INIT structure. This is an opaque structure that is accessed using APIs.

## Remarks

The driver is responsible for deleting the ACXFACTORYCIRCUIT_INIT object using AcxFactoryCircuitInitFree if the AcxFactoryCircuitCreate is not invoked or returns an error.

### Example

Example usage is shown below.

```cpp
    //
    // Get a FactoryCircuitInit structure.
    //
    PACXFACTORYCIRCUIT_INIT factoryInit = NULL;
    factoryInit = AcxFactoryCircuitInitAllocate(Device);

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)