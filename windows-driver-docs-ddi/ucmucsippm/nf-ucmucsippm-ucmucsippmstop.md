# UcmUcsiPpmStop function

## Description

Instructs the UcmUcsiCx class extension to stop sending requests to the client driver.

## Parameters

### `PpmObject` [in]

A handle to a Platform Policy Manager (PPM) object that the client driver received in the previous call to [**UcmUcsiPpmCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsippmcreate).

## Remarks

**UcmUcsiPpmStop** indicates that the client driver is no longer ready to receive requests from the class extension. The class extension guarantees that there will not be any requests made to the client after this call returns. The driver should call this DDI when it encounters a fault and wants the class extension to stop sending PPM requests. After the call completes, the driver should start the PPM again using [**UcmUcsiPpmStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsippmstart).

The client driver is expected to call this DDI on driver unload. This call indicates the class extension to start tearing down its internal state machines. It is recommended that the client calls **UcmUcsiPpmStop** from its EVT_WDF_DEVICE_RELEASE_HARDWARE callback.

Because **UcmUcsiPpmStop** relies on sending UCSI commands to PPM over the power-managed WDFQUEUE provided by the client driver, an attempt to call this function from [EVT_WDF_DEVICE_D0_EXIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit) callback results in a failure. That is because at this time, the dispatch gates for the queue are closed.

After the **UcmUcsiPpmStop** returns, [**UcmUcsiPpmStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsippmstart) can be called to start the PPM again.

## See also