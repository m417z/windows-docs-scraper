# IAutomaticUpdatesSettings::Refresh

## Description

Retrieves the latest Automatic Updates settings.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

## Remarks

Calling **Refresh** resets any setting changes that have not been saved by using the [Save](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-save) method.

**Note** On Windows RT, you can no longer use the [IAutomaticUpdatesSettings::Save](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-save) method to configure Windows Update settings programmatically. The configuration operation fails if you use **Save** to set any value other than 4 ([aunlScheduledInstallation](https://learn.microsoft.com/windows/desktop/api/wuapi/ne-wuapi-automaticupdatesnotificationlevel)).

## See also

[IAutomaticUpdatesSettings](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdatessettings)