# ExtRemoteList::Prev

## Description

The **Prev** method changes the current item to the previous item in the list.

## Remarks

This method can only be used when iterating over doubly-linked lists.

If **Prev** reaches the end of the list, subsequent calls to [ExtRemoteList::HasNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotelist-hasnode) will return `false`.

## See also

[ExtRemoteList](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotelist)

[ExtRemoteList::HasNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotelist-hasnode)