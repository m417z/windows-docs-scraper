# EtwRegister function

## Description

The **EtwRegister** function registers the event provider and must be called before a provider can start tracing. The **EtwRegister** function is the kernel mode counterpart to the user-mode **EventRegister** function. The function can also provide a pointer to an optional callback function that can be used to provide additional event filtering capabilities.

## Parameters

### `ProviderId` [in]

A pointer to the event provider GUID.

### `EnableCallback` [in, optional]

A pointer to an optional callback function. The callback function provides additional event filtering capabilities. The callback function is user-defined.

### `CallbackContext` [in, optional]

The function passes back the optional callback context when a callback is made. You can specify the optional context when you register a provider. The *CallbackContext* parameter supports the scenarios in which one callback is shared by multiple providers, as in a C++ class. The *CallbackContext* provides a way to distinguish the target provider instances for the enable callback.

### `RegHandle` [out]

A pointer to a variable that receives the provider registration handle if the function call is successful.

## Return value

The **EtwRegister** function returns a status code from the following list:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Indicates that event provider was successfully registered with ETW. |
| **STATUS_INVALID_PARAMETER** | Indicates that the parameter was not valid. |
| **STATUS_Xxx** | Indicates that the request failed for the reason specified by the NTSTATUS value. See Ntstatus.h for detailed information about the actual status return code. |

## Remarks

Before a kernel-mode driver can trace events, the driver must register as an event provider using the **EtwRegister** function. When a kernel mode driver calls **EtwRegister**, the function returns a registration handle. This registration handle can be used to test whether a keyword or level is enabled for a specific provider and to call event tracing and logging functions. After tracing is complete, a driver must call the **EtwUnregister** function to unregister the provider. For every call to **EtwRegister** there must be a corresponding call to **EtwUnregister**. Failure to unregister the event provider can cause errors when the process is unloaded because the callback functions associated with the process are no longer valid. No tracing calls should be made that fall outside of the code bounded by the **EtwRegister** and **EtwUnregister** functions. For the best performance, you can call the **EtwRegister** function in your **DriverEntry** routine and the **EtwUnregister** function in your **DriverUnload** routine.

Callers of **EtwRegister** must be running at IRQL = PASSIVE_LEVEL in the context of a system thread.

## See also

[EtwUnregister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwunregister)