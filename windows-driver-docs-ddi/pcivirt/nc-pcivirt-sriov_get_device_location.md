# SRIOV_GET_DEVICE_LOCATION callback

## Description

Retrieves information about the current location of the PCI device on the bus, such as PCI Segment, Bus, Device and Function number.

## Parameters

### `Context` [in]

A pointer to a driver-defined context.

### `VfIndex` [in]

A zero-based index of the VF to which this read operation applies.

### `SegmentNumber` [out]

A pointer to a variable that is filled in with the current Segment Number, which describes the group of PCI Buses to which this device is attached.

### `BusNumber` [out]

A pointer to a variable that is filled in with the current Bus Number, which describes which PCI Bus to which this device is attached.

### `FunctionNumber` [out]

A pointer to a variable that is filled in with the FunctionNumber, which further describes where on this bus the device can be found.

## Prototype

```cpp
SRIOV_GET_DEVICE_LOCATION SriovGetDeviceLocation;

VOID SriovGetDeviceLocation(
  _In_  PVOID   Context,
  _In_  USHORT  VfIndex,
  _Out_ PUINT16 SegmentNumber,
  _Out_ PUINT8  BusNumber,
  _Out_ PUINT8  FunctionNumber
)
{ ... }

typedef SRIOV_GET_DEVICE_LOCATION *PSRIOV_GET_DEVICE_LOCATION;
```

## Remarks

This callback function is implemented by the physical function (PF) driver. It is invoked when the system wants to retrieve the device location.

The PF driver registers its implementation by setting the **GetDeviceLocation** member of the [SRIOV_DEVICE_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_device_interface_standard), configuring a [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure, and calling [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface).