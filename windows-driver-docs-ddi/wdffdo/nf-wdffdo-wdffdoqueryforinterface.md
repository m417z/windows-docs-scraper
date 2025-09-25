# WdfFdoQueryForInterface function

## Description

[Applies to KMDF only]

The **WdfFdoQueryForInterface** method obtains access to another driver's GUID-identified interface.

## Parameters

### `Fdo` [in]

A handle to a framework device object.

### `InterfaceType` [in]

A pointer to a GUID that identifies the interface.

### `Interface` [out]

A pointer to a driver-allocated structure that receives the requested interface. This structure is defined by the driver that exports the requested interface and must begin with an [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure.

### `Size` [in]

The size, in bytes, of the driver-allocated structure that represents the requested interface.

### `Version` [in]

The version number of the requested interface. The format of this value is defined by the driver that exports the requested interface.

### `InterfaceSpecificData` [in, optional]

Additional interface-specific information. This parameter is optional and can be **NULL**.

## Return value

If the operation succeeds, the method returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The device object is invalid or if the *Device*, *InterfaceType*, or *Interface* parameter is **NULL**. |
| **STATUS_INSUFFICIENT_RESOURCES** | The framework could not allocate a request to send to another driver. |

The method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

Your driver can call **WdfFdoQueryForInterface** to obtain access to a driver-defined interface that was created by a driver that is in the same driver stack that your driver is in. To access a driver-defined interface that was created by a driver that is in a different driver stack, your driver must call [WdfIoTargetQueryForInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetqueryforinterface).

Framework-based drivers define interfaces by calling [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface).

For more information about **WdfFdoQueryForInterface**, see [Using Driver-Defined Interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-driver-defined-interfaces).

#### Examples

The following code example is from the [Toaster](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample function driver. This example obtains access to an interface that the toaster sample bus driver defines.

```cpp
status = WdfFdoQueryForInterface(
                                 Device,
                                 &GUID_TOASTER_INTERFACE_STANDARD,
                                 (PINTERFACE) &fdoData->BusInterface, // Object context space
                                 sizeof(TOASTER_INTERFACE_STANDARD),
                                 1,
                                 NULL
                                 );
```

## See also

[WdfIoTargetQueryForInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetqueryforinterface)