# NDIS_NBL_GET_MEDIA_SPECIFIC_INFO macro

## Description

> [!IMPORTANT]
> This macro is supported in NDIS 6.0 and 6.1. For NDIS 6.20 and later, use [**NDIS_NBL_GET_MEDIA_SPECIFIC_INFO_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_nbl_get_media_specific_info_ex).

The **NDIS_NBL_GET_MEDIA_SPECIFIC_INFO** macro gets a media-specific information data structure from a linked list of such structures that are associated with a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

### `_Tag`

A unique pre-assigned value that identifies the type of the media-specific information. This member is reserved for system use.

New tags can be assigned in future system releases for new media types that require additional OOB data specific to a particular media type.

### `_MediaSpecificInfo`

A pointer to an [**NDIS_NBL_MEDIA_SPECIFIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_media_specific_information) structure.

## Remarks

Any NDIS 6.0 or 6.1 driver can use **NDIS_NBL_GET_MEDIA_SPECIFIC_INFO** to get media-specific information from a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. When this macro returns, the *\_MediaSpecificInfo* parameter contains a pointer to the first [**NDIS_NBL_MEDIA_SPECIFIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_media_specific_information) structure in the media-specific information list that has a **Tag** member matching the value specified in the *\_Tag* parameter.

## See also

[**NDIS_NBL_GET_MEDIA_SPECIFIC_INFO_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_nbl_get_media_specific_info_ex)

[**NDIS_NBL_MEDIA_SPECIFIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_media_specific_information)

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)