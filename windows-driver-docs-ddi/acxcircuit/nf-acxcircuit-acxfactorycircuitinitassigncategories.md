## Description

The AcxFactoryCircuitInitAssignCategories function assigns a set of driver category (GUID) entries for the ACXFACTORYCIRCUIT.

## Parameters

### `FactoryInit`

An ACXFACTORYCIRCUIT_INIT structure that is used for circuit factory initialization. This is an opaque structure that is used to store ACX Circuit factory initialization information and associate the factory with a WDF device.

Use the [AcxFactoryCircuitInitAllocate function](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxfactorycircuitinitallocate) to initialize the ACXFACTORYCIRCUIT_INIT structure.

### `Categories`

An array that contains GUIDs of the desired set of driver category entries. For more information about the KSCATERGORY entries, see [Installing Device Interfaces for an Audio Adapter](https://learn.microsoft.com/windows-hardware/drivers/audio/installing-device-interfaces-for-an-audio-adapter).

### `CategoriesCount`

The number of categories that will be added to the circuit. This is a one based count.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

This call override the default category set initialized by ACX.

### Example

Example usage is shown below.

```cpp
    ACXFACTORYCIRCUIT                               factory;
    PACXFACTORYCIRCUIT_INIT                         factoryInit = NULL;
    SDCAXU_FACTORYCIRCUIT_CONTEXT *                 factoryCtx;
    ACX_FACTORY_CIRCUIT_OPERATION_CALLBACKS         operationCallbacks;

    //
    // Get a FactoryCircuitInit structure.
    //
    factoryInit = AcxFactoryCircuitInitAllocate(Device);

    //
    // Add factory identifiers.
    //
    AcxFactoryCircuitInitSetComponentId(factoryInit, &SDCAXU_FACTORY_GUID);
    AcxFactoryCircuitInitAssignCategories(factoryInit, &SDCAXU_FACTORY_CATEGORY, 1);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)