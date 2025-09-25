# IUpdateSearcher::get_ServerSelection

## Description

Gets and sets a [ServerSelection](https://learn.microsoft.com/openspecs/windows_protocols/ms-uamg/07e2bfa4-6795-4189-b007-cc50b476181a) value that indicates the server to search for updates.

This property is read/write.

## Parameters

## Remarks

 The site that is not a Windows Update site that is specified by the value of the [ServiceID](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesearcher-get_serviceid) property is searched only if the value of the **ServerSelection** property is ssOthers.

## See also

[IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher)