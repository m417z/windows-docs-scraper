# MINIPORT_INITIALIZE callback function

## Description

NDIS calls a miniport driver's
*MiniportInitializeEx* function to initialize a miniport adapter for network I/O operations.

**Note** You must declare the function by using the **MINIPORT_INITIALIZE** type. For more
information, see the following Examples section.

## Parameters

### `NdisMiniportHandle` [in]

An NDIS-supplied handle that identifies the miniport adapter that the miniport driver should
initialize.

### `MiniportDriverContext` [in]

A handle to a driver-allocated context area where the driver maintains state and configuration
information. The miniport driver passed this context area to the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function.

### `MiniportInitParameters` [in]

A pointer to an
[NDIS_MINIPORT_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_init_parameters) structure that defines the initialization parameters for the
miniport adapter.

## Return value

*MiniportInitializeEx* can return one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | *MiniportInitializeEx* configured and set up the miniport adapter, and allocated all the resources that the driver must have to perform network I/O operations. |
| **NDIS_STATUS_NOT_ACCEPTED** | *MiniportInitializeEx* could not get the miniport adapter to accept the configuration parameters that *MiniportInitializeEx* obtained from the registry. |
| **NDIS_STATUS_RESOURCES** | *MiniportInitializeEx* could not allocate resources to perform network I/O operations. *MiniportInitializeEx* should call the [NdisWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteerrorlogentry) function to identify the resource conflict (for example, I/O port range, interrupt vector, device memory range, as appropriate). Supplying an error log record gives the user or system administrator information that can be used to reconfigure the computer to avoid such hardware resource conflicts. |
| **NDIS_STATUS_FAILURE** | *MiniportInitializeEx* failed for reasons other than those in the preceding list. The driver should call **NdisWriteErrorLogEntry** with parameters that specify the reason for the failure. |

## Remarks

NDIS calls
*MiniportInitializeEx* as part of a system PnP operation. Drivers specify the
*MiniportInitializeEx* entry point by calling the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function from the
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine. NDIS can call
*MiniportInitializeEx* after
**DriverEntry** returns. For more information, see
[DriverEntry of NDIS
Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/initializing-a-miniport-driver).

For NDIS intermediate drivers, NDIS can call
*MiniportInitializeEx* in the context of the
[NdisIMInitializeDeviceInstanceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiminitializedeviceinstanceex) function or after it returns. Such a driver's
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function
usually calls
**NdisIMInitializeDeviceInstanceEx**.

Drivers can register as a combined miniport driver and intermediate driver (see
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)).
Such a miniport-intermediate driver functions similarly to an intermediate driver layered over a physical
miniport driver. For each virtual or physical device instance of a miniport-intermediate driver, if the
**IMMiniport** registry key is set to
**DWORD:0x0000001**, NDIS calls the
*MiniportInitializeEx* function that the driver registered for the virtual device. Otherwise, NDIS
calls the driver's
*MiniportInitializeEx* function that the driver registered for the physical device.

Until
*MiniportInitializeEx* returns, NDIS submits no requests for the miniport adapter being initialized.
The miniport adapter is in the
*initializing* state.

To obtain configuration information for the miniport adapter, a driver calls the
[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndisopenconfigurationex) and
[NdisReadConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadconfiguration) functions. The
driver can call the
[NdisMGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismgetbusdata) function to obtain
bus-specific information.

Miniport drivers must call the
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function and provide an
[NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_registration_attributes) structure which contains the following
attributes:

* A handle to a driver-allocated context area.
* Appropriate attributes flags.
* The time-out interval for calling its
  [MiniportCheckForHangEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_check_for_hang) function.
* The interface type.

The miniport driver passes
**NdisMSetMiniportAttributes** a handle at the
**MiniportAdapterContext** member of NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES. The driver
maintains state information for the specified miniport adapter in this context area. NDIS passes this
handle as an input parameter to other
*MiniportXxx* functions.

Miniport drivers must set the attributes in the
[NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniportgeneralattributes/ns-miniportgeneralattributes-ndis_miniport_adapter_general_attributes) structure after they set the registration attributes in
the NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES structure and before they set any additional
attributes.

*MiniportInitializeEx* can also allocate resources such as the following:

