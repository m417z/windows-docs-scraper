# EVT_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST callback function

## Description

[Applies to KMDF only]

A driver's *EvtDeviceProcessQueryInterfaceRequest* event callback function examines another driver's request for access to a driver-defined interface, before the framework passes the interface to the requesting driver.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `InterfaceType` [in]

A pointer to the GUID that identifies the driver-defined interface.

### `ExposedInterface` [in, out]

A pointer to an [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure that describes the driver-defined interface and was provided by the driver that is requesting access to the interface.

### `ExposedInterfaceSpecificData` [in, out]

A pointer to additional, optional, driver-defined, interface-specific information. Framework-based drivers specify this value by providing a non-**NULL** *InterfaceSpecificData* parameter value when calling [WdfFdoQueryForInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoqueryforinterface).

## Return value

If the *EvtDeviceProcessQueryInterfaceRequest* callback function receives a GUID that it supports, and if the function encounters no errors, it must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**. The framework continues passing the request down the stack to see if additional drivers also support the interface.

The *EvtDeviceProcessQueryInterfaceRequest* callback function must return STATUS_NOT_SUPPORTED if it determines that, for a particular case, it will not service the interface. The framework continues passing the request down the stack to see if another driver supports the interface. For more information about this situation, see the following Remarks section.

If the callback function encounters an error, it must return a status value for which NT_SUCCESS(*status*) equals **FALSE**. The framework fails the other driver's request for the interface and does not pass the request down the stack.

## Remarks

Framework-based drivers register an *EvtDeviceProcessQueryInterfaceRequest* event callback function by calling [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface).

If the driver-defined interface supports only one-way communication and sets the **ImportInterface** member of the [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure that describes the interface to **FALSE**, the *EvtDeviceProcessQueryInterfaceRequest* callback function is optional. When another driver calls [WdfFdoQueryForInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoqueryforinterface), the framework copies the driver-defined interface values into the requesting driver's [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure and then calls the callback function. For one-way communication, you need to provide a callback function only if you want the driver to examine, and possibly modify, the interface values before the framework returns them to the requesting driver.

Your driver must provide an *EvtDeviceProcessQueryInterfaceRequest* event callback function if the driver defines an interface that supports two-way communication (and sets the **ImportInterface** member of the [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure to **TRUE**). The callback function is required because, if **ImportInterface** is **TRUE** and another driver calls [WdfFdoQueryForInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoqueryforinterface), the framework does not copy the driver-defined interface into the requesting driver's interface structure. Instead, the callback function must update the requesting driver's interface structure.

The callback function can modify the interface. In particular, it can:

* Change any value in any member of the interface.
* Allocate a dynamic instance-specific context by modifying the **Context** member of the [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure.

The framework calls your driver's *EvtDeviceProcessQueryInterfaceRequest* callback functions only for GUIDs that the driver has registered by calling [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface). Therefore, these callback functions do not use the STATUS_NOT_SUPPORTED return value to report unexpected GUIDs. Instead, a *EvtDeviceProcessQueryInterfaceRequest* callback function should return STATUS_NOT_SUPPORTED when it determines that, for a particular case, it will not handle the interface. For example, based on data that the requesting driver provides, your driver might determine that a lower-level driver should service the interface request. The STATUS_NOT_SUPPORTED return value informs the framework that your driver is not servicing the interface request, but a lower-level driver might service it.

For more information about driver-defined interfaces, see [Using Driver-Defined Interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-driver-defined-interfaces).

#### Examples

To define an *EvtDeviceProcessQueryInterfaceRequest* callback function, you must first provide a function declaration that identifies the type of callback function you’re defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it’s a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtDeviceProcessQueryInterfaceRequest* callback function that is named *MyDeviceProcessQueryInterfaceRequest*, use the **EVT_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST** type as shown in this code example:

```
EVT_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST  MyDeviceProcessQueryInterfaceRequest;
```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
NTSTATUS
 MyDeviceProcessQueryInterfaceRequest (
    WDFDEVICE  Device,
    LPGUID  InterfaceType,
    PINTERFACE  ExposedInterface,
    PVOID  ExposedInterfaceSpecificData
    )
  {...}
```

The **EVT_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST** function type is defined in the WdfQueryInterface.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST** function type in the header file are used.
For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers).
For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/cpp/code-quality/annotating-function-behavior).

## See also

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config)

[WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface)

[WdfFdoQueryForInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoqueryforinterface)