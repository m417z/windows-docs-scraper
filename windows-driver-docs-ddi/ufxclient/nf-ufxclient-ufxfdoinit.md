# UfxFdoInit function

## Description

Initializes the WDFDEVICE_INIT structure that the client driver subsequently provides when it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

## Parameters

### `WdfDriver` [in]

A handle to the driver's WDF driver object that the driver obtained from a previous call to [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) or [WdfGetDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfgetdriver).

### `DeviceInit` [in, out]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `FdoAttributes` [in, out]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that describes object attributes for the

## Return value

If the operation is successful, the method returns STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it returns a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

The client driver receives a pointer to a framework-allocated [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure in its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function. It then calls **UfxFdoInit** with this pointer before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) to create the WDFDEVICE object.

By default, for WDF drivers, the device's function driver is the power policy owner.

The following code snippet shows how to call **UfxFdoInit**.

```
NTSTATUS
UfxClientDeviceCreate(
    _In_ WDFDRIVER Driver,
    _In_ PWDFDEVICE_INIT DeviceInit
    )
/*++

Routine Description:

    Worker routine called to create a device and its software resources.

Arguments:

    Driver - WDF driver object

    DeviceInit - Pointer to an opaque init structure. Memory for this
                 structure will be freed by the framework when WdfDeviceCreate
                 succeeds. So don't access the structure after that point.

Return Value:

    Appropriate NTSTATUS value

--*/
{
    WDF_OBJECT_ATTRIBUTES DeviceAttributes;
    WDFDEVICE WdfDevice;

    PAGED_CODE();

    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&DeviceAttributes, CONTROLLER_CONTEXT);

    //
    // Do UFX-specific initialization
    //
    Status = UfxFdoInit(Driver, DeviceInit, &DeviceAttributes);

    //
    // Proceed to WdfDeviceCreate
    //

    ...

}
```