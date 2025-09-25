# _NDIS_BIND_FAILED_NOTIFICATION structure

## Description

The **NDIS_BIND_FAILED_NOTIFICATION** structure describes a binding event failure.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_BIND_FAILED_NOTIFICATION** structure. NDIS sets the
**Type** member of the structure that
**Header** specifies to **NDIS_OBJECT_TYPE_DEFAULT**, the
**Revision** member to **NDIS_BIND_FAILED_NOTIFICATION_REVISION_1**, and the
**Size** member to **NDIS_SIZEOF_NDIS_BIND_FAILED_NOTIFICATION_REVISION_1**.

### `MiniportNetLuid`

The NDIS network interface
name (*ifName* in RFC 2863) of the miniport adapter.