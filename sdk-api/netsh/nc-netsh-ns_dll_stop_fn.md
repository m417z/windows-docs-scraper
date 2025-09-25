# NS_DLL_STOP_FN callback function

## Description

The
**NS_DLL_STOP_FN** command is the DLL stop function for helper DLLs. The DLL stop function provides an opportunity for helper DLLs to release any resources before being unloaded, and is registered in the
[RegisterContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registercontext) function. The following is an example of a DLL stop function. Be aware that **SampleStop** is a placeholder for the application-defined function name.

## Parameters

### `dwReserved` [in]

Reserved.

## Return value

Returns NO_ERROR upon success. Any other return value indicates an error.

## Remarks

The DLL stop function is called once for each helper DLL being unloaded.

## See also

[NS_HELPER_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-ns_helper_attributes)

[NS_HELPER_START_FN](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_helper_start_fn)

[NS_HELPER_STOP_FN](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_helper_stop_fn)

[RegisterContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registercontext)