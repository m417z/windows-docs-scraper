# IUpdate::get_RecommendedHardDiskSpace

## Description

Gets the recommended free space that should be available on the hard disk before you install the update. The free space is specified in megabytes (MB).

This property is read-only.

## Parameters

## Remarks

The following properties of the [IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate) interface return 0 (zero) when the information is not available:

* [RecommendedCpuSpeed](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate-get_recommendedcpuspeed)
* **RecommendedHardDiskSpace**
* [RecommendedMemory](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate-get_recommendedmemory)

## See also

[IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate)