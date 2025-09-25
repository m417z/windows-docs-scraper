# NetAlertRaise function

## Description

[This function is not supported as of Windows Vista because the alerter service is not supported.]

The
**NetAlertRaise** function notifies all registered clients when a particular event occurs.

To simplify sending an alert message, you can call the extended function
[NetAlertRaiseEx](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraiseex) instead.
**NetAlertRaiseEx** does not require that you specify a
[STD_ALERT](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-std_alert) structure.

## Parameters

### `AlertType` [in]

A pointer to a constant string that specifies the alert class (type of alert) to raise. This parameter can be one of the following predefined values, or a user-defined alert class for network applications. The event name for an alert can be any text string.

| Name | Meaning |
| --- | --- |
| **ALERT_ADMIN_EVENT** | An administrator's intervention is required. |
| **ALERT_ERRORLOG_EVENT** | An entry was added to the error log. |
| **ALERT_MESSAGE_EVENT** | A user or application received a broadcast message. |
| **ALERT_PRINT_EVENT** | A print job completed or a print error occurred. |
| **ALERT_USER_EVENT** | An application or resource was used. |

### `Buffer` [in]

A pointer to the data to send to the clients listening for the interrupting message. The data should begin with a fixed-length
[STD_ALERT](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-std_alert) structure followed by additional message data in one
[ADMIN_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-admin_other_info),
[ERRLOG_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-errlog_other_info),
[PRINT_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-print_other_info), or
[USER_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-user_other_info) structure. Finally, the buffer should include any required variable-length information. For more information, see the code sample in the following Remarks section.

The calling application must allocate and free the memory for all structures and variable data. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `BufferSize` [in]

The size, in bytes, of the message buffer.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value is a system error code and a can be one of the following error codes. For a list of all possible error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if the *AlertEventName* parameter is **NULL** or an empty string, the *Buffer* parameter is **NULL**, or the *BufferSize* parameter is less than the size of the [STD_ALERT](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-std_alert) structure plus the fixed size for the additional message data structure. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned on Windows Vista and later since the Alerter service is not supported. |

## Remarks

No special group membership is required to successfully execute the
**NetAlertRaise** function.

The alerter service must be running on the client computer when you call the
**NetAlertRaise** function, or the function fails with ERROR_FILE_NOT_FOUND.

#### Examples

The following code sample demonstrates how to raise an administrative alert by calling the
**NetAlertRaise** function and specifying
[STD_ALERT](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-std_alert) and
[ADMIN_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-admin_other_info) structures. First, the sample calculates the size of the message buffer. Then it allocates the buffer with a call to the
[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) function. The code assigns values to the members of the
**STD_ALERT** and the
**ADMIN_OTHER_INFO** portions of the buffer. The sample retrieves a pointer to the
**ADMIN_OTHER_INFO** structure by calling the
[ALERT_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-alert_other_info) macro. It also retrieves a pointer to the variable data portion of the buffer by calling the
[ALERT_VAR_DATA](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-alert_var_data) macro. Finally, the code sample frees the memory allocated for the buffer with a call to the
[GlobalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfree) function.

```cpp
#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")

#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <lm.h>

const int ALERT_VAR_DATA_SIZE = 216;

int wmain(int argc, wchar_t *argv[])
{
   int nBufferSize;
   LPVOID pAlertOtherInfo;
   PSTD_ALERT pStdAlert;              // STD_ALERT structure
   PADMIN_OTHER_INFO pAdminOtherInfo; // ADMIN_OTHER_INFO structure
   LPVOID pVarData;
   time_t now;
   DWORD dwResult;
   //
   // Check command line arguments.
   //
   if (argc != 2)
   {
      fwprintf(stderr, L"Usage: %s LogFileName\n", argv[0]);
      exit(1);
   }
   // Calculate the buffer size;
   //  then allocate the memory for the buffer.
   //
   nBufferSize  = sizeof(STD_ALERT) + ALERT_VAR_DATA_SIZE;
   pAlertOtherInfo = (LPVOID) GlobalAlloc(GPTR, nBufferSize);

   if (pAlertOtherInfo == NULL)
   {
       fwprintf(stderr, L"Unable to allocate memory\n");
       exit(1);
   }

   //
   // Assign values to the STD_ALERT portion of the buffer.
   //   (This is required when you call NetAlertRaise.)
   //
   pStdAlert = (PSTD_ALERT)pAlertOtherInfo;
   time( &now );
   pStdAlert->alrt_timestamp = (DWORD)now;
   wcscpy_s(pStdAlert->alrt_eventname, EVLEN + 1, ALERT_ADMIN_EVENT);
   wcscpy_s(pStdAlert->alrt_servicename, SNLEN + 1, argv[0]);
   //
   // Retrieve the pointer to the ADMIN_OTHER_INFO structure
   //  that follows the STD_ALERT portion of the buffer.
   //   Do this by calling the ALERT_OTHER_INFO macro.
   //
   pAdminOtherInfo = (PADMIN_OTHER_INFO)ALERT_OTHER_INFO(pAlertOtherInfo);
   //
   // Assign values to the ADMIN_OTHER_INFO structure.
   //
   pAdminOtherInfo->alrtad_numstrings = 1;
   //
   // Error 2377, NERR_LogOverflow, indicates
   //  a log file is full.
   //
   pAdminOtherInfo->alrtad_errcode = 2377;
   //
   // Retrieve the pointer to the variable data portion
   //  of the buffer by calling the ALERT_VAR_DATA macro.
   //
   pVarData = (LPTSTR)ALERT_VAR_DATA(pAdminOtherInfo);
   //
   // Supply the log file name for error 2377.
   //
   wcsncpy_s((wchar_t*) pVarData, ALERT_VAR_DATA_SIZE/2,
           argv[1],
           ALERT_VAR_DATA_SIZE/2 );
   //
   // Send an administrative alert by calling the
   //  NetAlertRaise function.
   //
   dwResult = NetAlertRaise(ALERT_ADMIN_EVENT,
                            pAlertOtherInfo,
                            nBufferSize);
   //
   // Display the results of the function call.
   //
   if (dwResult != NERR_Success)
      wprintf(L"NetAlertRaise failed: %d\n", dwResult);
   else
      wprintf(L"Administrative alert raised successfully.\n");
   //
   // Free the allocated memory.
   //
   GlobalFree(pAlertOtherInfo);

   return (dwResult);
}

```

## See also

[ADMIN_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-admin_other_info)

[ALERT_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-alert_other_info)

[ALERT_VAR_DATA](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-alert_var_data)

[Alert Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/alert-functions)

[ERRLOG_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-errlog_other_info)

[NetAlertRaiseEx](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraiseex)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[PRINT_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-print_other_info)

[STD_ALERT](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-std_alert)

[USER_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-user_other_info)