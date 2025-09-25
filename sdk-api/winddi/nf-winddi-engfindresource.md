# EngFindResource function

## Description

The **EngFindResource** function determines the location of a resource in a module.

## Parameters

### `h` [in]

Handle to the module that contains the resource. This handle is obtained from [EngLoadModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmodule).

### `iName` [in]

Is an integer identifier representing the name of the resource being looked up.

### `iType` [in]

Is an integer identifier representing the type of the resource being looked up.

### `pulSize` [out]

Pointer to a ULONG in which the resource's size, in bytes, is returned.

## Return value

The return value is a pointer to the address of the specified resource. The function returns **NULL** if an error occurs.

## Remarks

The size of a successfully located resource is returned in *pulSize*.

## See also

[EngLoadModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmodule)

[EngMapModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapmodule)