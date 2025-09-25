# NDIS_NBL_GET_MEDIA_SPECIFIC_INFO_EX macro

## Description

The **NDIS_NBL_GET_MEDIA_SPECIFIC_INFO_EX** macro gets a media-specific information data structure from a linked list of such structures that are associated with a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

### `_Tag`

A unique pre-assigned value that identifies the type of the media-specific information.

New tags can be assigned in future system releases for new media types that require additional OOB data specific to a particular media type.

### `_MediaSpecificInfo`

A pointer to an [**NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_specific_information_ex) structure.

## Remarks

Any NDIS 6.20 driver can use **NDIS_NBL_GET_MEDIA_SPECIFIC_INFO_EX** to get media-specific information from a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. When this macro returns, the *\_MediaSpecificInfo* parameter contains a pointer to the first [**NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_specific_information_ex) structure in the media-specific information list that has a **Tag** member matching the value specified in the *\_Tag* parameter.

## See also

[**NDIS_NBL_GET_MEDIA_SPECIFIC_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_nbl_get_media_specific_info)

[**NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_specific_information_ex)

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)