# NDIS_NBL_ADD_MEDIA_SPECIFIC_INFO macro

## Description

> [!IMPORTANT]
> This macro is supported in NDIS 6.0 and 6.1. For NDIS 6.20 and later, use [**NDIS_NBL_ADD_MEDIA_SPECIFIC_INFO_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_nbl_add_media_specific_info_ex).

The **NDIS_NBL_ADD_MEDIA_SPECIFIC_INFO** macro adds a media-specific information data structure to the beginning of a linked list of such structures that are associated with a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

### `_MediaSpecificInfo`

A pointer to an [**NDIS_NBL_MEDIA_SPECIFIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_media_specific_information) structure to add to the linked list.

## Remarks

Any NDIS 6.0 or 6.1 driver can use **NDIS_NBL_ADD_MEDIA_SPECIFIC_INFO** to add media-specific information to a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## See also

[**NDIS_NBL_ADD_MEDIA_SPECIFIC_INFO_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_nbl_add_media_specific_info_ex)

[**NDIS_NBL_MEDIA_SPECIFIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_media_specific_information)

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)