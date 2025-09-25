# FaxExtUnregisterForEvents function

## Description

The **FaxExtUnregisterForEvents** callback function unregisters the fax extension DLL for notifications about configuration data changes related to a specific device and GUID.

## Parameters

### `hNotification`

Type: **HANDLE**

Specifies a **HANDLE** that indicates the registration handle from which the caller wishes to unregister.

The handle must be the return value from a previous call to the [FaxExtRegisterForEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextregisterforevents) function.

## Return value

Type: **DWORD**

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is a nonzero error code defined in WinError.h. You can call the Win32 **FormatMessage** function specifying the FORMAT_MESSAGE_FROM_SYSTEM flag to retrieve a generic description of the error.

The **FaxExtUnregisterForEvents** function can return the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The unregistration process succeeded. |
| **ERROR_NOT_FOUND** | The registration handle specified by the hNotification parameter was not found. |
| **ERROR_INVALID_PARAMETER** | The *hNotification* parameter is invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory is available to complete the operation. |
| **ERROR_GEN_FAILURE** | An internal failure at the fax server prevents access to the data. |
| **ERROR_SHUTDOWN_IN_PROGRESS** | The server is shutting down. |
| **ERROR_BUSY** | The server cannot process a request for notifications while it is sending a notification about a data change. You should try calling the function at a later time. |

## Remarks

When the fax extension calls this fax service callback function, it must use the function pointer exposed by the fax service when the service calls the [FaxExtInitializeConfig](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextinitializeconfig) function.

The fax extension can call the **FaxExtUnregisterForEvents** function to stop receiving notifications about device configuration data changes. An extension registers for notifications by calling the fax service's callback function [FaxExtRegisterForEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextregisterforevents).

The fax service passes a pointer to the **FaxExtUnregisterForEvents** callback function when the fax service calls the [FaxExtInitializeConfig](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextinitializeconfig) function. The PFAX_EXT_UNREGISTER_FOR_EVENTS data type is a pointer to a **FaxExtUnregisterForEvents** function.

## See also

[FaxExtInitializeConfig](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextinitializeconfig)

[FaxExtRegisterForEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextregisterforevents)