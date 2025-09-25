## Description

The **ACX_METHOD_ITEM** structure describes a method item that is the target of an ACX request.

## Members

### `Set`

Specifies a GUID that identifies a KS (kernel streaming) method item set.

### `Id`

Specifies the member of the member set.

### `Flags`

The Flags field can be used to set the following Flags defined in the AcxRequest header.

```cpp

#define ACX_METHOD_ITEM_FLAG_NONE               0x00000000
#define ACX_METHOD_ITEM_FLAG_SEND               0x00000001 // KSMETHOD_TYPE_SEND
#define ACX_METHOD_ITEM_FLAG_BASICSUPPORT       0x00000200 // KSMETHOD_TYPE_BASICSUPPORT

```

### `EvtAcxObjectProcessRequest`

The [EVT_ACX_OBJECT_PROCESS_REQUEST callback](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/nc-acxrequest-evt_acx_object_process_event_request) method handler associated with this item.

### `Reserved`

This field is reserved.

### `ArgsCb`

The minimum count in bytes (size) of the Args buffer. Set to zero if no minimum value.

### `ResultCb`

The minimum count in bytes (size) of the Result buffer. Set to zero if no minimum value.

### `ResultType`

The minimum count in bytes (size) of the Result buffer. Set to zero if there is no minimum value.

## Remarks

### Example

Example usage is shown below.

```cpp

static ACX_METHOD_ITEM CircuitMethods[] =
{
    {
        &KSMETHODSETID_AcxTestMethod,
        KSMETHOD_ACXCIRCUIT_TEST_IN2OUT,
        ACX_METHOD_ITEM_FLAG_SEND,
        Codec_EvtTestIn2OutMethodCallback,
        NULL,               // Reserved
        sizeof(ULONG),      // ArgsCb
        sizeof(ULONG),      // ResultCb
    },
};

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxrequest.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/)