# _NDIS_WWAN_PIN_APP structure

## Description

The **NDIS_WWAN_PIN_APP** structure specifies the target application ID for a UICC application whose PIN is being queried.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_PIN_APP** structure. The MB Service sets the header with the values that are shown in the following table when it sends the data structure to the miniport driver for set operations. Miniport drivers must set the header with the same values when they send the data structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_PIN_APP_REVISION_1 |
| Size | sizeof(NDIS_WWAN_PIN_APP) |

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `PinApp`

A formatted [**WWAN_PIN_APP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pin_app) structure that describes the application ID.

## Remarks

This structure is used in the payload of an [OID_WWAN_PIN_EX2](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-pin-ex2) Query request.

## See also

[MB UICC application and file system access](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-application-and-file-system-access)

[OID_WWAN_PIN_EX2](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-pin-ex2)

[**WWAN_PIN_APP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pin_app)