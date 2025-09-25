# WdfDriverMiniportUnload function

## Description

[Applies to KMDF only]

The **WdfDriverMiniportUnload** method deletes a specified miniport driver's framework driver object.

## Parameters

### `Driver` [in]

A handle to the driver's framework driver object that the driver obtained from a previous call to [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) or [WdfGetDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfgetdriver).

## Remarks

A miniport driver calls the **WdfDriverMiniportUnload** method when the miniport driver is about to be unloaded. The method calls the driver's [EvtDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_unload) event callback function and deletes the driver's framework driver object.

Typically, a miniport driver calls **WdfDriverMiniportUnload** from within a driver-supplied unload routine that is defined by the port driver's architecture.

For more information about miniport drivers, see [Using Kernel-Mode Driver Framework with Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-kmdf-miniport-drivers).

#### Examples

The following code example deletes a specified miniport driver's framework driver object.

```cpp
WdfDriverMiniportUnload(WdfGetDriver());
```

## See also

[EvtDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_unload)

[WdfDeviceMiniportCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfminiport/nf-wdfminiport-wdfdeviceminiportcreate)

[WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate)

[WdfGetDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfgetdriver)