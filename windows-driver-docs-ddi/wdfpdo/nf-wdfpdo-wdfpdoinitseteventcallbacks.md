# WdfPdoInitSetEventCallbacks function

## Description

[Applies to KMDF only]

The **WdfPdoInitSetEventCallbacks** method registers a bus driver's event callback functions.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `DispatchTable` [in]

A pointer to a caller-allocated [WDF_PDO_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/ns-wdfpdo-_wdf_pdo_event_callbacks) structure.

## Remarks

The bus driver must allocate a [WDF_PDO_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/ns-wdfpdo-_wdf_pdo_event_callbacks) structure and fill in the structure with pointers to the driver's event callback functions.

The driver must call **WdfPdoInitSetEventCallbacks** before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfPdoInitSetEventCallbacks** and **WdfDeviceCreate**, see [Creating Device Objects in a Bus Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-device-objects-in-a-bus-driver).

#### Examples

The following code example initializes a [WDF_PDO_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/ns-wdfpdo-_wdf_pdo_event_callbacks) structure and then calls **WdfPdoInitSetEventCallbacks**.

```cpp
PWDFDEVICE_INIT  pDeviceInit = NULL;
WDF_PDO_EVENT_CALLBACKS  pdoCallbacks;

pDeviceInit = WdfPdoInitAllocate(Device);
WDF_PDO_EVENT_CALLBACKS_INIT(&pdoCallbacks);
pdoCallbacks.EvtDeviceResourceRequirementsQuery = Bus_Pdo_EvtDeviceResourceRequirementsQuery;
WdfPdoInitSetEventCallbacks(
                            pDeviceInit,
                            &pdoCallbacks
                            );
```

## See also

[WDF_PDO_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdf_pdo_event_callbacks_init)

[WdfPdoInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitallocate)