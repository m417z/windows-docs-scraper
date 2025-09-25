# IUpdateSearcher::put_ServerSelection

## Description

Gets and sets a [ServerSelection](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/wuapicommon/ne-wuapicommon-serverselection.md) value that indicates the server to search for updates.

This property is read/write.

## Parameters

## Remarks

 The site that is not a Windows Update site that is specified by the value of the [ServiceID](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesearcher-get_serviceid) property is searched only if the value of the **ServerSelection** property is ssOthers.

## See also

[IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher)