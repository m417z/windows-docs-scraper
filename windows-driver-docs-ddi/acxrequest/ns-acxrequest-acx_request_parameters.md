## Description

The **ACX_REQUEST_PARAMETERS** structure receives parameters that are associated with an I/O ACX request.

The following parameters are based on the service that is being invoked, such as a property, method or event. Drivers can determine which set to use based on the ACX_ITEM_TYPE.

The three uses of this structure facilitate communications back to existing kernel streaming (KS) types. For more information about KS see [KS Properties, Events, and Methods](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-properties--events--and-methods).

For specific information of each of the types, see the following topics.

- [KS Properties](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-properties)
- [KS Events](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-events)
- [KS Methods](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-methods)

In addition the following topics may be useful.

[Audio Drivers Property Sets](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-drivers-property-sets)
[KSIDENTIFIER structure (ks.h)](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksidentifier)

## Members

### `Size`

The size of the structure in bytes.

### `MajorFunction`

The WDF IRP major function that is used for this request, for example IRP_MJ_DEVICE_CONTROL. For more information about WDF IRP, see [IRP Major Function Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-major-function-codes).

### `MinorFunction`

The WDF IRP minor function that is used for this request. For more information about the Minor Function refer to the associated withe major IRP, for example [Plug and Play Minor IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/plug-and-play-minor-irps), [Power Management Minor IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/power-management-minor-irps) and [WMI Minor IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/wmi-minor-irps).

### `Type`

The [ACX_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ne-acxrequest-acx_request_type) enumeration describes the type of items that will be sent in the request. Depending on the type specified, a subset of the parameters listed below will be used.

### `Parameters`

### `Parameters.Property`

Parameters for [KS Properties](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-properties) are being used for the ACX request. For more information, see [KSPROPERTY structure](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure).

### `Parameters.Property.Set`

Specifies a GUID that identifies a kernel streaming property set.

### `Parameters.Property.Id`

Specifies the member of the property set.

### `Parameters.Property.Verb`

An [ACX_PROPERTY_VERB](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ne-acxrequest-acx_property_verb) enumeration that describes the property verb.

### `Parameters.Property.ItemType`

An [ACX_ITEM_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ne-acxrequest-acx_item_type) enumeration that describes the ACX item type being the target of this request.

### `Parameters.Property.ItemId`

The Item ID.

### `Parameters.Property.Control`

A pointer to system service parameters that are used as additional input parameters for the ACX request.

### `Parameters.Property.ControlCb`

The count in bytes (size) of the Property.Control buffer.

### `Parameters.Property.Value`

A pointer to the property value.

### `Parameters.Property.ValueCb`

The count in bytes (size) of the Property.Value buffer.

### `Parameters.Method`

Parameters used for a [KS Methods](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-methods) request.

### `Parameters.Method.Set`

Specifies a GUID that identifies a kernel streaming method set.

### `Parameters.Method.Id`

Specifies the member of the method set.

### `Parameters.Method.Verb`

An [ACX_METHOD_VERB](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ne-acxrequest-acx_method_verb) enumeration that describes the item being sent.

### `Parameters.Method.ItemType`

An [ACX_ITEM_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ne-acxrequest-acx_item_type) enumeration that describes the ACX item type being the target of this request.

### `Parameters.Method.ItemId`

The Item ID of the item being sent.

### `Parameters.Method.Args`

A pointer to optional arguments for the method.

### `Parameters.Method.ArgsCb`

The count in bytes (size) of the optional arguments for the method.

### `Parameters.Method.Result`

A pointer to the result of the method.

### `Parameters.Method.ResultCb`

The count in bytes (size) of the Method.Result buffer.

### `Parameters.Event`

Parameters used for [KS Events](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-events) that are being used for the ACX request. For more information, see [KSEVENT structure](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-structure).

### `Parameters.Event.Set`

Specifies a GUID that identifies a kernel streaming event set.

### `Parameters.Event.Id`

Specifies the member of the event set.

### `Parameters.Event.Verb`

An [ACX_EVENT_VERB](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ne-acxrequest-acx_event_verb) enumeration that describes the item being sent.

### `Parameters.Event.ItemType`

An [ACX_ITEM_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ne-acxrequest-acx_item_type) enumeration that describes the ACX item type being the target of this request.

### `Parameters.Event.ItemId`

The event Item ID.

### `Parameters.Event.Data`

A pointer to the event data.

### `Parameters.Event.DataCb`

The count in bytes (size) of the Event.Data buffer.

### `Parameters.Event.EventData`

An ACXEVENTDATA Object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Parameters.Create`

The structure that contains the create parameters that are being used for the ACX request.

### `Parameters.Create.Control`

A pointer to system service parameters that are used as additional input parameters for the ACX request.

### `Parameters.Create.ControlCb`

The count in bytes (size) of the Create.Control buffer.

## Remarks

Driver must use ACX_REQUEST_PARAMETERS only when working with I/O ACX Requests. Driver must use WDF request DDIs to handle other type of requests.

### Example

Example usage is shown below.

```cpp
    ACX_REQUEST_PARAMETERS              params;

    PAGED_CODE();

    //
    // Get request parameters.
    //
    ACX_REQUEST_PARAMETERS_INIT(&params);
    AcxRequestGetParameters(Request, &params);

    ASSERT(params.Type == AcxRequestTypeMethod);
    ASSERT(params.Parameters.Method.Verb == AcxMethodVerbSend);
    ASSERT(params.Parameters.Method.ArgsCb >= argsCb);

    args = (PAPX_CIRCUIT_FACTORY_ADD_CIRCUIT)params.Parameters.Method.Args;
    argsCb = params.Parameters.Method.ArgsCb; // use real value.
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxrequest.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/)