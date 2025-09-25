## Description

The *LookasideListFreeEx* routine frees the storage for a lookaside-list entry when a client tries to insert the entry into a lookaside list that is full.

## Parameters

### `Buffer` [in]

A pointer to the lookaside-list entry that is to be freed.

### `Lookaside` [in, out]

A pointer to a [LOOKASIDE_LIST_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that describes the lookaside list. This structure was previously initialized by the [ExInitializeLookasideListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializelookasidelistex) routine.

## Remarks

A driver that creates a lookaside list can implement a *LookasideListFreeEx* routine to free previously allocated buffers when the list becomes full and can contain no more buffers. A buffer that is not in use is stored as an entry in the list. All entries in a lookaside list are buffers of a uniform size, which the driver specifies when the list is initialized.

The driver supplies a pointer to a custom *LookasideListFreeEx* routine as an input parameter in the **ExInitializeLookasideListEx** call that initializes the lookaside list. If the driver sets this parameter to **NULL**, the lookaside list uses a default deallocation routine instead.

A driver calls the [ExFreeToLookasideListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreetolookasidelistex) routine to insert a previously allocated entry into a lookaside list. If the list is full (that is, if the list already contains the system-determined maximum number of entries), **ExFreeToLookasideListEx** calls *LookasideListFreeEx* to free the storage for the entry.

The *LookasideListFreeEx* routine can use the *Lookaside* parameter to access private context data that the driver has associated with the lookaside list. For more information, see the code example in [ExInitializeLookasideListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializelookasidelistex).

For more information about lookaside lists, see [Using Lookaside Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-lookaside-lists).

The *LookasideListFreeEx* routine is called at the same IRQL as the call to **ExFreeToLookasideListEx** that frees the entry. For a call to free an entry that resides in paged memory, the caller must be running IRQL <= APC_LEVEL. For a call to free an entry that resides in nonpaged memory, the caller must be running IRQL <= DISPATCH_LEVEL.

### Examples

To define a *LookasideListFreeEx* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *LookasideListFreeEx* callback routine that is named `MyLookasideListFreeEx`, use the FREE_FUNCTION_EX type as shown in this code example:

```cpp
FREE_FUNCTION_EX MyLookasideListFreeEx;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
VOID
  MyLookasideListFreeEx(
    PVOID  Buffer,
    PLOOKASIDE_LIST_EX  Lookaside
    )
  {
      // Function body
  }
```

The FREE_FUNCTION_EX function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the FREE_FUNCTION_EX function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[ExFreeToLookasideListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreetolookasidelistex)

[ExInitializeLookasideListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializelookasidelistex)

[LOOKASIDE_LIST_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)