# WdfIoTargetQueryForInterface function

## Description

[Applies to KMDF only]

The **WdfIoTargetQueryForInterface** method obtains access to the GUID-identified, driver-defined interface of a [remote I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/general-i-o-targets).

## Parameters

### `IoTarget` [in]

A handle to a remote I/O target object that was obtained from a previous call to [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate).

### `InterfaceType` [in]

A pointer to a GUID that identifies the interface.

### `Interface` [out]

A pointer to a driver-allocated structure that receives the requested interface. This structure is defined by the driver that exports the requested interface and must begin with an [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure.

### `Size` [in]

The size, in bytes, of the driver-allocated structure that *Interface* points to.

### `Version` [in]

The version number of the requested interface. The driver that exports the requested interface defines the format of this value.

### `InterfaceSpecificData` [in, optional]

Additional interface-specific information. This parameter is optional and can be **NULL**.

## Return value

**WdfIoTargetQueryForInterface** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The *IoTarget*, *InterfaceType*, or *Interface* parameter is **NULL**. |
| **STATUS_INSUFFICIENT_RESOURCES** | the framework could not allocate a request to send to another driver. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Your driver can call **WdfIoTargetQueryForInterface** to obtain access to a driver-defined interface that was created by a driver in a different driver stack. To access a driver-defined interface that was created by a driver that is in the same driver stack as your driver, your driver must call [WdfFdoQueryForInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoqueryforinterface).

Framework-based drivers define interfaces by calling [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface). For more information about driver-defined interfaces, see [Using Driver-Defined Interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-driver-defined-interfaces).

#### Examples

The following code example attempts to gain access to a specified remote I/O target's interface. GUID_RAWPDO_INTERFACE_STANDARD is the GUID that identifies the interface.

```cpp
NTSTATUS status;
RAWPDO_INTERFACE_STANDARD busInterface;

status = WdfIoTargetQueryForInterface(
                                      IoTarget,
                                      &GUID_RAWPDO_INTERFACE_STANDARD,
                                      (PINTERFACE) &busInterface,
                                      sizeof(RAWPDO_INTERFACE_STANDARD),
                                      1,
                                      NULL
                                      );
if (!NT_SUCCESS (status)){
    return status;
}
```

## See also

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface)

[WdfFdoQueryForInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoqueryforinterface)

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)