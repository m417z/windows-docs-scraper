# _AVC_PIN_DESCRIPTOR structure

## Description

The AVC_PIN_DESCRIPTOR structure describes a pin on an AV/C subunit device.

## Members

### `PinId`

Specifies the offset (or ID) of the pin for which information is to be retrieved.

### `PinDescriptor`

Specifies a KSPIN_DESCRIPTOR structure. This structure is allocated in the nonpaged pool. The subunit driver must not free this pointer.

### `IntersectHandler`

An optional output parameter specifying a data range intersect handler associated with the **DataRanges** member of the **PinDescriptor** member.

### `Context`

An optional output parameter specifying a value to be passed to the **IntersectHandler** when it is called during format negotiation. For more information about what an intersect handler is, see [DataRange Intersections in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/data-range-intersections-in-avstream).

## Remarks

This structure is used with the [AVC_FUNCTION_GET_PIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-pin-descriptor) function code.

This structure is used only as a member inside the AVC_MULTIFUNC_IRB structure. It is not used by itself.

For information about building and sending an AV/C command, see [How to Use Avc.sys](https://learn.microsoft.com/windows-hardware/drivers/stream/using-avc-sys).

A description of the members of the **KSPIN_DESCRIPTOR** structure used in AVC_PIN_DESCRIPTOR follows:

```cpp
typedef struct {
    ULONG                   InterfacesCount;
    const KSPIN_INTERFACE*  Interfaces;
    ULONG                   MediumsCount;
    const KSPIN_MEDIUM*     Mediums;
    ULONG                   DataRangesCount;
    const PKSDATARANGE*     DataRanges;
    KSPIN_DATAFLOW          DataFlow;
    KSPIN_COMMUNICATION     Communication;
    const GUID*             Category;
    const GUID*             Name;
    union {
        LONGLONG            Reserved;
        struct {
            ULONG           ConstrainedDataRangesCount;
            PKSDATARANGE*   ConstrainedDataRanges;
        };
    };
} KSPIN_DESCRIPTOR, *PKSPIN_DESCRIPTOR;
```

## See also

[AV/C Intersect Handler](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/nc-avc-pfnavcintersecthandler)

[AVC_MULTIFUNC_IRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_multifunc_irb)

[KSPIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_descriptor)