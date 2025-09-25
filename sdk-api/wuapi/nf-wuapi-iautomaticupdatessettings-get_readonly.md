# IAutomaticUpdatesSettings::get_ReadOnly

## Description

[**IAutomaticUpdatesSettings::ReadOnly** is no longer supported. Starting with
Windows 10 calls to **ReadOnly** always return **VARIANT_FALSE**. However, **IAutomaticUpdatesSettings::Save** is a no-op, so no changes can be made.]

Gets a Boolean value that indicates whether the Automatic Update settings are read-only.

This property is read-only.

## Parameters

## Remarks

**ReadOnly** is **VARIANT_TRUE** if either of the following conditions is true:

* The caller has insufficient security permissions to modify the Automatic Updates settings.
* The current settings are enforced by Group Policy.

The caller can modify the settings in the [IAutomaticUpdatesSettings](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdatessettings) interface only if **ReadOnly** is **VARIANT_FALSE**.
The value of **ReadOnly** may change after calling [Refresh](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-refresh).

## See also

[IAutomaticUpdatesSettings](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdatessettings)

[IAutomaticUpdatesSettings.Refresh](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-refresh)