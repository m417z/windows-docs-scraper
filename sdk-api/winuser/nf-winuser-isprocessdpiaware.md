# IsProcessDPIAware function

## Description

[IsProcessDPIAware is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [GetProcessDPIAwareness](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-getprocessdpiawareness).]

Determines whether the current process is dots per inch (dpi) aware such that it adjusts the sizes of UI elements to compensate for the dpi setting.

## Return value

Type: **BOOL**

**TRUE** if the process is dpi aware; otherwise, **FALSE**.