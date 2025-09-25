## Description

The AcxFactoryCircuitInitAssignAcxRequestPreprocessCallback function initializes defined AssignAcxRequest Preprocess callbacks for circuit factories.

## Parameters

### `FactoryInit`

An ACXFACTORYCIRCUIT_INIT structure that is used for circuit factory initialization. This is an opaque structure that is used to store ACX Circuit factory initialization information and associate the factory with a WDF device.
Use the [AcxFactoryCircuitInitAllocate function](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxfactorycircuitinitallocate) to initialize the ACXFACTORYCIRCUIT_INIT structure.

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

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)