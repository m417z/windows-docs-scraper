# GetFieldValue macro

## Description

The **GetFieldValue** macro is a thin wrapper around the [GetFieldData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-getfielddata) function. It is provided as a convenience for reading the value of a member in a structure.

## Parameters

### `Addr`

Specifies the address of the structure in the target's memory.

### `Type`

Specifies the name of the type of the structure. This can be qualified with a module name, for example, **mymodule!mystruct**.

### `Field`

Specifies the name of the member in the structure. Submembers can be specified by using a period-separated path, for example, "myfield.mysubfield".

### `OutValue`

Specifies the object into which the member's value is read.

## Remarks

The parameters provided to this macro are the same as those provided to the **GetFieldData** function except that instead of providing a pointer to a buffer and its size, the variable to hold the returned value can be provided directly.

### Returns

If the function succeeds, the return value is zero. Otherwise, the return value is one of the *IG_DUMP_SYMBOL_INFO* error code.

## See also

[GetFieldData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-getfielddata)