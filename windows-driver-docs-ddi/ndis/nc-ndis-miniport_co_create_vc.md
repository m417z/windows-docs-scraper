# MINIPORT_CO_CREATE_VC callback function

## Description

The
*MiniportCoCreateVc* function is required for connection-oriented miniports.
*MiniportCoCreateVc* is called by NDIS to indicate to the miniport driver that a
new VC is being created.

**Note** You must declare the function by using the **MINIPORT_CO_CREATE_VC** type. For more
information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

Specifies the handle to a miniport driver-allocated context area in which the miniport driver
maintains state information about this instance of the adapter. The miniport driver provided this handle
to NDIS by calling
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `NdisVcHandle` [in]

Specifies a handle, supplied by NDIS, that uniquely identifies the VC being created. This handle
is opaque to the miniport driver and reserved for NDIS library use.

### `MiniportVcContext` [out]

Specifies, on output, a handle to a miniport driver-supplied context area in which the miniport
driver maintains state about the VC.

## Return value

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | Indicates that the miniport driver successfully allocated all necessary resources and prepared itself for handling requests for the newly created VC. |
| **NDIS_STATUS_RESOURCES** | Indicates that the call manager could not obtain dynamically allocated resources necessary for it to operate on the new VC. |

## Remarks

*MiniportCoCreateVc* must be written as a synchronous function and cannot, under
any circumstances, return NDIS_STATUS_PENDING without causing a system-wide failure.

*MiniportCoCreateVc* allocates any necessary resources that the miniport driver
requires to maintain state information about the VC. The resources could include, but are not limited to
memory buffers, events, data structures, and other such similar resources.

After allocating all required resources the miniport driver should initialize the resources into a
usable state and return a pointer to the state area in
*MiniportVcContext*. The handle is set by dereferencing the handle and storing a
pointer to the state buffer as the value of the handle. For example:

```
*MiniportVcContext = SomeBuffer;
```

Miniport drivers
*must* store the handle to the VC,
*NdisVcHandle*, in their state area as it is a required parameter to other NDIS
library routines that are subsequently called by the miniport driver.

### Examples

To define a *MiniportCoCreateVc* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportCoCreateVc* function that is named "MyCoCreateVc", use the **MINIPORT_CO_CREATE_VC** type as shown in this code example:

```
MINIPORT_CO_CREATE_VC MyCoCreateVc;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyCoCreateVc(
    NDIS_HANDLE  MiniportAdapterContext,
    NDIS_HANDLE  NdisVcHandle,
    PNDIS_HANDLE  MiniportVcContext
    )
  {...}
```

The **MINIPORT_CO_CREATE_VC** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_CO_CREATE_VC** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)