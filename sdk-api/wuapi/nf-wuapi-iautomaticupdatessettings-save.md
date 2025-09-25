# IAutomaticUpdatesSettings::Save

## Description

[**AutomaticUpdatesSettings::Save** is no longer supported. Starting with
Windows 10 calls to **Save** always return
**S_OK**, but do nothing.]

Applies the current Automatic Updates settings.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

## Remarks

Saving settings with a [NotificationLevel](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-get_notificationlevel) value other than Disabled starts the Automatic Updates service.

**Note** On Windows RT, you can no longer use the **Save** method to configure Windows Update settings programmatically. The configuration operation fails if you use **Save** to set any value other than 4 ([aunlScheduledInstallation](https://learn.microsoft.com/windows/desktop/api/wuapi/ne-wuapi-automaticupdatesnotificationlevel)).

## See also

[IAutomaticUpdatesSettings](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdatessettings)