# NDIS_NBL_REMOVE_MEDIA_SPECIFIC_INFO macro

## Description

> [!IMPORTANT]
> This macro is supported in NDIS 6.0 and 6.1. For NDIS 6.20 and later, use [**NDIS_NBL_REMOVE_MEDIA_SPECIFIC_INFO_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_nbl_remove_media_specific_info_ex).

The **NDIS_NBL_REMOVE_MEDIA_SPECIFIC_INFO** macro removes a media-specific information data structure from a linked list of such structures that are associated with a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

### `_MediaSpecificInfo`

A pointer to an [**NDIS_NBL_MEDIA_SPECIFIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_media_specific_information) structure that has a **Tag** member matching the **Tag** member of the information structure that should be removed.

## Remarks

Any NDIS 6.0 or 6.1 driver can use **NDIS_NBL_REMOVE_MEDIA_SPECIFIC_INFO** to remove an [**NDIS_NBL_MEDIA_SPECIFIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_media_specific_information) structure from a list of media-specific information. To specify the type information to remove, specify an **NDIS_NBL_MEDIA_SPECIFIC_INFORMATION** structure with a matching **Tag** member in the *\_MediaSpecificInfo* parameter.

## See also

[**NDIS_NBL_REMOVE_MEDIA_SPECIFIC_INFO_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_nbl_remove_media_specific_info_ex)

[**NDIS_NBL_MEDIA_SPECIFIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_nbl_media_media_specific_information)

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)