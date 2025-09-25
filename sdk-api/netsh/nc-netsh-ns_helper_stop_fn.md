# NS_HELPER_STOP_FN callback function

## Description

The
**NS_HELPER_STOP_FN** command is the stop function for helpers. This function enables helper contexts to release any resources before being unloaded, and is registered in the
[RegisterContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registercontext) function. The following is an example of a stop function. Be aware that **SampleStopHelper** is a placeholder for the application-defined function name.

## Parameters

### `dwReserved` [in]

Reserved.

## Return value

Returns NO_ERROR upon success. Any other return value indicates an error.

## Remarks

The stop function for helpers provides an opportunity for a helper context to release resources before being unloaded. This function is called once for each context for which the function is registered.

## See also

[NS_HELPER_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-ns_helper_attributes)

[NS_HELPER_START_FN](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_helper_start_fn)

[RegisterContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registercontext)