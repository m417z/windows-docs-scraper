# NDIS_NBL_ADD_MEDIA_SPECIFIC_INFO_EX macro

## Description

The **NDIS_NBL_ADD_MEDIA_SPECIFIC_INFO_EX** macro adds a media-specific information data structure to the beginning of a linked list of such structures that are associated with a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

### `_MediaSpecificInfo`

A pointer to an [**NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_specific_information_ex) structure to add to the linked list.

## Remarks

Any NDIS 6.20 or later driver can use **NDIS_NBL_ADD_MEDIA_SPECIFIC_INFO_EX** to add media-specific information to a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## See also

[**NDIS_NBL_ADD_MEDIA_SPECIFIC_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_nbl_add_media_specific_info)

[**NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_specific_information_ex)

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)