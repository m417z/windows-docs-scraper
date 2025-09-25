# IAutomaticUpdatesSettings2::put_IncludeRecommendedUpdates

## Description

[**Set** is no longer supported. Also, starting with
Windows 10 calls to **Get** always return **VARIANT_TRUE** (include recommended updates). ]

Gets and sets a Boolean value that indicates whether to include optional or recommended updates when a search for updates and installation of updates is performed.

This property is read/write.

## Parameters

## Remarks

Only administrators can set this property.

The caller can modify the settings in the [IAutomaticUpdatesSettings2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdatessettings2) interface only if the [ReadOnly](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-get_readonly) property is **VARIANT_TRUE**.
The **ReadOnly** property may change after the [Refresh](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-refresh) method is called.

## See also

[IAutomaticUpdatesSettings2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdatessettings2)