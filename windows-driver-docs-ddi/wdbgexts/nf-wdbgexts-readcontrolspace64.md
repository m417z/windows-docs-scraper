# ReadControlSpace64 function

## Description

The **ReadControlSpace64** function reads the processor-specific control space into the array pointed to by *buf*.

## Parameters

### `processor`

Specifies the number of the processor whose control space is to be read.

### `address`

Specifies the address of the control space.

### `buf`

Specifies the address of an array of bytes to hold the control space data.

### `size`

Specifies the number of bytes in the array pointed to by *buf*.

## Remarks

If you are writing 32-bit code, you should use [ReadControlSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-readcontrolspace) instead. See [32-Bit Pointers and 64-Bit Pointers](https://learn.microsoft.com/windows-hardware/drivers/debugger/32-bit-pointers-and-64-bit-pointers) for details.

If you are writing a WdbgExts extension, include **wdbgexts.h**. If you are writing a DbgEng extension that calls this function, include **wdbgexts.h** before **dbgeng.h** (see [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details).

The **ReadTypedControlSpace32** macro is a thin wrapper around the **ReadControlSpace64** function. It is provided as a convenience for reading processor-specific control space into a structure.

```cpp
void ReadTypedControlSpace32(
    _Proc,
    _Addr,
    _Buf
);
```

*_Proc*

Specifies the number of the processor whose control space is to be read.

*_Addr*

Specifies the address of the control space.

*_Buf*

Specifies the object into which the control space data is read.

**Return value**

This macro does not return a value.

The parameters provided to this macro are the same as those provided to the **ReadControlSpace64** function except that instead of providing a pointer to a structure and its size, the structure can be provided directly.

The **ReadTypedControlSpace64** macro is a thin wrapper around the **ReadControlSpace64** function. It is provided as a convenience for reading processor-specific control space into a structure.

```cpp
void ReadTypedControlSpace64(
    _Proc,
    _Addr,
    _Buf
);
```

*_Proc*

Specifies the number of the processor whose control space is to be read.

*_Addr*

Specifies the address of the control space.

*_Buf*

Specifies the object into which the control space data is read.

**Return value**

This macro does not return a value.

The parameters provided to this macro are the same as those provided to the **ReadControlSpace64** function except that instead of providing a pointer to a structure and its size, the structure can be provided directly.