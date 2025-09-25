# GetDeveloperDriveEnablementState function

## Description

Gets a value indicating whether the developer drive is enabled.

## Return value

Returns a [DEVELOPER_DRIVE_ENABLEMENT_STATE](https://learn.microsoft.com/windows/win32/api/sysinfoapi/ne-sysinfoapi-developer_drive_enablement_state) value indicating the developer drive enablement state.

## Remarks

**GetDeveloperDriveEnablementState** returns information indicating whether the developer drive feature is enabled. If the developer drive feature is disabled, the **DEVELOPER_DRIVE_ENABLEMENT_STATE** returned indicates whether developer drive is disabled via group policy or via local policy.

If **GetDeveloperDriveEnablementState** fails, it returns **DeveloperDriveEnablementStateError** and sets the last error.

#### Examples

The following example shows how to use **GetDeveloperDriveEnablementState** to determine whether the developer drive is enabled.

```cpp
#include <Windows.h>

void PrintDevDriveEnabledStatus()
{
    DEVELOPER_DRIVE_ENABLEMENT_STATE state = GetDeveloperDriveEnablementState();

    switch (state) {
    case DeveloperDriveEnabled:
        printf("Developer drive is enabled.\n");
        break;
    case DeveloperDriveDisabledByGroupPolicy:
        printf("Developer drive is disabled by Group Policy.\n");
        break;
    case DeveloperDriveEnablementStateError:
        printf("Error querying developer drive info: %d\n", GetLastError());
        break;
    case DeveloperDriveDisabledBySystemPolicy:
    default:
        printf("Developer drive is disabled.");
        break;
    }
}
```

## See also

[DEVELOPER_DRIVE_ENABLEMENT_STATE](https://learn.microsoft.com/windows/win32/api/sysinfoapi/ne-sysinfoapi-developer_drive_enablement_state)