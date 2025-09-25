# MINIPORT_RESTART callback function

## Description

The
*MiniportRestart* function initiates a restart request for a miniport adapter that
is paused.

**Note** You must declare the function by using the **MINIPORT_RESTART** type. For more
information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
The miniport driver uses this context area to maintain state information for a miniport adapter.

### `RestartParameters`

A pointer to an
[NDIS_MINIPORT_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_restart_parameters) structure that defines the restart parameters for the miniport
adapter.

## Return value

*MiniportRestart* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | [MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart) successfully restarted the flow of network data through the miniport adapter. |
| **NDIS_STATUS_PENDING** | *MiniportRestart* did not complete the restart operation and the operation will be completed asynchronously. The miniport driver must call the [NdisMRestartComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismrestartcomplete) function when the operation is complete. |
| **NDIS_STATUS_RESOURCES** | [MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart) failed because of insufficient resources. |
| **NDIS_STATUS_FAILURE** | None of the preceding status values applies. In this situation, the driver should call the [NdisWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteerrorlogentry) function with parameters that specify the reason for the failure. |

## Remarks

A driver specifies the
*MiniportRestart* entry point when it calls the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function.

The miniport adapter that is specified by the
*MiniportAdapterContext* parameter enters the
*Restarting* state when NDIS calls
*MiniportRestart*.

When NDIS calls
*MiniportRestart*, a miniport driver:

* Must complete any tasks that are required to resume send and receive operations.
* Optionally modifies the restart attributes that are specified in the
  **RestartAttributes** member of the
  [NDIS_MINIPORT_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_restart_parameters) structure. If the pointer in
  **RestartAttributes** is **NULL**, the miniport driver should not modify or add to the restart attributes
  list. If the pointer in
  **RestartAttributes** is non-**NULL**, it points to an
  [NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes) structure.
  If a miniport driver does not restart, it should not modify any attributes.
* Can provide status indications with the
  [NdisMIndicateStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatestatusex) function.
* Should handle status requests in the
  [MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function.

If a miniport driver modifies the list of restart attributes, the miniport driver:

* Can add new media-specific attributes to the list of restart attributes. In this situation, the
  miniport driver must allocate a new
  [NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes) structure--for example, with the
  [NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority) function--and provide memory space for the new attributes.
  After propagating the restart attributes to overlying drivers, NDIS frees the attributes memory for the
  miniport drivers.
* Can modify the media-specific attributes in the list of restart attributes. If the miniport driver
  requires more memory space, it can free an NDIS_RESTART_ATTRIBUTES structure with the
  [NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory) function and allocate a
  new structure to contain the modified information. After propagating the restart attributes to
  overlying drivers, NDIS frees the attributes memory for the miniport drivers.
* Can modify any field in the
  [NDIS_RESTART_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_general_attributes) structure. When NDIS provides a non-**NULL** pointer in the
  **RestartAttributes** member of the
  [NDIS_MINIPORT_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_restart_parameters) structure, the attributes list contains one entry in which the
  **Oid** member in the
  [NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes) structure
  is
  [OID_GEN_MINIPORT_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-miniport-restart-attributes) and the
  **Data** member contains an NDIS_RESTART_GENERAL_ATTRIBUTES structure.
* Should make sure that the
  [NDIS_RESTART_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_general_attributes) structure contains the correct information. To make sure that the
  NDIS_RESTART_GENERAL_ATTRIBUTES structure contains the required information, you should first determine
  the version of the structure by checking the
  **Revision** member in the
  [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure that is
  specified in the
  **Header** member of the NDIS_RESTART_GENERAL_ATTRIBUTES structure.

NDIS does not initiate other Plug and Play (PnP) operations for the miniport adapter, such as halt,
initialize, power change, or a pause request, until the restart operation is complete.

After the miniport driver successfully restarts the send and receive operations, it must complete the
restart operation. If the driver returns NDIS_STATUS_SUCCESS from
*MiniportRestart*, the restart operation is complete. If the driver returns
NDIS_STATUS_PENDING, it can continue restart operations. The restart operation is complete after the
driver calls the
[NdisMRestartComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismrestartcomplete) function. After
the restart operation is complete, the miniport adapter is in the
*Running* state.

The miniport driver can resume indicating received packets for the miniport adapter immediately after
NDIS calls
*MiniportRestart* and before the driver calls
**NdisMRestartComplete**. The miniport driver should be ready to accept send requests after the driver
completes the restart request.

If the miniport driver does not restart the send and receive operations, the driver must return an
appropriate failure status from
*MiniportRestart*. In this situation, the driver must stop any send or receive
operations that were started and then return to the
*Paused* state.

NDIS calls
*MiniportRestart* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *MiniportRestart* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportRestart* function that is named "MyRestart", use the **MINIPORT_RESTART** type as shown in this code example:

```
MINIPORT_RESTART MyRestart;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyRestart(
    NDIS_HANDLE  MiniportAdapterContext,
    PNDIS_MINIPORT_RESTART_PARAMETERS  RestartParameters
    )
  {...}
```

The **MINIPORT_RESTART** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_RESTART** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request)

[MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause)

[NDIS_MINIPORT_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_restart_parameters)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes)

[NDIS_RESTART_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_general_attributes)

[NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority)

[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory)

[NdisMIndicateStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatestatusex)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisMRestartComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismrestartcomplete)

[NdisWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteerrorlogentry)

[OID_GEN_MINIPORT_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-miniport-restart-attributes)