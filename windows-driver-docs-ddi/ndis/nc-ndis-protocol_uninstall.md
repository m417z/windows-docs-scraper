# PROTOCOL_UNINSTALL callback function

## Description

NDIS calls a protocol driver's
*ProtocolUninstall* function to perform cleanup operations before a protocol driver is
uninstalled.

**Note** You must declare the function by using the **PROTOCOL_UNINSTALL** type. For more
information, see the following Examples section.

## Remarks

The
*ProtocolUninstall* function is optional. The protocol driver registered an entry point, if any, for
this function in the
[NDIS_PROTOCOL_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_driver_characteristics) structure that it passed to the
[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver) function.

In response to a user request to uninstall a protocol driver, NDIS calls a protocol driver's
*ProtocolUninstall* function. NDIS calls
*ProtocolUninstall* after calling the protocol driver's
[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex) function once for each bound adapter.

*ProtocolUninstall* performs driver-determined cleanup operations. For example,
*ProtocolUninstall* could request clients to close open handles to device objects that the protocol
driver exported. Until all such handles are closed, the I/O manager will not call the
[Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload) routine that the protocol driver registered in
the driver object passed to its
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine. After all the handles are
closed,
*ProtocolUninstall* can call
[NdisDeregisterDeviceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisderegisterdeviceex) to delete
any device objects created by the protocol driver.

The protocol lower edge of an intermediate driver might require a
*ProtocolUninstall* function. The intermediate driver can release its protocol edge resources in
*ProtocolUninstall* before NDIS calls its
[MiniportDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_unload) function.

NDIS calls
*ProtocolUninstall* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *ProtocolUninstall* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolUninstall* function that is named "MyUninstall", use the **PROTOCOL_UNINSTALL** type as shown in this code example:

```
PROTOCOL_UNINSTALL MyUninstall;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyUninstall(void)
  {...}
```

The **PROTOCOL_UNINSTALL** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_UNINSTALL** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[MiniportDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_unload)

[NDIS_PROTOCOL_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_driver_characteristics)

[NdisDeregisterDeviceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisderegisterdeviceex)

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex)

[Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload)