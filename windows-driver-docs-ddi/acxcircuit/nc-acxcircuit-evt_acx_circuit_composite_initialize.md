## Description

The **EVT_ACX_CIRCUIT_COMPOSITE_INITIALIZE** callback is used by the driver to do any post-initialization after the composite endpoint has been assembled by ACX Manager.

## Parameters

### `Device`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that is associated with the specified ACXCIRCUIT.

### `Circuit`

The ACXCIRCUIT object being initialized. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `CompositeProperties`

Optional handle to CompositeProperties that describes the composite circuit. This is an optional ACXOBJECTBAG object for composite endpoint's properties.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

This sample code shows how the driver retrieves a composite property from the specified composite property object bag.

```cpp
EVT_ACX_CIRCUIT_COMPOSITE_INITIALIZE CodecR_EvtCircuitCompositeInitialize;

NTSTATUS
CodecR_EvtCircuitCompositeInitialize(
    _In_ WDFDEVICE      Device,
    _In_ ACXCIRCUIT     Circuit,
    _In_ ACXOBJECTBAG   CompositeProperties
    )
{
    PAGED_CODE();

    NTSTATUS status = STATUS_SUCCESS;

    UNREFERENCED_PARAMETER(Device);
    UNREFERENCED_PARAMETER(Circuit);

    ASSERT(CompositeProperties);

    DECLARE_CONST_ACXOBJECTBAG_SYSTEM_PROPERTY_NAME(UniqueID);
    GUID uniqueId = {0};
    status = AcxObjectBagRetrieveGuid(CompositeProperties, &UniqueID, &uniqueId);

    // ...

    return status;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)