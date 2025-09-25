# WdfDeviceSetBusInformationForChildren function

## Description

[Applies to KMDF only]

The **WdfDeviceSetBusInformationForChildren** method sets information about a bus that a bus driver supports. This information is available to the bus's child devices.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `BusInformation` [in]

A pointer to a caller-allocated [PNP_BUS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pnp_bus_information) structure that describes the bus.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

Child devices can obtain the information that **WdfDeviceSetBusInformationForChildren** supplies by calling [WdfFdoInitQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitqueryproperty) or [WdfDeviceQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequeryproperty).

#### Examples

The following code example initializes a PNP_BUS_INFORMATION structure and then calls **WdfDeviceSetBusInformationForChildren**.

```cpp
PNP_BUS_INFORMATION  busInfo;

busInfo.BusTypeGuid = GUID_DEVCLASS_TOASTER;
busInfo.LegacyBusType = PNPBus;
busInfo.BusNumber = 0;

WdfDeviceSetBusInformationForChildren(
                                      device,
                                      &busInfo
                                      );
```

## See also

[PNP_BUS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pnp_bus_information)