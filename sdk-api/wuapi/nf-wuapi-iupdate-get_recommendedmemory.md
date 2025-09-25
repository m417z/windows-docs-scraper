# IUpdate::get_RecommendedMemory

## Description

Gets the recommended physical memory size that should be available in your computer before you install the update. The physical memory size is specified in megabytes (MB).

This property is read-only.

## Parameters

## Remarks

The following properties of the [IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate) interface return 0 (zero) when the information is not available:

* [RecommendedCpuSpeed](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate-get_recommendedcpuspeed)
* [RecommendedHardDiskSpace](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate-get_recommendedharddiskspace)
* **RecommendedMemory**

## See also

[IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate)