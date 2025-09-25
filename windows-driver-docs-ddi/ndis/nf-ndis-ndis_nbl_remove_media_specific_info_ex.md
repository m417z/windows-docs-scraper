# NDIS_NBL_REMOVE_MEDIA_SPECIFIC_INFO_EX macro

## Description

The **NDIS_NBL_REMOVE_MEDIA_SPECIFIC_INFO_EX** macro removes a media-specific information data structure from a linked list of such structures that are associated with a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

### `_MediaSpecificInfo`

A pointer to an [**NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_specific_information_ex) structure that has a **Tag** member matching the **Tag** member of the information structure that should be removed.

## Remarks

Any NDIS 6.20 driver can use **NDIS_NBL_REMOVE_MEDIA_SPECIFIC_INFO_EX** to remove an [**NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_specific_information_ex) structure from a list of media-specific information. To specify the type information to remove, specify an **NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX** structure with a matching **Tag** member in the *\_MediaSpecificInfo* parameter.

## See also

[**NDIS_NBL_REMOVE_MEDIA_SPECIFIC_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_nbl_get_media_specific_info)

[**NDIS_NBL_MEDIA_SPECIFIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_specific_information_ex)

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)