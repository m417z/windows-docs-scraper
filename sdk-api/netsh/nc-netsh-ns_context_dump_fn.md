# NS_CONTEXT_DUMP_FN callback function

## Description

The **NS_CONTEXT_DUMP_FN** command
is the dump function for helpers. The dump function is used to print comments, and is
registered in the [RegisterContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registercontext) function. The
following is an example of a dump function. Be aware that **SampleDump** is a
placeholder for the application-defined function name.

## Parameters

### `pwszRouter` [in]

The computer on which to perform the command, or null if the command applies to the local computer. The
default value is null.

### `ppwcArguments` [in]

An array of command arguments. *ppwcArguments*[0] equates to "dump".

### `dwArgCount` [in]

The number of elements in *ppwcArguments*.

### `pvData` [in]

A pointer to an arbitrary buffer of data specified by the parent context.

## Return value

Returns NO_ERROR upon success. Any other return value indicates an error.

## Remarks

When the dump function is called, helpers should print any comments, localized, followed by a
**pushd …** command to enter the helper context, followed by any context-specific
commands, and ending with a **popd** command. More localized comments can be added thereafter, if
desired.

## See also

[NS_HELPER_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-ns_helper_attributes)

[RegisterContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registercontext)