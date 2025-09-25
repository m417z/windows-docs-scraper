# SetTimeZoneInformation function

## Description

Sets the current time zone settings. These settings control translations from Coordinated Universal Time (UTC) to local time.

To support boundaries for daylight saving time that change from year to year, use the [SetDynamicTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-setdynamictimezoneinformation) function.

## Parameters

### `lpTimeZoneInformation` [in]

A pointer to a
[TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-time_zone_information) structure that contains the new settings.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

An application must have the SE_TIME_ZONE_NAME privilege for this function to succeed. This privilege is disabled by default. Use the
[AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges) function to enable the privilege before calling
**SetTimeZoneInformation**, and then to disable the privilege after the
**SetTimeZoneInformation** call. For more information, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

**Windows Server 2003 and Windows XP/2000:** The application must have the SE_SYSTEMTIME_NAME privilege.

> [!IMPORTANT]
> Starting with Windows Vista and Windows Server 2008 through all current versions of Windows, call **[SetDynamicTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-setdynamictimezoneinformation)** instead of **SetTimeZoneInformation** to set system time zone information. **SetDynamicTimeZoneInformation** supports the full history of changes to standard time and daylight saving time provided by the dynamic data in the Windows registry. If an application uses **SetTimeZoneInformation**, dynamic daylight saving time support is disabled for the system and the message "Your current time zone is not recognized. Please select a valid time zone." will appear to the user in the Windows time zone settings.

To inform Explorer that the time zone has changed, send the
[WM_SETTINGCHANGE](https://learn.microsoft.com/windows/desktop/winmsg/wm-settingchange) message.

All translations between UTC and local time are based on the following formula:

UTC = local time + bias

The bias is the difference, in minutes, between UTC and local time.

#### Examples

The following example displays the current time zone, then adjusts the time zone one zone west. The old and new time zone names are displayed. You can also verify the changes using Date and Time in Control Panel. The new name is displayed on the **Date&Time** tab as the **Current Time Zone**. The new time zone is displayed in the drop-down list on the **Time Zone** tab. To undo these changes, simply choose your old time zone from the drop-down list.

```cpp
#define UNICODE 1
#define _UNICODE 1

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <strsafe.h>

int main()
{
   TIME_ZONE_INFORMATION tziOld, tziNew, tziTest;
   DWORD dwRet;

   // Enable the required privilege

   HANDLE hToken;
   TOKEN_PRIVILEGES tkp;

   OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY, &hToken);
   LookupPrivilegeValue(NULL, SE_TIME_ZONE_NAME, &tkp.Privileges[0].Luid);
   tkp.PrivilegeCount = 1;
   tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
   AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);

   // Retrieve the current time zone information

   dwRet = GetTimeZoneInformation(&tziOld);

   if(dwRet == TIME_ZONE_ID_STANDARD || dwRet == TIME_ZONE_ID_UNKNOWN)
      wprintf(L"%s\n", tziOld.StandardName);
   else if( dwRet == TIME_ZONE_ID_DAYLIGHT )
      wprintf(L"%s\n", tziOld.DaylightName);
   else
   {
      printf("GTZI failed (%d)\n", GetLastError());
      return 0;
   }

   // Adjust the time zone information

   ZeroMemory(&tziNew, sizeof(tziNew));
   tziNew.Bias = tziOld.Bias + 60;
   StringCchCopy(tziNew.StandardName, 32, L"Test Standard Zone");
   tziNew.StandardDate.wMonth = 10;
   tziNew.StandardDate.wDayOfWeek = 0;
   tziNew.StandardDate.wDay = 5;
   tziNew.StandardDate.wHour = 2;

   StringCchCopy(tziNew.DaylightName, 32, L"Test Daylight Zone");
   tziNew.DaylightDate.wMonth = 4;
   tziNew.DaylightDate.wDayOfWeek = 0;
   tziNew.DaylightDate.wDay = 1;
   tziNew.DaylightDate.wHour = 2;
   tziNew.DaylightBias = -60;

   if( !SetTimeZoneInformation( &tziNew ) )
   {
      printf("STZI failed (%d)\n", GetLastError());
      return 0;
   }

   // Retrieve and display the newly set time zone information

   dwRet = GetTimeZoneInformation(&tziTest);

   if(dwRet == TIME_ZONE_ID_STANDARD || dwRet == TIME_ZONE_ID_UNKNOWN)
      wprintf(L"%s\n", tziTest.StandardName);
   else if( dwRet == TIME_ZONE_ID_DAYLIGHT )
      wprintf(L"%s\n", tziTest.DaylightName);
   else printf("GTZI failed (%d)\n", GetLastError());

   // Disable the privilege

   tkp.Privileges[0].Attributes = 0;
   AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES) NULL, 0);

   return 1;
}

```

## See also

[GetTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-gettimezoneinformation)

[SetDynamicTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-setdynamictimezoneinformation)

[TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-time_zone_information)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)