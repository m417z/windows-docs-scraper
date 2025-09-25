# ExtRemoteList::HasNode

## Description

The **HasNode** method determines if there is a current item in the list iteration.

## Return value

**HasNode** returns `true` if there is a current item in the list iteration, and `false` otherwise.

## Remarks

Before you call **HasNode**, you must initialize the list for iteration by calling [StartHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotelist-starthead) or [StartTail](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotelist-starttail).

If this method returns `true`, [ExtRemoteList::GetNodeOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotelist-getnodeoffset) can be used to return the current item in the list.

## See also

[ExtRemoteList](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotelist)

[ExtRemoteList::GetNodeOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotelist-getnodeoffset)