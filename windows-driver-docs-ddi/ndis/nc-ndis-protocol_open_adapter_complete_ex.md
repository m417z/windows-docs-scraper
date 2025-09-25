# PROTOCOL_OPEN_ADAPTER_COMPLETE_EX callback function

## Description

NDIS calls a protocol driver's
*ProtocolOpenAdapterCompleteEx* function to complete an open adapter operation for which the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function returned
NDIS_STATUS_PENDING.

**Note** You must declare the function by using the **PROTOCOL_OPEN_ADAPTER_COMPLETE_EX** type. For more
information, see the following Examples section.

## Parameters

### `ProtocolBindingContext` [in]

A handle to a context area allocated by the protocol driver. The protocol driver maintains the
per-binding context information in this context area. The driver supplied this handle to NDIS when the
driver called
**NdisOpenAdapterEx**.

### `Status` [in]

The final status of the open operation for the underlying miniport driver. This status value is
NDIS_STATUS_SUCCESS if the binding was established or any error status that the underlying driver
determines.

## Remarks

The
*ProtocolOpenAdapterCompleteEx* function is required. A protocol driver calls the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function from its
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function.
NDIS calls the driver's
*ProtocolOpenAdapterCompleteEx* function after a pending open operation is complete.

If
*ProtocolBindAdapterEx* is waiting for NDIS to call
*ProtocolOpenAdapterCompleteEx*, this function can simply save the status and indicate that it has
been called (for example, it can update the
*ProtocolBindingContext* context area). This allows the
*ProtocolBindAdapterEx* function to complete the bind operation.

If the
*ProtocolBindAdapterEx* function has not already done so,
*ProtocolOpenAdapterCompleteEx* can allocate the resources that the driver requires for the
binding.

If
*ProtocolBindAdapterEx* returned NDIS_STATUS_PENDING,
*ProtocolOpenAdapterCompleteEx* can call the
[NdisCompleteBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscompletebindadapterex) function to complete the binding operation. In this case,
*ProtocolOpenAdapterCompleteEx* passes
**NdisCompleteBindAdapterEx** the
*BindContext* handle that NDIS passed to
*ProtocolBindAdapterEx*. If the
*Status* parameter indicates an error,
*ProtocolOpenAdapterCompleteEx* can release binding resources that were set up in
*ProtocolBindAdapterEx*.

NDIS calls
*ProtocolOpenAdapterCompleteEx* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *ProtocolOpenAdapterCompleteEx* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolOpenAdapterCompleteEx* function that is named "MyOpenAdapterCompleteEx", use the **PROTOCOL_OPEN_ADAPTER_COMPLETE_EX** type as shown in this code example:

```
PROTOCOL_OPEN_ADAPTER_COMPLETE_EX MyOpenAdapterCompleteEx;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyOpenAdapterCompleteEx(
    NDIS_HANDLE  ProtocolBindingContext,
    NDIS_STATUS  Status
    )
  {...}
```

The **PROTOCOL_OPEN_ADAPTER_COMPLETE_EX** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_OPEN_ADAPTER_COMPLETE_EX** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisCompleteBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscompletebindadapterex)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)