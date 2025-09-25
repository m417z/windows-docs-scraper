# ID3D12Device::SetStablePowerState

## Description

A development-time aid for certain types of profiling and experimental prototyping.

## Parameters

### `Enable`

Type: **BOOL**

Specifies a BOOL that turns the stable power state on or off.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

This method is only useful during the development of applications. It enables developers to profile GPU usage of multiple algorithms without experiencing artifacts from [dynamic frequency scaling](https://en.wikipedia.org/wiki/Dynamic_frequency_scaling).

Do not call this method in normal execution for a shipped application. This method only works while the machine is in [developer mode](https://learn.microsoft.com/windows/uwp/get-started/enable-your-device-for-development). If developer mode is not enabled, then device removal will occur. Instead, call this method in response to an off-by-default, developer-facing switch. Calling it in response to command line parameters, config files, registry keys, and developer console commands are reasonable usage scenarios.

A stable power state typically fixes GPU clock rates at a slower setting that is significantly lower than that experienced by users under normal application load. This reduction in clock rate affects the entire system. Slow clock rates are required to ensure processors don’t exhaust power, current, and thermal limits. Normal usage scenarios commonly leverage a processors ability to dynamically over-clock. Any conclusions made by comparing two designs under a stable power state should be double-checked with supporting results from real usage scenarios.

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)