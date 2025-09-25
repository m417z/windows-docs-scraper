# _SRBEX_DATA_POWER structure (storport.h)

## Description

The **SRBEX_DATA_POWER** structure contains the request data for an extended power SRB.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Type`

Data type indicator for the bidirectional extended SRB data structure. Set to **SrbExDataTypePower**.

### `Length`

Length of the data in this structure starting with the **SrbPowerFlags** member. Set to SRBEX_DATA_POWER_LENGTH.

### `SrbPowerFlags`

Indicates that the power request is for the adapter if SRB_POWER_FLAGS_ADAPTER_REQUEST is set and that storage device address is reserved. Otherwise, *SrbPowerFlags* will be **NULL**, indicating that the request is for the storage device specified by an address at **AddressOffset** in the [STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block) structure.

### `Reserved`

This member is reserved. Set to 0.

### `DevicePowerState`

An enumerator value of type [STOR_DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-_stor_device_power_state) that specifies the requested power state of the device.

### `PowerAction`

An enumerator value of type [STOR_POWER_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-stor_power_action) that specifies the type of system shutdown that is about to occur. This value is meaningful only if the device is moving into the D1, D2, or D3 power state as indicated by the **DevicePowerState** member.

## See also

[STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block)

[STOR_DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-_stor_device_power_state)

[STOR_POWER_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-stor_power_action)