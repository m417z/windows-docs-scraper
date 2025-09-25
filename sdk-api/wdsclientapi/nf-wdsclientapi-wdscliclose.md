# WdsCliClose function

## Description

Closes a handle to a WDS session or image, and releases resources.

## Parameters

### `Handle` [in]

 A handle to a WDS session or image. This function can close handles opened with the
[WdsCliCreateSession](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclicreatesession) or
[WdsCliFindFirstImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindfirstimage) functions.

## Return value

If the function succeeds, the return is **S_OK**.

## See also

[WdsCliCreateSession](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclicreatesession)

[WdsCliFindFirstImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindfirstimage)

[Windows Deployment Services Client Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-client-functions)