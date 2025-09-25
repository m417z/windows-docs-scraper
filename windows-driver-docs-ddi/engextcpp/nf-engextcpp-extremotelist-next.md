# ExtRemoteList::Next

## Description

The **Next** method changes the current item to the next item in the list.

## Remarks

If **Next** reaches the end of the list, subsequent calls to [ExtRemoteList::HasNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotelist-hasnode) will return `false`.

## See also

[ExtRemoteList](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotelist)

[ExtRemoteList::HasNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotelist-hasnode)