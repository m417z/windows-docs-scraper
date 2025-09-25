# ExtRemoteTyped::GetTypeFieldOffset

## Description

The **GetTypeFieldOffset** static method returns the offset of a member within a structure.

## Parameters

### `Type` [in]

The name of the type of the structure. This can be qualified with a module name, for example, **mymodule!mystruct**.

### `Field` [in]

The name of the member in the structure. You can specify sub-members by using a dot operator (.) (for example, **mymember.mysubmember**).

## Return value

**GetTypeFieldOffset** returns the number of bytes between the address of an instance of the structure and address of the instance's member.