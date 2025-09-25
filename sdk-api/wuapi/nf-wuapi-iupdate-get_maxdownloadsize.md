# IUpdate::get_MaxDownloadSize

## Description

Gets the maximum download size of the update.

This property is read-only.

## Parameters

## Remarks

The [MinDownloadSize](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate-get_mindownloadsize) property of an update is always downloaded. However, the **MaxDownloadSize** property is not always downloaded. The **MaxDownloadSize** property is downloaded based on the configuration of the computer that receives the update.

## See also

[IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate)