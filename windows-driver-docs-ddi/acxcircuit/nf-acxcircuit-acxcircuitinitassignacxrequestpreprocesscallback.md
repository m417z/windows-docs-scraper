## Description

The **AcxCircuitInitAssignAcxRequestPreprocessCallback** function add a WDFREQUEST preprocess callback.

## Parameters

### `CircuitInit`

The ACXCIRCUIT_INIT structure that defines the circuit initialization. ACXCIRCUIT_INIT is an opaque object used for circuit initialization. Use [AcxCircuitInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitallocate) to initialize the ACXCIRCUIT_INIT structure.

### `EvtObjectAcxRequestPreprocess`

A pointer to a [EVT_ACX_OBJECT_PREPROCESS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/nc-acxrequest-evt_acx_object_preprocess_request) callback.

### `DriverContext`

The driver context defined by the ACXCONTEXT object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `RequestType`

An [ACX_REQUEST_TYPE enum](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ne-acxrequest-acx_request_type) that defines different request types, such as AcxRequestTypeAny, AcxRequestTypeProperty, etc.

### `Set`

Optional GUID to identify a specific item set ID.

### `Id`

An ID to identify a specific item in the specified set ID.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The driver can invoke this DDI multiple times to setup different preprocess callbacks. ACX invokes the first it finds that matches the specific incoming WDFREQUEST type.

### Example

Example usage is shown below.

```cpp
    // Render callbacks.

    EVT_ACX_OBJECT_PREPROCESS_REQUEST   CodecR_EvtCircuitRequestPreprocess;

    //
    // Add circuit type.
    //
    AcxCircuitInitSetCircuitType(circuitInit, AcxCircuitTypeRender);

    //
    // Assign the circuit's pnp-power callbacks.
    //
    ACX_CIRCUIT_PNPPOWER_CALLBACKS_INIT(&powerCallbacks);
    powerCallbacks.EvtAcxCircuitPowerUp = CodecR_EvtCircuitPowerUp;
    powerCallbacks.EvtAcxCircuitPowerDown = CodecR_EvtCircuitPowerDown;
    AcxCircuitInitSetAcxCircuitPnpPowerCallbacks(circuitInit, &powerCallbacks);

    //
    // Set circuit-callbacks.
    //
    status = AcxCircuitInitAssignAcxRequestPreprocessCallback(
                                            circuitInit,
                                            CodecR_EvtCircuitRequestPreprocess,
                                            (ACXCONTEXT)AcxRequestTypeAny, // dbg only
                                            AcxRequestTypeAny,
                                            NULL,
                                            AcxItemIdNone);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)