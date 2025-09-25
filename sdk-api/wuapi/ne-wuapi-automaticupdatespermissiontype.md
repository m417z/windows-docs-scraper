# AutomaticUpdatesPermissionType enumeration

## Description

Defines the possible ways to set the [NotificationLevel](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-get_notificationlevel) property of the [IAutomaticUpdatesSettings](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdatessettings) interface or the [IncludeRecommendedUpdates](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings2-get_includerecommendedupdates) property of the [IAutomaticUpdatesSettings2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdatessettings2) interface.

## Constants

### `auptSetNotificationLevel:1`

The ability to set the [IAutomaticUpdatesSettings::NotificationLevel](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-get_notificationlevel) property.

### `auptDisableAutomaticUpdates:2`

The ability to set the [IAutomaticUpdatesSettings::NotificationLevel](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-get_notificationlevel) property to [aunlDisabled](https://learn.microsoft.com/windows/desktop/api/wuapi/ne-wuapi-automaticupdatesnotificationlevel).

### `auptSetIncludeRecommendedUpdates:3`

The ability to set the [IAutomaticUpdatesSettings2::IncludedRecommendedUpdates](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings2-get_includerecommendedupdates) property.

### `auptSetFeaturedUpdatesEnabled:4`

The ability to set the [IAutomaticUpdatesSettings3::FeaturedUpdatesEnabled](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings3-get_featuredupdatesenabled) property.

### `auptSetNonAdministratorsElevated:5`

The ability to set the [IAutomaticUpdatesSettings3::NonAdministratorsElevated](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings3-get_nonadministratorselevated) property.

## Remarks

Featured update notifications are only supported on Windows Vista and above. On Windows XP systems running versions of the Windows Update Agent (WUA) that support [IAutomaticUpdatesSettings3](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdatessettings3), the [IAutomaticUpdatesSettings3::FeaturedUpdatesEnabled](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings3-get_featuredupdatesenabled) value will always be VARIANT_FALSE, and attempting to alter its value will result in an error.

Featured update notifications are only supported when Automatic Updates is turned on. If Automatic Updates is set to “Never check for updates (not recommended),” then the [IAutomaticUpdatesSettings3::FeaturedUpdatesEnabled](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings3-get_featuredupdatesenabled) value will always be VARIANT_FALSE, and attempting to alter its value will result in an error.

Featured update notifications are only supported on certain update services. Currently, the only supported update service is Microsoft Update. If Automatic Updates is currently configured to receive updates from another service (from Windows Update, or from a WSUS server), then the [IAutomaticUpdatesSettings3::FeaturedUpdatesEnabled](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings3-get_featuredupdatesenabled) value will always be VARIANT_FALSE, and attempting to alter its value will result in an error.