* Non-paged pool memory
* [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) and
  [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure pools
* Spin locks
* Timers
* IO ports
* DMA
* Shared memory
* Interrupts

If the driver indicates receives with the
[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists) function, the
*MiniportInitializeEx* function should call the
[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool) and
[NdisAllocateNetBufferPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferpool) functions and save the handles returned by these NDIS functions.
Typically, the network data that the driver subsequently indicates with
**NdisMIndicateReceiveNetBufferLists** references structures that were allocated with the
[NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist) function. A driver can also use structures that were
allocated with the
[NdisAllocateNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbuffer), and
[NdisAllocateNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlist) functions.

If driver functions, other than the
[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) function, share
resources,
*MiniportInitializeEx* should call the
[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock) function to set
up any spin locks necessary to synchronize access to such shared resources. Resources that other driver
functions share with
*MiniportInterrupt*, such as NIC registers, are protected by the interrupt object that the driver
set up with the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function. Driver functions access these resources by calling the
[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex) function.

*MiniportInitializeEx* can call the
[NdisAllocateTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatetimerobject) function
with a driver-supplied
[NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function) function and a pointer
to driver-allocated memory for a timer object. Drivers can set up multiple
*NetTimerCallback* functions, each with its own timer object. A driver can call the
[NdisSetTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissettimerobject) function to enable a
periodic
*NetTimerCallback* function. A driver can also call the
**NdisSetTimerObject** function to enable a one-time
*NetTimerCallback* function.

*MiniportInitializeEx* must call the
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function before it calls any
**NdisM*Xxx*** function, such as the
[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndismregisterioportrange) or
[**NdisMMapIoSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismmapiospace) functions, that claims
hardware resources for the miniport adapter.
*MiniportInitializeEx* must call
**NdisMSetMiniportAttributes** before it tries to allocate resources for DMA operations.

If the device supports bus-master DMA,
*MiniportInitializeEx* must call the
[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma) function after it calls
**NdisMSetMiniportAttributes** and before it calls the
[NdisMAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemory) function. If the device supports subordinate DMA,
*MiniportInitializeEx* must call
**NdisMSetMiniportAttributes** before it calls the
[NdisMRegisterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdmachannel) function.

After
*MiniportInitializeEx* calls the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function, NDIS can call the driver's
[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) function. NDIS
calls
*MiniportInterrupt* if the NIC generates an interrupt or if any other device with which the NIC
shares an interrupt generates an interrupt. Note that a miniport driver can get an interrupt as soon as
it calls
**NdisMRegisterInterruptEx** and keeps getting interrupts until its call to the
[NdisMDeregisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterinterruptex) function returns.

*MiniportInitializeEx* should test the NIC to make sure that the hardware is configured correctly. If
the driver must wait for state changes to occur in the hardware,
*MiniportInitializeEx* can use the
[NdisWaitEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswaitevent) function or the
[NdisMSleep](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsleep) function.

After
*MiniportInitializeEx* returns successfully, the miniport adapter is in the
*Paused* state. NDIS can call the
[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart) function to transition the
miniport adapter to the
*Running* state.

If
*MiniportInitializeEx* returns NDIS_STATUS_SUCCESS, the driver should release all the resources for
the miniport adapter in the
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function.

The driver must call **NdisMSetMiniportAttributes** and set the **GeneralAttributes** in the **NDIS_MINIPORT_ADAPTER_ATTRIBUTES** structure if it returns NDIS_STATUS_SUCCESS.

If
*MiniportInitializeEx* failed,
*MiniportInitializeEx* must release all resources that it allocated before it returns and the
miniport adapter returns to the
*Halted* state.

NDIS calls
*MiniportInitializeEx* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *MiniportInitializeEx* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportInitializeEx* function that is named "MyInitializeEx", use the **MINIPORT_INITIALIZE** type as shown in this code example:

```
MINIPORT_INITIALIZE MyInitializeEx;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyInitializeEx(
    NDIS_HANDLE  NdisMiniportHandle,
    NDIS_HANDLE  MiniportDriverContext,
    PNDIS_MINIPORT_INIT_PARAMETERS  MiniportInitParameters
    )
  {...}
```

The **MINIPORT_INITIALIZE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_INITIALIZE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[MiniportCheckForHangEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_check_for_hang)

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)

[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart)

[NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniportgeneralattributes/ns-miniportgeneralattributes-ndis_miniport_adapter_general_attributes)

[NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_registration_attributes)

[NDIS_MINIPORT_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_init_parameters)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisAllocateNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbuffer)

[NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist)

[NdisAllocateNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlist)

[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool)

[NdisAllocateNetBufferPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferpool)

[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock)

[NdisAllocateTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatetimerobject)

[NdisMAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemory)

[NdisMDeregisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterinterruptex)

[NdisMGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismgetbusdata)

[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists)

[**NdisMMapIoSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismmapiospace)

[NdisMRegisterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdmachannel)

[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex)

[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndismregisterioportrange)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[NdisMSleep](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsleep)

[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex)

[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndisopenconfigurationex)

[NdisReadConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadconfiguration)

[NdisSetTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissettimerobject)

[NdisWaitEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswaitevent)

[NdisWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteerrorlogentry)

[NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)