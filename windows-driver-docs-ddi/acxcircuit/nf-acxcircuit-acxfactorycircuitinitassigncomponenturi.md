## Description

The AcxFactoryCircuitInitAssignComponentUri function assigns an URI string as identifier for the ACXFACTORYCIRCUIT.

## Parameters

### `FactoryInit`

An ACXFACTORYCIRCUIT_INIT structure that is used for circuit factory initialization. This is an opaque structure that is used to store ACX Circuit factory initialization information and associate the factory with a WDF device.

Use the [AcxFactoryCircuitInitAllocate function](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxfactorycircuitinitallocate) to initialize the ACXFACTORYCIRCUIT_INIT structure.

### `ComponentUri`

A unicode string that describes the component.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The driver must initialize the circuit factory's identity by setting its URI and/or its ID (AcxCircuitInitSetComponentId).

### Example

Example usage is shown below.

```cpp
    DECLARE_CONST_UNICODE_STRING(dspFactoryName, L"DspFactoryCircuit");
    DECLARE_CONST_UNICODE_STRING(dspFactoryUri, L"URI_Goes_Here");

    //
    // Get a FactoryCircuitInit structure.
    //
    PACXFACTORYCIRCUIT_INIT factoryInit = NULL;
    factoryInit = AcxFactoryCircuitInitAllocate(Device);

    //
    // Add factory identifiers.
    //
    status = cxFactoryCircuitInitAssignComponentUri(factoryInit, &dspFactoryUri);
    status = AcxFactoryCircuitInitAssignName(factoryInit, &dspFactoryName);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)