# PROTOCOL_CLOSE_ADAPTER_COMPLETE_EX callback function

## Description

NDIS calls a protocol driver's
*ProtocolCloseAdapterCompleteEx* function to complete a close adapter operation for which the
[NdisCloseAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseadapterex) function returned
NDIS_STATUS_PENDING.

**Note** You must declare the function by using the **PROTOCOL_CLOSE_ADAPTER_COMPLETE_EX** type. For more
information, see the following Examples section.

## Parameters

### `ProtocolBindingContext` [in]

A handle to a context area allocated by the protocol driver. The protocol driver maintains the
per-binding context information in this context area. The driver supplied this handle to NDIS when the
driver called the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function.

## Remarks

*ProtocolCloseAdapterCompleteEx* is a required function.

If
*ProtocolUnbindAdapterEx* is waiting for NDIS to call
*ProtocolCloseAdapterCompleteEx*, this function can simply indicate that it has been called and
return (for example, it updates the
*ProtocolBindingContext* context area). This allows the
*ProtocolCloseAdapterCompleteEx* function to complete the unbind operation.

After the protocol driver calls the
[NdisCloseAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseadapterex) function, the
*NdisBindingHandle* handle that the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function returned is
no longer valid. Therefore,
*ProtocolCloseAdapterCompleteEx* cannot call any
**Ndis*Xxx*** functions that require this handle as a parameter.

If the
[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex) function has not already done so,
*ProtocolCloseAdapterCompleteEx* can release the resources that the protocol driver allocated for
per-binding network I/O operations.

If
*ProtocolUnbindAdapterEx* returned NDIS_STATUS_PENDING and saved the
*UnbindContext* handle in the context area at
*ProtocolBindingContext*,
*ProtocolCloseAdapterCompleteEx* can call the
[NdisCompleteUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscompleteunbindadapterex) function to complete the unbinding operation. Consequently,
*ProtocolCloseAdapterCompleteEx* should not release the context area until after it calls
**NdisCompleteUnbindAdapterEx**.

NDIS calls
*ProtocolCloseAdapterCompleteEx* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *ProtocolCloseAdapterCompleteEx* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCloseAdapterCompleteEx* function that is named "MyCloseAdapterCompleteEx", use the **PROTOCOL_CLOSE_ADAPTER_COMPLETE_EX** type as shown in this code example:

```
PROTOCOL_CLOSE_ADAPTER_COMPLETE_EX MyCloseAdapterCompleteEx;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyCloseAdapterCompleteEx(
    NDIS_HANDLE  ProtocolBindingContext
    )
  {...}
```

The **PROTOCOL_CLOSE_ADAPTER_COMPLETE_EX** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CLOSE_ADAPTER_COMPLETE_EX** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisCloseAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseadapterex)

[NdisCompleteUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscompleteunbindadapterex)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex)