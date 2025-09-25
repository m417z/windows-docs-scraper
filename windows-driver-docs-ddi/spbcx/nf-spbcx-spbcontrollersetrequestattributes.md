# SpbControllerSetRequestAttributes function

## Description

The **SpbControllerSetRequestAttributes** method sets object attributes that will be used for all SPBREQUEST objects that the SPB framework extension (SpbCx) delivers to the SPB controller driver.

## Parameters

### `FxDevice` [in]

A WDFDEVICE handle to the device object that represents the SPB controller.

### `RequestAttributes` [in]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains attributes for the SPB controller's SPBREQUEST objects.

## Remarks

During device initialization, your SPB controller driver can call this method to set the default attributes for SPBREQUEST objects. Thereafter, SpbCx assigns these attributes to any I/O requests that it delivers (or forwards) to target devices on the bus.

*RequestAttributes* points to an **WDF_OBJECT_ATTRIBUTES** structure. The caller must previously have called the [WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init) function to initialize this structure. After this call, but before the call to **SpbControllerSetRequestAttributes**, the caller can change the values of the following members of this structure:

* **EvtCleanupCallback**
* **EvtDestroyCallback**
* **ContextSizeOverride**
* **ContextTypeInfo**

**SpbControllerSetRequestAttributes** will use these values as default attributes for SPBREQUEST objects. However, the driver cannot change the default attribute values that are contained in the **ExecutionLevel**, **SynchronizationScope**, and **ParentObject** members. These members must remain unchanged from the values that the **WDF_OBJECT_ATTRIBUTES_INIT** function initializes them to.

**WDF_OBJECT_ATTRIBUTES_INIT** initializes the **EvtCleanupCallback** and **EvtDestroyCallback** members to **NULL**. If you change these default values to register an [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) or [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback function, this function is called each time an I/O request arrives in the SPB controller queue, which is managed by SpbCx. Such an I/O request causes the *EvtCleanupCallback* or *EvtDestroyCallback* function to be called even if SpbCx never presents the request to the SPB controller driver (because the request is canceled after it arrives in the queue but before it is passed to the driver).

The SPB controller driver must call **SpbControllerSetRequestAttributes** before it *commits* the device object—that is, before it returns from the [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback or adds the PDO to the controller's child list. The child list represents the devices that are attached to the bus. For more information, see [Enumerating the Devices on a Bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus).

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)