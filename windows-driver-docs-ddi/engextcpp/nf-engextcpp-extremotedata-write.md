# ExtRemoteData::Write

## Description

The **Write** method writes the data cached by the [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong)) object to the region of memory on the target, represented by this object.

## Remarks

This method can be used to reset the region of memory on the target to the currently cached value that was previously read from the target.

It is also possible to directly set the value cached by the [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong)) object, for example:

```cpp
ExtRemoteData ext_remote_data = new ExtRemoteData(address, sizeof(USHORT));
ext_remote_data.m_Data = (ULONG64) my_ushort;
ext_remote_data.Write();
```

### Returns

This method does not return a value.

## See also

[ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong))

[ExtRemoteData::Read](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-read)