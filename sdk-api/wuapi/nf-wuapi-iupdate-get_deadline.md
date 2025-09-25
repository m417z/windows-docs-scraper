# IUpdate::get_Deadline

## Description

Gets the date by which the update must be installed.

This property is read-only.

## Parameters

## Remarks

In COM, if the update has a deadline, the return value is of type VT_DATE and contains a DATE value that specifies the deadline. Otherwise, the return value is of type VT_EMPTY.

In the Microsoft .NET Framework, the return value is **NULL** if the update has no deadline.

## See also

[IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate)