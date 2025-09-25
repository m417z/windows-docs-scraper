# _NDK_EXTENSION_INTERFACE structure

## Description

The **NDK_EXTENSION_INTERFACE** structure specifies dispatch function entry points for an NDK extension interface.

## Members

### `Dispatch`

An entry point for an extension interface dispatch function.

## Remarks

An extension interface is identified by a GUID and represented as a pointer to an **NDK_EXTENSION_INTERFACE** function dispatch table.

Each NDK object contains a [NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface) function pointer in its object type-specific function dispatch table. This function allows a driver to query the extended interfaces the object type supports.

**Tip** There are currently no standard extension interfaces defined.

## See also

[NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface)