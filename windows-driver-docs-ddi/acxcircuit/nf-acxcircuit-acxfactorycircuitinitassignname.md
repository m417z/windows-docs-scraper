## Description

The AcxFactoryCircuitInitAssignName function assigns a friendly name for the ACXFACTORYCIRCUIT.

## Parameters

### `FactoryInit`

An ACXFACTORYCIRCUIT_INIT structure that is used for circuit factory initialization. This is an opaque structure that is used to store ACX Circuit factory initialization information and associate the factory with a WDF device.

Use the [AcxFactoryCircuitInitAllocate function](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxfactorycircuitinitallocate) to initialize the ACXFACTORYCIRCUIT_INIT structure.

### `FactoryName`

A unicode string with the circuit factory name, such as *Factory_Microphone*.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
//
// Factory Name.
//
DECLARE_CONST_UNICODE_STRING(s_FactoryName, L"Render");

    //
    // Get a FactoryCircuitInit structure.
    //
    factoryInit = AcxFactoryCircuitInitAllocate(Device);

    //
    // Add factory identifiers.
    //
    AcxFactoryCircuitInitSetComponentId(factoryInit, &KSCATEGORY_APXCIRCUITFACTORY);
    AcxFactoryCircuitInitAssignCategories(factoryInit, &KSCATEGORY_APXCIRCUITFACTORY, 1);
    AcxFactoryCircuitInitAssignName(factoryInit, &s_FactoryName);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)