# UcxControllerCreate function

## Description

Creates a host controller object.

## Parameters

### `Device` [in]

A handle to the framework device object that the client driver retrieved in the previous call to [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `Config` [in]

A pointer to a caller-allocated [UCX_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/ns-ucxcontroller-_ucx_controller_config) structure that the client driver initialized by calling UCX_CONTROLLER_CONFIG_INIT. The structure contains configuration
information required to create the object.

### `Attributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies attributes for the controller object.

### `Controller` [out]

A pointer to a variable that receives a handle to the new controller object.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

The client driver for the host controller must call this method after the [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) call. The parent of the new host controller object is the framework device object.

During this call, the client driver-supplied event callback implementations are also registered. Supply function pointers to those functions by call setting appropriate members of [UCX_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/ns-ucxcontroller-_ucx_controller_config).

If the parent type is PCI, then initialize the [UCX_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/ns-ucxcontroller-_ucx_controller_config) by calling [UCX_CONTROLLER_CONFIG_SET_PCI_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucx_controller_config_set_pci_info). If the parent is ACPI, call [UCX_CONTROLLER_CONFIG_SET_ACPI_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucx_controller_config_set_acpi_info) instead.

The method creates various queues required to handle IOCTL requests sent to the USB device.

The method registers a device interface GUID_DEVINTERFACE_USB_HOST_CONTROLLER and symbolic link so that user mode components can open a handle to the controller.

#### Examples

```

    WDF_OBJECT_ATTRIBUTES                   objectAttributes;
    UCX_CONTROLLER_CONFIG                   ucxControllerConfig;
    UCXCONTROLLER                           ucxController;
    PUCX_CONTROLLER_CONTEXT                 ucxControllerContext;

    // Create the controller
    //
    UCX_CONTROLLER_CONFIG_INIT(&ucxControllerConfig, "");
    ucxControllerConfig.EvtControllerUsbDeviceAdd = UsbDevice_EvtControllerUsbDeviceAdd;
    ucxControllerConfig.EvtControllerQueryUsbCapability = Controller_EvtControllerQueryUsbCapability;
    ucxControllerConfig.EvtControllerReset = Controller_EvtControllerReset;
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&objectAttributes, UCX_CONTROLLER_CONTEXT);

    status = UcxControllerCreate(wdfDevice,
        &ucxControllerConfig,
        &objectAttributes,
        &ucxController);

    if (!NT_SUCCESS(status)) {
        DbgTrace(TL_ERROR, Controller, "UcxControllerCreate Failed %!STATUS!", status);
        goto Controller_WdfEvtDeviceAddEnd;
    }

    DbgTrace(TL_INFO, Controller, "UCX Controller created.");

    controllerContext->UcxController = ucxController;

    ucxControllerContext = GetUcxControllerContext(ucxController);
    ucxControllerContext->WdfDevice = wdfDevice;

```

## See also

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)