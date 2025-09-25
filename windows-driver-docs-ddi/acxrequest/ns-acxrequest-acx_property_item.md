## Description

The **ACX_PROPERTY_ITEM** structure describes a property item that is the target of an ACX request. A property represents a capability or control-state setting that belongs to an ACX object, such as a circuit, element, pin, stream, etc. For more information, see [KS Properties](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-properties).

## Members

### `Set`

Specifies a GUID that identifies a KS (kernel streaming) property item set. For example, the KSPROPSETID_Topology set ID is the set of topology circuit properties For more information, see [KSPROPERTY structure](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure).

### `Id`

Specifies the member of the property set. For example, KSPROPERTY_TOPOLOGY_NODES of the topology property set is used to retrieve the list of KS NODES (ACXELEMENTS).

### `Flags`

The Flags field is used to set the following Flags defined in the AcxRequest header.

```cpp

#define ACX_PROPERTY_ITEM_FLAG_NONE             0x00000000
#define ACX_PROPERTY_ITEM_FLAG_GET              0x00000001 // KSPROPERTY_TYPE_GET
#define ACX_PROPERTY_ITEM_FLAG_SET              0x00000002 // KSPROPERTY_TYPE_SET
#define ACX_PROPERTY_ITEM_FLAG_BASICSUPPORT     0x00000200 // KSPROPERTY_TYPE_BASICSUPPORT

```

ACX_PROPERTY_ITEM_FLAG_GET - Retrieves the value of the specified property item.

ACX_PROPERTY_ITEM_FLAG_SET - Sets the value of the specified property item.

ACX_PROPERTY_ITEM_FLAG_BASICSUPPORT - Queries the request types that the driver handles for this property item. Returns KSPROPERTY_TYPE_GET or KSPROPERTY_TYPE_SET or both. All property sets must support this flag. And some object may return more info, such as volume ranges etc.

### `EvtAcxObjectProcessRequest`

The [EVT_ACX_OBJECT_PROCESS_REQUEST callback](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/nc-acxrequest-evt_acx_object_process_request) property handler associated with this item.

### `Reserved`

This field is reserved.

### `ControlCb`

The minimum count in bytes (size) of the additional Control buffer. Set to zero if no minimum value.

### `ValueCb`

The minimum count in bytes (size) of the Value buffer. Set to zero if there is no minimum value.

### `ValueType`

The VARENUM type of the property. Set to 0, i.e., VT_EMPTY to use default behavior.

## Remarks

### Example

Example usage is shown below.

```cpp

#define ACX_PROPERTY_ITEM_FLAG_NONE             0x00000000
#define ACX_PROPERTY_ITEM_FLAG_GET              0x00000001 // KSPROPERTY_TYPE_GET
#define ACX_PROPERTY_ITEM_FLAG_SET              0x00000002 // KSPROPERTY_TYPE_SET
#define ACX_PROPERTY_ITEM_FLAG_BASICSUPPORT     0x00000200 // KSPROPERTY_TYPE_BASICSUPPORT

// Pin properties.
static ACX_PROPERTY_ITEM PinProperties[] =
{
    {
        &KSPROPSETID_Pin,
        KSPROPERTY_PIN_DATAFLOW,
        ACX_PROPERTY_ITEM_FLAG_GET,
        &AfxPin::EvtPinDataflowCallback,
        NULL,                       // Reserved
        0,                          // ControlCb
        sizeof(KSPIN_DATAFLOW),     // ValueCb
    },
};

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxrequest.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/)