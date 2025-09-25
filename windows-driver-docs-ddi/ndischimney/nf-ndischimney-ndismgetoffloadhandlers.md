# NdisMGetOffloadHandlers function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

This function obtains the entry points of the NDIS functions for a particular chimney type.

## Parameters

### `NdisMiniportHandle` [in]

The handle to a context area that is offload target-allocated in which the offload target
maintains state information about this instance of the adapter. The offload target provided this handle
to NDIS when calling
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `ChimneyType` [in]

A chimney type that is one of the following NDIS_CHIMNEY_OFFLOAD_TYPE values:

#### NdisTcpChimneyOffload

The TCP chimney offload type.

All other NDIS_CHIMNEY_OFFLOAD_TYPE values are currently reserved.

### `OffloadHandlers` [out]

A pointer to a variable supplied by the offload target. The size of this variable is
sizeof(PNDIS_OFFLOAD_EVENT_HANDLERS). If the call to the
**NdisMGetOffloadHandlers** function succeeds, the function returns, in this variable, a pointer to an
NDIS_OFFLOAD_EVENT_HANDLERS structure. This structure serves as a header for the chimney-specific
structure that contains the entry points. The NDIS_OFFLOAD_EVENT_HANDLERS structure is formatted as
follows:

```
typedef struct _NDIS_OFFLOAD_EVENT_HANDLERS {
  NDIS_OBJECT_HEADER  Header;
} NDIS_OFFLOAD_EVENT_HANDLERS, *PNDIS_OFFLOAD_EVENT_HANDLERS;
```

This structure contains the following member:

#### Header

Specifies an NDIS object header, which is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

## Return value

**NdisMGetOffloadHandlers** can return either of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The call succeeded. The returned NDIS entry points are valid for the specified chimney type. |
| **STATUS_NOT_SUPPORTED** | NDIS does not support the chimney type specified by the offload target. In this case, NDIS does not return a valid *OffloadHandlers* pointer. |

## Remarks

The offload target calls this function from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function to
get the entry points of the NDIS functions for a particular chimney type. The offload target calls
**NdisMGetOffloadHandlers** once for each chimney type that it supports. In each call, the offload
target specifies a different chimney type.

If the call to the
**NdisMGetOffloadHandlers** function succeeds, NDIS supplies a valid
*OffloadHandlers* pointer, which points to an NDIS_OFFLOAD_EVENT_HANDLERS structure. This structure
contains an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure. The offload
target examines the
**Type**,
**Revision**, and
**Size** members of the NDIS_OBJECT_HEADER structure. These members specify the structure that contains
the chimney-specific entry points, the revision number of this structure, and the size of this structure
in bytes. The
**Type** value is the same value that the offload target supplied for the
*ChimneyType* parameter.

If the offload target supports the specified
**Revision** number, it casts the
*OffloadHandlers* pointer to a pointer to the appropriate chimney-specific structure type. The
following table indicates the chimney-specific structure for each chimney type.

| *ChimneyType* | Chimney-specific handlers structure |
| --- | --- |
| **NdisTcpChimneyOffload** | [NDIS_TCP_OFFLOAD_EVENT_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_tcp_offload_event_handlers) |

For example, for the
**NdisTcpChimneyOffload** chimney type, the offload target casts the
*OffloadHandlers* pointer to *PNDIS_TCP_OFFLOAD_EVENT_HANDLERS.

The chimney-specific handlers structure contains the same NDIS_OBJECT_HEADER structure as the
NDIS_OFFLOAD_EVENT_HANDLERS structure.

The offload target copies the entry points from the chimney-specific structure into its own internal
data structure and then returns.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_TCP_OFFLOAD_EVENT_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_tcp_offload_event_handlers)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)