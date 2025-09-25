# SpbControllerSetTargetAttributes function

## Description

The **SpbControllerSetTargetAttributes** method sets object attributes that will be used for all SPBTARGET objects that the SPB framework extension (SpbCx) delivers to the SPB controller driver.

## Parameters

### `FxDevice` [in]

A WDFDEVICE handle to the device object that represents the SPB controller.

### `ObjectAttributes` [in]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains attributes for the controller's SPBTARGET objects.

## Remarks

Your SPB controller driver calls this method to set the default attributes for SPBTARGET objects. The SPB framework extension (SpbCx) sets these attributes on any target devices on the bus that are opened by clients (peripheral devices) of the controller.

*ObjectAttributes* points to an **WDF_OBJECT_ATTRIBUTES** structure. The caller must previously have called the [WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init) function to initialize this structure. After this call, but before the call to **SpbControllerSetTargetAttributes**, the caller can change the values of the following members of this structure:

* **EvtCleanupCallback**
* **EvtDestroyCallback**
* **ContextSizeOverride**
* **ContextTypeInfo**

**SpbControllerSetTargetAttributes** will use these values as default attributes for SPBTARGET objects. However, the driver cannot change the default attribute values that are contained in the **ExecutionLevel**, **SynchronizationScope**, and **ParentObject** members. These members must remain unchanged from the values that they were initialized to by the **WDF_OBJECT_ATTRIBUTES_INIT** function.

The SPB controller driver must call this method before it *commits* the device object—that is, before it returns from the [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback or adds the PDO to the controller's child list. The child list represents the devices that are attached to the bus. For more information, see [Enumerating the Devices on a Bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus).

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)