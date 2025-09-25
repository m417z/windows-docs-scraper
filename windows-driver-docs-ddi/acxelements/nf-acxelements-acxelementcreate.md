## Description

The **AcxElementCreate** function is used to create an ACXELEMENT object that that will be associated with a circuit or stream device object parent.

## Parameters

### `Object`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that that will be associated with the stream or circuit.

### `Attributes`

Additional Attributes defined using a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that are used to set various values and to associate the ACX element with the parent stream or circuit object.

### `Config`

An initialized [ACX_ELEMENT_CONFIG structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_element_config) that describes the configuration of the element.

### `Element`

A pointer to a location that receives the handle to the newly created ACXELEMENT object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
    NTSTATUS                        status;
    WDF_OBJECT_ATTRIBUTES           attributes;

    ACXSTREAM                       stream;

    ACXELEMENT                      elements[2] = {0};
    ACX_ELEMENT_CONFIG              elementCfg;
    CODEC_ELEMENT_CONTEXT *         elementCtx;

    ACX_ELEMENT_CONFIG_INIT(&elementCfg);
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, CODEC_ELEMENT_CONTEXT);
    attributes.ParentObject = stream;

    status = AcxElementCreate(stream, &attributes, &elementCfg, &elements[0]);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)