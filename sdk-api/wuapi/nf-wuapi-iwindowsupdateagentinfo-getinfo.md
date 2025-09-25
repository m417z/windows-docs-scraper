# IWindowsUpdateAgentInfo::GetInfo

## Description

Retrieves version information about Windows Update Agent (WUA).

## Parameters

### `varInfoIdentifier` [in]

 A literal string value that specifies the type of information that the *retval* parameter returns. The following table lists the current possible string values.

|  |  |
| --- | --- |
| **ApiMajorVersion** | Retrieves the current major version of WUA. |
| **ApiMinorVersion** | Retrieves the current minor version of WUA. |
| **ProductVersionString** | Retrieves the file version of the Wuapi.dll file in string format. |

### `retval` [out]

* Returns the major version of the WUA API as a **LONG** value within the **VARIANT** variable if the value of the *varInfoIdentifier* parameter is **ApiMajorVersion**.
* Returns the minor version of the WUA API as a **LONG** value within the **VARIANT** variable if the value of *varInfoIdentifier* is **ApiMinorVersion**.
* Returns the file version of the Wuapi.dll file as a **BSTR** value within the **VARIANT** variable if the value of *varInfoIdentifier* is **ProductVersionString**.

**Note** The format of a returned string is as follows: "*<Windows-major-version>*.*<Windows-minor-version>*.*<build>*.*<update>*".

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows

error code.

## Remarks

The [IWindowsUpdateAgentInfo](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iwindowsupdateagentinfo) interface may require you to update WUA. For more information, see [Updating Windows Update Agent](https://learn.microsoft.com/windows/desktop/Wua_Sdk/updating-the-windows-update-agent).

The major version is incremented one time for each release if a change occurs in the interfaces of the WUA API. The minor version is incremented one time for each release if a change occurs in the existing interfaces of the WUA API.

## See also

[IWindowsUpdateAgentInfo](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iwindowsupdateagentinfo)