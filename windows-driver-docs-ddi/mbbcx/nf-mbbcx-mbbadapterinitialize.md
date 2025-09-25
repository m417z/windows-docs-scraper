# MbbAdapterInitialize function

## Description

The **MbbAdapterInitialize** method initializes a newly created NETADAPTER object for MBBCx.

## Parameters

### `Adapter`

A handle to a NetAdapterCx NETADAPTER object obtained in a previous call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method may return an appropriate NTSTATUS error code.

This method might return failure in low resource situations.

## Remarks

The client driver must call this method from within [*EvtMbbDeviceCreateAdapter*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_create_adapter).

For more information, see [Creating the NetAdapter interface for the PDP context/EPS bearer](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-an-mbbcx-client-driver#creating-the-netadapter-interface-for-the-pdp-contexteps-bearer).

## See also