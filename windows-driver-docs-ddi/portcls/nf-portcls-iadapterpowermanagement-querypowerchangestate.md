# IAdapterPowerManagement::QueryPowerChangeState

## Description

The `QueryPowerChangeState` method is called by PortCls in response to the receipt of an [IRP_MN_QUERY_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-power) power IRP.

## Parameters

### `NewStateQuery` [in]

Specifies the new power state that is being requested for the device. This parameter is a union of type POWER_STATE. The new power state (*NewStateQuery*.**DeviceState**) can be one of the DEVICE_POWER_STATE enumeration values listed in [IAdapterPowerManagement::PowerChangeState](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iadapterpowermanagement-powerchangestate).

## Return value

`QueryPowerChangeState` returns STATUS_SUCCESS if call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

PortCls calls the `QueryPowerChangeState` method on behalf of the system to query the adapter driver for acceptability of a potential device power-state change. The driver can deny the power state change by returning a value other than STATUS_SUCCESS. A call to `QueryPowerStateChange` is not guaranteed to occur prior to all **PowerChangeState** calls.

The code for this method must reside in paged memory.

## See also

[IAdapterPowerManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpowermanagement)

[IAdapterPowerManagement::PowerChangeState](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iadapterpowermanagement-powerchangestate)

[IRP_MN_QUERY_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-power)