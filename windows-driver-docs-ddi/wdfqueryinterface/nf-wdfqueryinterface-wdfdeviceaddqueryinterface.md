# WdfDeviceAddQueryInterface function

## Description

[Applies to KMDF only]

The **WdfDeviceAddQueryInterface** method creates a driver-defined interface that other drivers can query and use.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `InterfaceConfig` [in]

A pointer to a driver-allocated [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure that describes the interface.

## Return value

**WdfDeviceAddQueryInterface** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The method was called at the wrong IRQL. |
| **STATUS_INVALID_PARAMETER** | An input parameter (possibly including members of the WDF_QUERY_INTERFACE_CONFIG structure) was invalid. |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the WDF_QUERY_INTERFACE_CONFIG structure was incorrect. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory. |

For a list of additional return values, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

> [!NOTE]
> WdfDeviceAddQueryInterface cannot be called for a [control device](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-control-device-objects).

Drivers that create driver-defined interfaces typically call **WdfDeviceAddQueryInterface** from within an [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) or [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function.

After a driver calls **WdfDeviceAddQueryInterface** to create a driver-defined interface, another framework-based driver can access the interface by calling [WdfFdoQueryForInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoqueryforinterface).

For more information about driver-defined interfaces, see [Using Driver-Defined Interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-driver-defined-interfaces).

#### Examples

The following code example is from the [Toaster](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample bus driver. This example creates a driver-defined interface that uses the toaster sample's TOASTER_INTERFACE_STANDARD structure.

```cpp
typedef struct _TOASTER_INTERFACE_STANDARD {
 INTERFACE  InterfaceHeader;
  PTOASTER_GET_CRISPINESS_LEVEL  GetCrispinessLevel;
  PTOASTER_SET_CRISPINESS_LEVEL  SetCrispinessLevel;
  PTOASTER_IS_CHILD_PROTECTED  IsSafetyLockEnabled;
} TOASTER_INTERFACE_STANDARD, *PTOASTER_INTERFACE_STANDARD;

TOASTER_INTERFACE_STANDARD  ToasterInterface;
WDF_QUERY_INTERFACE_CONFIG  qiConfig;

//
// Initialize the ToasterInterface structure.
//
RtlZeroMemory(
              &ToasterInterface,
              sizeof(ToasterInterface)
              );

ToasterInterface.InterfaceHeader.Size = sizeof(ToasterInterface);
ToasterInterface.InterfaceHeader.Version = 1;
ToasterInterface.InterfaceHeader.Context = (PVOID)hChild;

ToasterInterface.InterfaceHeader.InterfaceReference =
        WdfDeviceInterfaceReferenceNoOp;
ToasterInterface.InterfaceHeader.InterfaceDereference =
        WdfDeviceInterfaceDereferenceNoOp;

ToasterInterface.GetCrispinessLevel = Bus_GetCrispinessLevel;
ToasterInterface.SetCrispinessLevel = Bus_SetCrispinessLevel;
ToasterInterface.IsSafetyLockEnabled = Bus_IsSafetyLockEnabled;

//
// Initialize the qiConfig structure.
//
WDF_QUERY_INTERFACE_CONFIG_INIT(
                                &qiConfig,
                                (PINTERFACE)&ToasterInterface,
                                &GUID_TOASTER_INTERFACE_STANDARD,
                                NULL
                                );

//
// Create the interface.
//
status = WdfDeviceAddQueryInterface(
                                    hChild,
                                    &qiConfig
                                    );
if (!NT_SUCCESS(status)) {
    return status;
}
```

## See also

[EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware)

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config)

[WDF_QUERY_INTERFACE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdf_query_interface_config_init)

[WdfDeviceInterfaceDereferenceNoOp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceinterfacedereferencenoop)

[WdfDeviceInterfaceReferenceNoOp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceinterfacereferencenoop)

[WdfFdoQueryForInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoqueryforinterface)