# _NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX structure

## Description

The **NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX** structure defines media-specific information that is
associated with a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
structure (NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX). The driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_NBL_MEDIA_SPECIFIC_INFO_REVISION_1, and the
**Size** member to NDIS_SIZEOF_NBL_MEDIA_SPECIFIC_INFO_REVISION_1.

### `NextEntry`

A pointer to the next NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX structure in a linked list of
NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX structures. If this is the last structure in the list, the
pointer is **NULL**. Drivers must use the
[NDIS_NBL_ADD_MEDIA_SPECIFIC_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_specific_information_ex),
[NDIS_NBL_GET_MEDIA_SPECIFIC_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-nbl-get-media-specific-info-ex), and
[NDIS_NBL_REMOVE_MEDIA_SPECIFIC_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_specific_information_ex) macros to manipulate this list.

### `Tag`

A unique value (assigned by Microsoft) that identifies the type of media-specific information.
This member is reserved for system use.

New tags can be assigned in future system releases for new media types that require additional OOB
data specific to a particular media type.

### `Data`

A pointer to a buffer that contains the media-specific information.

## Remarks

NDIS 6.20 and later drivers should use the NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX structure to specify
media-specific information. Any driver in an NDIS driver stack can allocate and manage media-specific
information. The media-specific information is specified in a NULL-terminated linked list of
NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX structures, and each structure contains driver-allocated and
driver-defined data.

Structures in the list contain any media-specific out-of-band (OOB) data that accompanies the
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures that are associated with a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

If a protocol driver allocated the OOB data, it configured the data for a send operation. If a
miniport driver allocated the data, it configured the data for a receive indication.

To get the first element in the linked list, an NDIS driver calls the
[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro and specifies
the
**MediaSpecificInformationEx** information type.

To add, get, and remove NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX structures in the linked list, use the
[NDIS_NBL_ADD_MEDIA_SPECIFIC_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_specific_information_ex),
[NDIS_NBL_GET_MEDIA_SPECIFIC_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-nbl-get-media-specific-info-ex), and
[NDIS_NBL_REMOVE_MEDIA_SPECIFIC_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_specific_information_ex) macros.

## See also

[NDIS_NBL_ADD_MEDIA_SPECIFIC_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_specific_information_ex)

[NDIS_NBL_GET_MEDIA_SPECIFIC_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-nbl-get-media-specific-info-ex)

[NDIS_NBL_MEDIA_SPECIFIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_media_specific_information)

[NDIS_NBL_REMOVE_MEDIA_SPECIFIC_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_specific_information_ex)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info)