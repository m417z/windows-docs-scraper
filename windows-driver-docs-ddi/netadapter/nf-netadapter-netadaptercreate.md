# NetAdapterCreate function

## Description

Creates a NETADAPTER object.

## Parameters

### `AdapterInit` [_In_]

A pointer to a **NETADAPTER_INIT** structure that the client driver previously received from a call to [**NetAdapterInitAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterinitallocate).

### `AdapterAttributes` [_In_opt_]

A pointer to a caller-allocated [**WDF_OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure. The structure’s **ParentObject** must be **NULL**. The parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Adapter` [_Out_]

A pointer to a location that receives a handle to the new NETADAPTER object.

## Return value

The function returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

After it has called [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), the client typically calls **NetAdapterCreate** from within its [*EvtDriverDeviceAdd*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) routine.

For a code example of creating a NETADAPTER, see [Device initialization](https://learn.microsoft.com/windows-hardware/drivers/netcx/device-initialization).

The NETADAPTER object is a standard WDF object. The framework manages its deletion, which occurs when the parent WDFDEVICE is deleted.

## See also