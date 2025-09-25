## Description

The **AcxCircuitInitAssignMethods** function assigns one or more ACX methods for the ACXCIRCUIT.

## Parameters

### `CircuitInit`

The ACXCIRCUIT_INIT structure that defines the circuit initialization. ACXCIRCUIT_INIT is an opaque object used for circuit initialization. Use [AcxCircuitInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitallocate) to initialize the ACXCIRCUIT_INIT structure.

### `Methods`

An [ACX_METHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ns-acxrequest-acx_method_item) structure that defines a set of methods that will be used for circuit initialization.

### `MethodsCount`

The number of methods that will be added to the circuit. This is a one based count.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

Drivers should only add driver owned methods.

### Example

Example usage is shown below.

```cpp

static ACX_METHOD_ITEM CircuitMethods[] =
{
    {
        &KSMETHODSETID_AcxTestMethod,
        KSMETHOD_ACXCIRCUIT_TEST2_IN2OUT,
        ACX_METHOD_ITEM_FLAG_SEND,
        Amp_EvtTestIn2OutMethodCallback,
        NULL,               // Reserved
        sizeof(ULONG),      // ArgsCb
        sizeof(ULONG),      // ResultCb
    },
};

static ULONG CircuitMethodsCount = SIZEOF_ARRAY(CircuitMethods);

    status = AcxCircuitInitAssignMethods(circuitInit,
                                         CircuitMethods,
                                         CircuitMethodsCount);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)