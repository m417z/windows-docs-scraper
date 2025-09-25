## Description

The **AcxTargetElementGetId** function given an existing ACXTARGETELEMENT object, returns its corresponding ID value.

## Parameters

### `TargetElement`

An existing ACXTARGETELEMENT Object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

The ID value associated with the element.

## Remarks

### Example

```cpp
    ACXTARGETELEMENT targetElement = nullptr;

    targetElement = circuitCtx->TargetVolumeHandler;

    ACX_REQUEST_PARAMETERS_INIT_PROPERTY(&targetParams,
                                         propertySet,
                                         propertyId,
                                         params.Parameters.Property.Verb,
                                         params.Parameters.Property.ItemType,
                                         AcxTargetElementGetId(targetElement),
                                         params.Parameters.Property.Control,
                                         params.Parameters.Property.ControlCb,
                                         params.Parameters.Property.Value,
                                         params.Parameters.Property.ValueCb);

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)