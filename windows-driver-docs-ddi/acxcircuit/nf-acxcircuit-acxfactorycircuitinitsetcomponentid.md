## Description

The **AcxFactoryCircuitInitSetComponentId** function sets the component ID for the ACXFACTORYCIRCUIT.

## Parameters

### `FactoryInit`

An ACXFACTORYCIRCUIT_INIT structure that is used for circuit factory initialization. This is an opaque structure that is used to store ACX Circuit factory initialization information and associate the factory with a WDF device.

Use the [AcxFactoryCircuitInitAllocate function](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxfactorycircuitinitallocate) to initialize the ACXFACTORYCIRCUIT_INIT structure.

### `ComponentId`

A defined GUID that serves as the component ID for the circuit factory.

## Remarks

The driver must initialize the circuit factory's identity by setting its URI (AcxFactoryCircuitInitAssignComponentUri) and/or its ID (this DDI).

### Example

Example usage is shown below.

```cpp
DEFINE_GUID(SDCAXU_FACTORY_GUID,
0xa8215305, 0xe7db, 0x49eb, 0x96, 0x49, 0x84, 0x34, 0x55, 0xe2, 0xe0, 0xd1);
    //
    // Get a FactoryCircuitInit structure.
    //
    factoryInit = AcxFactoryCircuitInitAllocate(Device);

    //
    // Add factory identifiers.
    //
    AcxFactoryCircuitInitSetComponentId(factoryInit, &SDCAXU_FACTORY_GUID);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)