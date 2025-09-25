# _WWAN_LIST_HEADER structure

## Description

The WWAN_LIST_HEADER structure represents the header of a list of MB objects, including the number of
objects in the list that follow the header in memory.

## Members

### `ElementType`

A value from the
[WWAN_STRUCT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_struct_type) enumeration that represents
the type of objects in the list.

### `ElementCount`

The number of elements in the list. The MB Service uses this information to allocate and
reallocate memory for the list.

## Remarks

You can assume that the list of elements is stored in memory immediately following the data structure
that contains the list.

## See also

[NDIS_WWAN_PREFERRED_PROVIDERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_preferred_providers)

[NDIS_WWAN_PROVISIONED_CONTEXTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_provisioned_contexts)

[NDIS_WWAN_SET_PREFERRED_PROVIDERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_preferred_providers)

[NDIS_WWAN_SMS_RECEIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_sms_receive)

[NDIS_WWAN_VISIBLE_PROVIDERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_visible_providers)

[WWAN_STRUCT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_struct_type)