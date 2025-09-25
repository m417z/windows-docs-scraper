# _NDIS_WWAN_USSD_REQUEST structure

## Description

The NDIS_WWAN_USSD_EVENT structure represents an Unstructured Supplementary Service Data (USSD) NDIS request.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_USSD_REQUEST structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_USSD_REQUEST_REVISION_1 |
| Size | sizeof(NDIS_WWAN_USSD_REQUEST) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `UssdRequest`

A formatted
[WWAN_USSD_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_ussd_request) object that represents a USSD request.

## See also

[WWAN_USSD_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_ussd_request)