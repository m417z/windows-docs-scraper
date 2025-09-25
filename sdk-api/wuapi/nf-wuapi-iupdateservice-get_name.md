# IUpdateService::get_Name

## Description

Gets the name of the service.

This property is read-only.

## Parameters

## Remarks

The localized properties of an update are returned in the language that corresponds to the user default user interface (UI) language of the caller. If a property of an update is unavailable in such language, it will be returned in the system default UI language on the specified computer. If the property is unavailable in either languages mentioned, then it will be returned in the language recommended, if any, by the provider of the Update. Otherwise the Update Service will choose a language as it sees fit for the property.

## See also

[IUpdateService](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservice)