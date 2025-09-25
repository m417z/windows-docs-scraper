## Description

The AcxFactoryCircuitInitAssignMethods function assigns one or more ACX methods for the ACXFACTORYCIRCUIT.

## Parameters

### `FactoryInit`

An ACXFACTORYCIRCUIT_INIT structure that is used for circuit factory initialization. This is an opaque structure that is used to store ACX Circuit factory initialization information and associate the factory with a WDF device.
Use the [AcxFactoryCircuitInitAllocate function](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxfactorycircuitinitallocate) to initialize the ACXFACTORYCIRCUIT_INIT structure.

### `Methods`

An [ACX_METHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ns-acxrequest-acx_method_item) structure that defines a set of methods that will be used for circuit initialization.

### `MethodsCount`

The number of methods that will be assigned to the circuit. This is a one based count.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

Drivers should only add driver owned methods.

### Example

Example usage is shown below.

```cpp
typedef enum {
    KSMETHOD_APXCIRCUITFACTORY_ADD_CIRCUIT        = 1,
    KSMETHOD_APXCIRCUITFACTORY_REMOVE_CIRCUIT     = 2,
} KSMETHOD_APXCIRCUITFACTORY;

static ACX_METHOD_ITEM s_FactoryCircuitMethods[] =
{
    {
        &KSMETHODSETID_ApxCircuitFactory,
        KSMETHOD_APXCIRCUITFACTORY_ADD_CIRCUIT,
        ACX_METHOD_ITEM_FLAG_SEND,
        &C_EvtAddCircuitCallback,
        NULL,                                       // Reserved
        sizeof(APX_CIRCUIT_FACTORY_ADD_CIRCUIT),    // ControlCb
        0,                                          // ValueCb
    },
    /*
    {
        &KSMETHODSETID_ApxCircuitFactory,
        KSMETHOD_APXCIRCUITFACTORY_REMOVE_CIRCUIT,
        ACX_METHOD_ITEM_FLAG_SEND,
        &EvtRemoveCircuitCallback,
        NULL,                                       // Reserved
        sizeof(APX_CIRCUIT_FACTORY_REMOVE_CIRCUIT), // ControlCb
        0,                                          // ValueCb
    },
    */
};
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

    //
    // Add properties, events and methods.
    //
    status = AcxFactoryCircuitInitAssignMethods(factoryInit,
                                                s_FactoryCircuitMethods,
                                                s_FactoryCircuitMethodsCount);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)