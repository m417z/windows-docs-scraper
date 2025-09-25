# UfxDeviceCreate function

## Description

Creates a UFX device object, registers event callback routines, and specifies capabilities specific to the controller.

## Parameters

### `WdfDevice`

A handle to a WDF device object.

### `Callbacks` [in]

A structure of type [UFX_DEVICE_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/ns-ufxclient-_ufx_device_callbacks) that contains pointers to driver-supplied callback routines to be associated with the UFX device object.

### `Capabilities` [in]

A pointer to a [UFX_DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxbase/ns-ufxbase-_ufx_device_capabilities) structure.

### `Attributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains driver-supplied attributes for the new object. This parameter is optional and can be **WDF_NO_OBJECT_ATTRIBUTES**.

### `UfxDevice` [out]

A pointer to a location that receives a handle to the new UFX device object.

## Return value

If the operation is successful, the method returns STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it returns a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

The client driver must call [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) before it calls **UfxDeviceCreate**. Typically, the client driver calls **UfxDeviceCreate** from its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback routine.

The following code snippet shows how to call **UfxDeviceCreate**.

```
NTSTATUS
UfxDevice_DeviceCreate (
    _In_ WDFDEVICE WdfDevice
    )
/*++

Routine Description:

    Routine that registers with UFX and creates the UFX device object.

Arguments:

    WdfDevice - Wdf object representing the device.

Return Value:

    NTSTATUS.

--*/
{
    NTSTATUS Status;
    PCONTROLLER_CONTEXT ControllerContext;
    UFX_DEVICE_CALLBACKS UfxDeviceCallbacks;
    UFX_DEVICE_CAPABILITIES UfxDeviceCapabilities;
    PUFXDEVICE_CONTEXT UfxDeviceContext;
    UFXDEVICE UfxDevice;
    WDF_OBJECT_ATTRIBUTES Attributes;

    PAGED_CODE();

    TraceEntry();

    ControllerContext = DeviceGetControllerContext(WdfDevice);

    UFX_DEVICE_CAPABILITIES_INIT(&UfxDeviceCapabilities);
    UfxDeviceCapabilities.MaxSpeed = UsbSuperSpeed;
    UfxDeviceCapabilities.RemoteWakeSignalDelay = REMOTE_WAKEUP_TIMEOUT_INTERVAL_MS;

    //
    // Set bitmasks that define the IN and OUT endpoint numbers that are available on the controller
    //

    //
    // #### TODO: Set the IN endpoint mask here if not all endpoint addresses are supported ####
    //
    // For illustration purposes sample will set default control endpoint 0, 1-4, 8
    UfxDeviceCapabilities.InEndpointBitmap = 0x011F;

    //
    // #### TODO: Set the OUT endpoint mask here if not all endpoint addresses are supported ####
    //
    // For illustration purposes sample will set default control endpoint 0, 2-7
    //
    UfxDeviceCapabilities.OutEndpointBitmap = 0x00FD;

    //
    // Set the event callbacks for the ufxdevice
    //
    UFX_DEVICE_CALLBACKS_INIT(&UfxDeviceCallbacks);
    UfxDeviceCallbacks.EvtDeviceHostConnect = UfxDevice_EvtDeviceHostConnect;
    UfxDeviceCallbacks.EvtDeviceHostDisconnect = UfxDevice_EvtDeviceHostDisconnect;
    UfxDeviceCallbacks.EvtDeviceAddressed = UfxDevice_EvtDeviceAddressed;
    UfxDeviceCallbacks.EvtDeviceEndpointAdd = UfxDevice_EvtDeviceEndpointAdd;
    UfxDeviceCallbacks.EvtDeviceDefaultEndpointAdd = UfxDevice_EvtDeviceDefaultEndpointAdd;
    UfxDeviceCallbacks.EvtDeviceUsbStateChange = UfxDevice_EvtDeviceUsbStateChange;
    UfxDeviceCallbacks.EvtDevicePortChange = UfxDevice_EvtDevicePortChange;
    UfxDeviceCallbacks.EvtDevicePortDetect = UfxDevice_EvtDevicePortDetect;
    UfxDeviceCallbacks.EvtDeviceRemoteWakeupSignal = UfxDevice_EvtDeviceRemoteWakeupSignal;
    UfxDeviceCallbacks.EvtDeviceTestModeSet = UfxDevice_EvtDeviceTestModeSet;
    UfxDeviceCallbacks.EvtDeviceSuperSpeedPowerFeature = UfxDevice_EvtDeviceSuperSpeedPowerFeature;

    // Context associated with UFXDEVICE object
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&Attributes, UFXDEVICE_CONTEXT);
    Attributes.EvtCleanupCallback = UfxDevice_EvtCleanupCallback;

    // Create the UFXDEVICE object
    Status = UfxDeviceCreate(WdfDevice,
                             &UfxDeviceCallbacks,
                             &UfxDeviceCapabilities,
                             &Attributes,
                             &UfxDevice);

    ...

}
```