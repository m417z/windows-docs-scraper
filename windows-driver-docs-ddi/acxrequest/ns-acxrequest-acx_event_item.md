## Description

The **ACX_EVENT_ITEM** structure describes an event item that is the target of an ACX request.

## Members

### `Set`

Specifies a GUID that identifies a KS (kernel streaming) event item set.

### `Id`

Specifies the member of the event set.

### `Flags`

The Flags field can be used to set the following Flags defined in the AcxRequest header.

```cpp

#define ACX_EVENT_ITEM_FLAG_NONE                0x00000000
#define ACX_EVENT_ITEM_FLAG_ENABLE              0x00000001 // KSEVENT_TYPE_ENABLE
#define ACX_EVENT_ITEM_FLAG_BASICSUPPORT        0x00000200 // KSEVENT_TYPE_BASICSUPPORT

```

### `EvtAcxObjectProcessRequest`

The [EVT_ACX_OBJECT_PROCESS_REQUEST callback](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/nc-acxrequest-evt_acx_object_process_request) event handler associated with this item.

### `Reserved`

This field is reserved.

## Remarks

### Example

Example usage is shown below.

```cpp

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxrequest.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/)