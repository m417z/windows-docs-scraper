# _GET_UNIT_INFO structure

## Description

This structure is used to get unit information.The request retrieves unit information about the device. The Plug and Play ID for a 61883 device is based on its VendorID, ModelID, and Character/Transaction Set.

## Members

### `nLevel`

On input, the level of information to retrieve. Can be one of the following:

GET_UNIT_INFO_IDS

GET_UNIT_INFO_CAPABILITIES

GET_UNIT_INFO_ISOCH_PARAMS

GET_UNIT_BUS_GENERATION_NODE

GET_UNIT_DDI_VERSION

GET_UNIT_DIAG_LEVEL

### `Information`

In input, a pointer to information supplied by the protocol driver about the device.

| Value of nLevel | Action of the Protocol Driver |
| --- | --- |
| GET_UNIT_INFO_IDS | The protocol driver writes device ID information to the caller-allocated [GET_UNIT_IDS](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_get_unit_ids) structure at **Information**. |
| GET_UNIT_INFO_CAPABILITIES | The protocol driver writes a [GET_UNIT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_get_unit_capabilities) structure containing device capability information. |
| GET_UNIT_ISOCH_PARAMS | The protocol driver writes a [UNIT_ISOCH_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_unit_isoch_params) structure containing device parameters used by the device to capture and transmit isochronous packets. |
| GET_UNIT_BUS_GENERATION_NODE | The protocol driver writes current bus characteristics to the caller-allocated [BUS_GENERATION_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_bus_generation_node) structure at **Information**. |
| GET_UNIT_DDI_VERSION | The protocol driver writes current 61883 DDI version to the caller-allocated [UNIT_DDI_VERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_unit_ddi_version) structure at **Information**. |
| GET_UNIT_DIAG_LEVEL | The protocol driver writes current diag level to the caller-allocated [UNIT_DIAG_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_unit_diag_level) structure at **Information**. |

## Remarks

**Flags** in the request specifies either RETRIEVE_DEVICE_UNIT_INFO or RETRIEVE_LOCAL_UNIT_INFO. Only used when **nLevel** is set to GET_UNIT_INFO_CAPABILITIES.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)