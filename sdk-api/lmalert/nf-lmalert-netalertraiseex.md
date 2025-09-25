# NetAlertRaiseEx function

## Description

[This function is not supported as of Windows Vista because the alerter service is not supported.]

The
**NetAlertRaiseEx** function notifies all registered clients when a particular event occurs. You can call this extended function to simplify the sending of an alert message because
**NetAlertRaiseEx** does not require that you specify a
[STD_ALERT](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-std_alert) structure.

## Parameters

### `AlertType` [in]

A pointer to a constant string that specifies the alert class (type of alert) to raise. This parameter can be one of the following predefined values, or a user-defined alert class for network applications. (The event name for an alert can be any text string.)

| Name | Meaning |
| --- | --- |
| **ALERT_ADMIN_EVENT** | An administrator's intervention is required. |
| **ALERT_ERRORLOG_EVENT** | An entry was added to the error log. |
| **ALERT_MESSAGE_EVENT** | A user or application received a broadcast message. |
| **ALERT_PRINT_EVENT** | A print job completed or a print error occurred. |
| **ALERT_USER_EVENT** | An application or resource was used. |

### `VariableInfo` [in]

A pointer to the data to send to the clients listening for the interrupting message. The data should consist of one
[ADMIN_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-admin_other_info),
[ERRLOG_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-errlog_other_info),
[PRINT_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-print_other_info), or
[USER_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-user_other_info) structure followed by any required variable-length information. For more information, see the code sample in the following Remarks section.

The calling application must allocate and free the memory for all structures and variable data. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `VariableInfoSize` [in]

The number of bytes of variable information in the buffer pointed to by the *VariableInfo* parameter.

### `ServiceName` [in]

A pointer to a constant string that specifies the name of the service raising the interrupting message.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value is a system error code and a can be one of the following error codes. For a list of all possible error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if the *AlertEventName* parameter is **NULL** or an empty string, the *ServiceName* parameter is **NULL** or an empty string, the *VariableInfo* parameter is **NULL**, or the *VariableInfoSize* parameter is greater than 512 minus the size of the [STD_ALERT](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-std_alert) structure. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned on Windows Vista and later since the Alerter service is not supported. |

## Remarks

No special group membership is required to successfully execute the
**NetAlertRaiseEx** function.

The alerter service must be running on the client computer when you call the
**NetAlertRaiseEx** function, or the function fails with ERROR_FILE_NOT_FOUND.

#### Examples

The following code sample demonstrates how to raise the following types of interrupting messages (alerts) by calling the **NetAlertRaiseEx** function:

* An administrative alert by specifying an [ADMIN_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-admin_other_info) structure
* A print alert by specifying a [PRINT_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-print_other_info) structure
* A user alert by specifying a [USER_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-user_other_info) structure

In each instance the code assigns values to the members of the relevant alert information structure. Following this, the sample retrieves a pointer to the portion of the message buffer that follows the structure by calling the [ALERT_VAR_DATA](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-alert_var_data) macro. The code also fills in the variable-length strings in this portion of the buffer. Finally, the sample calls **NetAlertRaiseEx** to send the alert.

Note that the calling application must allocate and free the memory for all structures and variable-length data in an alert message buffer.

