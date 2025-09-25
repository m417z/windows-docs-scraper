# PROTOCOL_CO_STATUS_EX callback function

## Description

The
*ProtocolCoStatusEx* function indicates status changes from underlying connection-oriented drivers or
from NDIS.

**Note** You must declare the function by using the **PROTOCOL_CO_STATUS_EX** type.
For more information, see the following Examples section.

## Parameters

### `ProtocolBindingContext` [in]

A handle to a protocol driver-allocated context area. The protocol driver maintains the
per-binding context information in this context area. The driver supplied this handle to NDIS when the
driver called the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function.

### `ProtocolVcContext` [in]

A handle to a protocol driver-allocated context area in which the protocol driver maintains
virtual connection (VC) run-time state information. If the status indication is
not VC-specific, this parameter is **NULL**. Otherwise, the protocol driver originally supplied this
handle either when it called the
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) function or from its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

### `StatusIndication` [in]

A pointer to an
[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication) structure
that contains the status information.

## Remarks

NDIS calls
*ProtocolCoStatusEx* to notify a protocol driver about changes in the status of an underlying CoNDIS
driver. A **NULL** VC handle for the
*ProtocolVcContext* parameter indicates a status change that is not specific to a VC. For a non-**NULL**
VC handle, NDIS restricts the status notification to clients or call managers that share this VC
handle.

NDIS serializes status indications for each protocol binding. To determine link status, use the status
indications from underlying drivers instead of OID queries. These status indications will improve system
performance and avoid possible race conditions.

NDIS calls
*ProtocolCoStatusEx* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *ProtocolCoStatusEx* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCoStatusEx* function that is named "MyCoStatusEx", use the **PROTOCOL_CO_STATUS_EX** type as shown in this code example:

```
PROTOCOL_CO_STATUS_EX MyCoStatusEx;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyCoStatusEx(
    NDIS_HANDLE  ProtocolBindingContext,
    NDIS_HANDLE  ProtocolVcContext,
    PNDIS_STATUS_INDICATION  StatusIndication
    )
  {...}
```

The **PROTOCOL_CO_STATUS_EX** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CO_STATUS_EX** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)