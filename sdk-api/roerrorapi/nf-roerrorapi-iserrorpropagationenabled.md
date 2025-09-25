# IsErrorPropagationEnabled function

## Description

**Note** This function is deprecated. Going forward, all Windows 8.1 and Windows 10 apps can operate automatically as if error propagation is enabled, and do not need to check dynamically whether error propagation is enabled.

Indicates whether the [CoreApplication.UnhandledErrorDetected](https://msdn.microsoft.com/863a06ac-b8ec-440a-8445-1dbbf1b04263) event occurs for the errors that are returned by the delegate registered as a callback function for a Windows Runtime API event or the completion of an asynchronous method.

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | Indicates that the [CoreApplication.UnhandledErrorDetected](https://msdn.microsoft.com/863a06ac-b8ec-440a-8445-1dbbf1b04263) event occurs for the errors that are returned by the delegate registered as a callback function for a Windows Runtime API event or the completion of an asynchronous method. |
| **FALSE** | Indicates that the [CoreApplication.UnhandledErrorDetected](https://msdn.microsoft.com/863a06ac-b8ec-440a-8445-1dbbf1b04263) event does not occur for the errors that are returned by the delegate registered as a callback function for a Windows Runtime API event or the completion of an asynchronous method. |

## Remarks

For Windows 8 apps, this value is **FALSE**, and errors returned by a delegate registered as a callback function for the asynchronous completion of a Windows Runtime API or for a Windows Runtime API event are ignored. For Windows 8.1 and Windows 10 apps, this value is **TRUE**, and errors from callback functions that return control to operating system code are propagated to the global error handler.

Use this function only when your code needs to interoperate with both Windows 8 and newer applications by using the same binary.

## See also

[CoreApplication.UnhandledErrorDetected](https://msdn.microsoft.com/863a06ac-b8ec-440a-8445-1dbbf1b04263)