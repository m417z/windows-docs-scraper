# _NDIS_NBL_MEDIA_MEDIA_SPECIFIC_INFORMATION structure

## Description

The NDIS_NBL_MEDIA_SPECIFIC_INFORMATION structure specifies media-specific data that is associated
with a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Members

### `NextEntry`

A pointer to the next media-specific information structure in a linked list.

### `Tag`

A unique pre-assigned value that identifies the type of the media-specific information. This
member is reserved for system use.

New tags can be assigned in future system releases for new media types that require additional OOB
data specific to a particular media type.

### `Data`

A variable sized UCHAR array that contains the media-specific information.

## Remarks

Any driver in an NDIS driver stack can allocate and manage media-specific information. The
media-specific information is in a linked list of NDIS_NBL_MEDIA_SPECIFIC_INFORMATION structures that
contain driver-allocated and driver-defined data. Structures in the list contain any media-specific
out-of-band (OOB) data that accompanies the
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures associated with a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

If a protocol driver allocated the OOB data, it configured the data for a send operation. If a
miniport driver allocated the data, it configured the data for a receive indication.

To access NDIS_NBL_MEDIA_SPECIFIC_INFORMATION structures in a linked list, use the
[NDIS_NBL_ADD_MEDIA_SPECIFIC_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-nbl-add-media-specific-info),
[NDIS_NBL_GET_MEDIA_SPECIFIC_INFO](https://learn.microsoft.com/previous-versions/windows/embedded/gg159261(v=winembedded.80)), and
[NDIS_NBL_REMOVE_MEDIA_SPECIFIC_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-nbl-remove-media-specific-info) macros.

## See also

[NDIS_NBL_ADD_MEDIA_SPECIFIC_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-nbl-add-media-specific-info)

[NDIS_NBL_GET_MEDIA_SPECIFIC_INFO](https://learn.microsoft.com/previous-versions/windows/embedded/gg159261(v=winembedded.80))

[NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_specific_information_ex)

[NDIS_NBL_REMOVE_MEDIA_SPECIFIC_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-nbl-remove-media-specific-info)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)