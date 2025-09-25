# ExtRemoteTyped::GetFieldOffset

## Description

The **GetFieldOffset** method returns the offset of a member from the base address of an instance of the type that is represented by this object.

## Parameters

### `Field` [in]

The name of the member whose offset is requested. Sub-members can be specified using a dot-separated path (for example, **mymember.mysubmember**).

## Return value

**GetFieldOffset** returns the offset of the member from the base address of an instance of the type.

## See also

[ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped)

[GetFieldOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols-getfieldoffset)

**IDebugSymbols::GetFieldOffset**