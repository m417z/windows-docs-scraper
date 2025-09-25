# _NDIS_WWAN_SET_UICC_RESET structure

## Description

The **NDIS_WWAN_SET_UICC_RESET** structure represents the passthrough action the MB host specifies for a modem miniport adapter after it resets a UICC card.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_SET_UICC_RESET** structure.
The MB Service sets the header with the values that are shown in the following table when it sends the
data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_UICC_RESET_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SET_UICC_RESET) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `SetUiccReset`

A formatted [WWAN_SET_UICC_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_uicc_reset) structure that represents the passthrough action the host specifies for the miniport adapter after it resets the UICC.

## See also

[MB UICC reset operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-reset-operations)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_WWAN_UICC_RESET](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-reset)

[WWAN_SET_UICC_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_uicc_reset)