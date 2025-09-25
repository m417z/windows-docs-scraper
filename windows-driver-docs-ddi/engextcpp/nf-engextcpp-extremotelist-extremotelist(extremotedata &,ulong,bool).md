# ExtRemoteList::ExtRemoteList(ExtRemoteData &,ULONG,bool)

## Description

The **ExtRemoteList** constructors create a new instance that wraps a singly-linked or doubly-linked list.

## Parameters

### `Head` [in, ref]

A reference to an [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong)) object, in the target's memory, that wraps the head of the list. The head is not considered to be an item in the list. The type of the head of the list is SINGLE_LIST_ENTRY or LIST_ENTRY.

### `LinkOffset` [in]

The offset from the beginning of a list item to the pointer to the next item in the list. This is the offset of the SINGLE_LIST_ENTRY or LIST_ENTRY structure embedded within the list item structure.

### `Double` [in]

Specifies whether the list is singly-linked or doubly-linked. If *Double* is `true`, the list is doubly-linked. If *Double* is `false`, the list is singly-linked.

## Remarks

For more information about the SINGLE_LIST_ENTRY and LIST_ENTRY structures, see the Windows Driver Kit (WDK) documentation.

## See also

[ExtRemoteList](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotelist)

[ExtRemoteList::ExtRemoteList (ULONG64)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotelist-extremotelist(ulong64_ulong_bool))