## Description

The AcxFactoryCircuitCreate function is used to create an ACXFACTORYCIRCUIT.

## Parameters

### `Device`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that will be associated with the circuit.

### `Attributes`

Additional Attributes defined using a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) that are used to set the various object's values: cleanup and destroy callbacks, context type, and to specify its WDF parent object.

### `Config`

The ACXFACTORYCIRCUIT_INIT structure that defines the circuit factory initialization. ACXFACTORYCIRCUIT_INIT is an opaque object used for circuit factory initialization. Use [AcxFactoryCircuitInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxfactorycircuitinitallocate) to initialize the ACXFACTORYCIRCUIT_INIT structure.

### `Factory`

A pointer to a location that receives a handle to the new ACXFACTORYCIRCUIT Object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The ACXFACTORYCIRCUIT is used by the ACX framework for 'on-demand' ACXCIRCUITs. ACX will ask the ACXFACTORYCIRCUIT to create a new circuit when an endpoint requires one.

The ACXFACTORYCIRCUIT is used in a multi-circuit endpoint. A circuit created by an ACXFACTORYCIRCUIT cannot be the 'core' circuit for the endpoint, i.e., the circuit that gives the endpoint identity.

An ACXFACTORYCIRCUIT has a dedicated WDF queue. For more information about WDF queues, see [Framework Queue Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-queue-objects).

An AcxFactoryCircuit can only be created on FDOs (not on RAW PDOs). The ACXFACTORYCIRCUIT object uses its FDO's static child list which is not available on a RAW PDO. For more information, see [Static Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/static-enumeration) and [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration) in the WDF documentation.

### Example

Example usage is shown below.

```cpp
    NTSTATUS                                        status;
    WDF_OBJECT_ATTRIBUTES                           attributes;
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
    AcxFactoryCircuitInitAssignName(factoryInit, &s_FactoryName);

    //
    // Assign the circuit's operation-callbacks.
    //
    ACX_FACTORY_CIRCUIT_OPERATION_CALLBACKS_INIT(&operationCallbacks);
    operationCallbacks.EvtAcxFactoryCircuitCreateCircuitDevice = SdcaXu_EvtAcxFactoryCircuitCreateCircuitDevice;
    operationCallbacks.EvtAcxFactoryCircuitCreateCircuit = SdcaXu_EvtAcxFactoryCircuitCreateCircuit;
    AcxFactoryCircuitInitSetOperationCallbacks(factoryInit, &operationCallbacks);

    //
    // Create the factory circuit.
    //
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, SDCAXU_FACTORYCIRCUIT_CONTEXT);
    attributes.ParentObject = Device;
    status = AcxFactoryCircuitCreate(Device, &attributes, &factoryInit, &factory);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)