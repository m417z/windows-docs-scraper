# ListType function

## Description

The **ListType** function calls a specified callback function for every element in a linked list.

## Parameters

### `Type` [in]

Specifies the name of the type of each entry in the linked list.

### `Address` [in]

#### If ListByFieldAddress is zero:

Specifies the address in the target's memory of the first entry in the linked list.

#### If ListByFieldAddress is 1:

Specifies the address in the target's memory of the member of the first entry that points to the next entry.

### `ListByFieldAddress` [in]

Specifies whether *Address* contains the base address of the first entry, or if it contains the address of the member of the first entry that points to the next entry.

### `NextPointer` [in]

Specifies the name of the member in the structure of type *Type* that contains a pointer to the next entry in the linked list. *NextPointer* can be a period-separated path, for example, if *Type* is "nt!_ETHREAD", *NextPointer* could be "Tcb.ThreadListEntry.Flink".

### `Context` [in]

Specifies a pointer that is passed to the callback function specified by *CallbackRoutine* each time the callback function is called.

### `CallbackRoutine` [in]

Specifies a function that is called for each entry in the linked list. The parameters passed to the function are the *Context* pointer and a [FIELD_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_field_info) structure; the address of the entry is found in the **address** member of this structure.

## Return value

This function returns **TRUE** on success and **FALSE** on failure.