## Description

The **EVT_ACX_CIRCUIT_COMPOSITE_CIRCUIT_INITIALIZE** callback is used by the driver to do any initialization of a composite circuit when it is detected and initialized by ACX Manager.

## Parameters

### `Device`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that is associated with the specified ACXCIRCUIT.

### `Circuit`

The ACXCIRCUIT object being initialized. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `CircuitProperties`

Optional handle to CircuitProperties. This is an optional ACXOBJECTBAG object for ACXCIRCUIT's properties.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

This sample code shows how the driver retrieves a circuit property from the specified circuit property object bag.

```cpp
DspR_EvtCircuitCompositeCircuitInitialize(
    _In_     WDFDEVICE      Device,
    _In_     ACXCIRCUIT     Circuit,
    _In_opt_ ACXOBJECTBAG   CircuitProperties
    )
{
    NTSTATUS status = STATUS_SUCCESS;

    PAGED_CODE();

    UNREFERENCED_PARAMETER(Device);
    UNREFERENCED_PARAMETER(Circuit);

    if (CircuitProperties != NULL)
    {
        DECLARE_CONST_ACXOBJECTBAG_DRIVER_PROPERTY_NAME(msft, TestUI4);
        ULONG testUI4;

        status = AcxObjectBagRetrieveUI4(CircuitProperties, &TestUI4, &testUI4);
        if (!NT_SUCCESS(status))
        {
            // Log error.
            goto exit;
        }

        //...
    }

    //...

    // All done.
    status = STATUS_SUCCESS;

exit:
    return status;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)