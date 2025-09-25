# PROTOCOL_STATUS_EX callback function

## Description

The
*ProtocolStatusEx* function indicates status-changes from underlying connectionless drivers or
NDIS.

**Note** You must declare the function by using the **PROTOCOL_STATUS_EX** type. For more
information, see the following Examples section.

## Parameters

### `ProtocolBindingContext` [in]

A handle to a context area that the protocol driver allocated. The protocol driver maintains the
per-binding context information in this context area. The driver supplied this handle to NDIS when the
driver called the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function.

### `StatusIndication` [in]

A pointer to an
[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication) structure
that contains the status information.

## Remarks

A call to
*ProtocolStatusEx* notifies the protocol driver about changes in status of an underlying driver.

To determine link status, use the status indications from underlying drivers instead of OID queries.
These status indications will improve system performance and avoid possible race conditions.

NDIS calls the
*ProtocolStatusEx* function of all bound protocol drivers when an underlying driver is resetting a
NIC. First NDIS specifies the
[NDIS_STATUS_RESET_START](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-reset-start) code and
later, when the reset operation is complete, NDIS specifies the
[NDIS_STATUS_RESET_END](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-reset-end) code.

NDIS will not accept send requests and OID requests for a miniport adapter while a reset operation is
in progress, the NDIS_STATUS_RESET_START notification warns bound protocol drivers to stop such requests
on the affected binding until they receive the corresponding NDIS_STATUS_RESET_END notification.

NDIS calls
*ProtocolStatusEx* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *ProtocolStatusEx* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolStatusEx* function that is named "MyStatusEx", use the **PROTOCOL_STATUS_EX** type as shown in this code example:

```
PROTOCOL_STATUS_EX MyStatusEx;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyStatusEx(
    NDIS_HANDLE  ProtocolBindingContext,
    PNDIS_STATUS_INDICATION  StatusIndication
    )
  {...}
```

The **PROTOCOL_STATUS_EX** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_STATUS_EX** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset)

[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication)

[NDIS_STATUS_RESET_END](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-reset-end)

[NDIS_STATUS_RESET_START](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-reset-start)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)