# GetFieldData function

## Description

The **GetFieldData** function returns the value of a member in a structure.

## Parameters

### `TypeAddress` [in]

Specifies the address of the structure in the target's memory.

### `Type` [in]

Specifies the name of the type of the structure. This can be qualified with a module name, for example, **mymodule!mystruct**.

### `Field` [in]

Specifies the name of the member in the structure whose value will be returned. Submembers can be specified by using a period-separated path, for example, "myfield.mysubfield".

If the size of the structure pointed to by *TypeAddress* is less than 8 bytes, *Field* can be **NULL**; in this case, the entire structure is copied to *pOutValue*.

### `OutSize` [in]

Specifies the size, in bytes, of the buffer *pOutValue*.

If *OutSize* is smaller than the size of the value returned, an error message is printed and an exception is raised; if the exception is handled or ignored, the return value is zero. In this case, the data beyond the end of the buffer referred to by *pOutValue* might be overwritten.

### `pOutValue` [out]

Receives the value of the member. Or, the value of the type, if *Field* is **NULL**.

## Return value

If the function succeeds, the return value is zero. Otherwise, the return value is an [IG_DUMP_SYMBOL_INFO error code](https://learn.microsoft.com/previous-versions/ff550910(v=vs.85)).