To pass a user-defined structure and valid strings in a user alert, you must create an event message file and link it with your application. You must also register the application in the **EventMessageFile** subkey in the **EventLog** section of the registry. If you do not register the application, the user alert will contain the information you pass in the variable-length strings that follow the [USER_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-user_other_info) structure. For more information about **EventMessageFile**, see [Event Logging](https://learn.microsoft.com/windows/desktop/EventLog/event-logging).

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#pragma comment(lib, "netapi32.lib")

#include <windows.h>
#include <lm.h>
#include <stdio.h>
#include <time.h>
//
// Define default strings.
//
#define PROGRAM_NAME    TEXT("NETALRT")
#define szComputerName  TEXT("\\\\TESTCOMPUTER")
#define szUserName      TEXT("TEST")
#define szQueueName     TEXT("PQUEUE")
#define szDestName      TEXT("MYPRINTER")
#define szStatus        TEXT("OK")
//
// Define structure sizes.
//
#define VAREDSIZE 312  // maximum size of the variable length message
char buff[VAREDSIZE];
//
int main()
{
   time_t             now;
   PADMIN_OTHER_INFO  pAdminInfo; // ADMIN_OTHER_INFO structure
   PPRINT_OTHER_INFO  pPrintInfo; // PRINT_OTHER_INFO structure
   PUSER_OTHER_INFO   pUserInfo;  // USER_OTHER_INFO structure
   TCHAR              *p;
   DWORD dwResult;

   time( &now );  // Retrieve the current time to print it later.

   //
   // Sending an administrative alert
   //
   // Assign values to the members of the ADMIN_OTHER_INFO structure.
   //
   pAdminInfo = (PADMIN_OTHER_INFO) buff;
   ZeroMemory(pAdminInfo, VAREDSIZE);
   //
   // Error 2377, NERR_LogOverflow, indicates
   //  a log file is full.
   //
   pAdminInfo->alrtad_errcode = 2377;
   pAdminInfo->alrtad_numstrings = 1;
   //
   // Retrieve a pointer to the variable data portion at the
   //  end of the buffer by calling the ALERT_VAR_DATA macro.
   //
   p = (LPTSTR) ALERT_VAR_DATA(pAdminInfo);
   //
   // Fill in the variable-length, concatenated strings
   //  that follow the ADMIN_OTHER_INFO structure. These strings
   //  will be written to the message log.
   //
   wcscpy_s(p,VAREDSIZE/2, TEXT("'C:\\MYLOG.TXT'"));
   //
   // Call the NetAlertRaiseEx function to raise the
   //  administrative alert.
   //
   dwResult = NetAlertRaiseEx(ALERT_ADMIN_EVENT, pAdminInfo, 255 , TEXT("MYSERVICE"));
   //
   // Display the results of the function call.
   //
   if (dwResult != NERR_Success)
   {
      wprintf(L"NetAlertRaiseEx failed: %d\n", dwResult);
      return -1;
   }
   else
      wprintf(L"Administrative alert raised successfully.\n");

   //
   // Sending a print alert
   //
   // Assign values to the members of the PRINT_OTHER_INFO structure.
   //
   pPrintInfo = (PPRINT_OTHER_INFO) buff;
   ZeroMemory(pPrintInfo, VAREDSIZE);
   pPrintInfo->alrtpr_jobid = 5457;
   pPrintInfo->alrtpr_status = 0;
   pPrintInfo->alrtpr_submitted = (DWORD) now;
   pPrintInfo->alrtpr_size = 1000;
   //
   // Retrieve a pointer to the variable data portion at the
   //  end of the buffer by calling the ALERT_VAR_DATA macro.
   //
   p = (LPTSTR) ALERT_VAR_DATA(pPrintInfo);
   //
   // Fill in the variable-length, concatenated strings
   //  that follow the PRINT_OTHER_INFO structure.
   //
   wcscpy_s(p, VAREDSIZE/2, szComputerName); // computername
   p += lstrlen(p) + 1;
   wcscpy_s(p, (VAREDSIZE/2)-wcslen(szComputerName)-1, szUserName);     // user name
   p += lstrlen(p) + 1;
   wcscpy_s(p, (VAREDSIZE/2)-wcslen(szComputerName)-wcslen(szUserName)-2,
       szQueueName);    // printer queuename
   p += lstrlen(p) + 1;
   wcscpy_s(p, (VAREDSIZE/2)-wcslen(szComputerName)-wcslen(szUserName)-wcslen(szQueueName)-3,
       szDestName);     // destination or printer name (optional)
   p += lstrlen(p) + 1;
   wcscpy_s(p, (VAREDSIZE/2)-wcslen(szComputerName)-wcslen(szUserName)-wcslen(szQueueName)
       - wcslen(szDestName)-4, szStatus);       // status of the print job (optional)
   //
   // Call the NetAlertRaiseEx function to raise the
   //  print alert.
   //
   dwResult = NetAlertRaiseEx(ALERT_PRINT_EVENT, pPrintInfo, VAREDSIZE, TEXT("MYSERVICE"));
   //
   // Display the results of the function call.
   //
   if (dwResult != NERR_Success)
   {
      wprintf(L"NetAlertRaiseEx failed: %d\n", dwResult);
      return -1;
   }
   else
      wprintf(L"Print alert raised successfully.\n");

   //
   // Sending a user alert
   //
   // Assign values to the members of the USER_OTHER_INFO structure.
   //
   pUserInfo  = (PUSER_OTHER_INFO)  buff;
   ZeroMemory(pUserInfo, VAREDSIZE);
   pUserInfo->alrtus_errcode = 0xffff;
   pUserInfo->alrtus_numstrings = 1;
   //
   // Retrieve a pointer to the variable data portion at the
   //  end of the buffer by calling the ALERT_VAR_DATA macro.
   //
   p = (LPTSTR) ALERT_VAR_DATA(pUserInfo);
   //
   // Fill in the variable-length, concatenated strings
   //  that follow the USER_OTHER_INFO structure.
   //
   wcscpy_s(p,(VAREDSIZE/2), TEXT("C:\\USERLOG.TXT"));
   p += lstrlen(p) + 1;
   wcscpy_s(p, (VAREDSIZE/2) - wcslen(TEXT("C:\\USERLOG.TXT"))-1, szUserName);
   //
   // Call the NetAlertRaiseEx function to raise the
   //  user alert.
   //
   dwResult = NetAlertRaiseEx(ALERT_USER_EVENT, pUserInfo, VAREDSIZE, TEXT("MYSERVICE"));
   //
   // Display the results of the function call.
   //
   if (dwResult != NERR_Success)
   {
      wprintf(L"NetAlertRaiseEx failed: %d\n", dwResult);
      return -1;
   }
   else
      wprintf(L"User alert raised successfully.\n");

   return(dwResult);
}

```

## See also

[ADMIN_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-admin_other_info)

[ALERT_VAR_DATA](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-alert_var_data)

[Alert Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/alert-functions)

[ERRLOG_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-errlog_other_info)

[NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[PRINT_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-print_other_info)

[USER_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-user_other_info)