# _SET_UNIT_INFO structure

## Description

This structure is used to set unit information.

The Av61883_SetUnitInfo request sets the parameters that the IEC-61883 protocol driver should use when capturing and transmitting isochronous packets.

## Members

### `nLevel`

On input, the level of information to retrieve. Can be one of the following:

SET_UNIT_INFO_DIAG_LEVEL

SET_UNIT_INFO_ISOCH_PARAMS

SET_CMP_ADDRESS_RANGE_TYPE

### `Information`

On input, if **nLevel** is SET_UNIT_INFO_DIAG_LEVEL, this member is a pointer to a caller-allocated and initialized [UNIT_DIAG_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_unit_diag_level) structure.

If **nLevel** is SET_UNIT_INFO_ISOCH_PARAMS, this member is a pointer to a caller-allocated [UNIT_ISOCH_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_unit_isoch_params) structure.

If **nLevel** is SET_CMP_ADDRESS_RANGE_TYPE, this member is a pointer to a caller-allocated [SET_CMP_ADDRESS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_set_cmp_address_type) structure.

## Remarks

If successful, the IEC-61883 protocol driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS.

If an incorrect parameter is passed in, the protocol driver sets **Irp->IoStatus.Status** to STATUS_INVALID_PARAMETER.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)