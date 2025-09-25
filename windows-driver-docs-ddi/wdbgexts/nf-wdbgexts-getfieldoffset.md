# GetFieldOffset function

## Description

The **GetFieldOffset** function returns the offset of a member from the beginning of a structure.

## Parameters

### `Type` [in]

Specifies the name of the type of the structure. This can be qualified with a module name, for example, **mymodule!mystruct**.

### `Field` [in]

Specifies the name of the member in the structure. Submembers can be specified by using a period-separated path, for example, "myfield.mysubfield".

### `pOffset` [out]

Receives the offset of the member from the beginning of an instance of the structure.

## Return value

If the function succeeds, the return value is zero. Otherwise, the return value is an [IG_DUMP_SYMBOL_INFO error code](https://learn.microsoft.com/previous-versions/ff550910(v=vs.85)).