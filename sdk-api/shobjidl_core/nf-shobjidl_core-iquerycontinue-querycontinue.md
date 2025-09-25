# IQueryContinue::QueryContinue

## Description

Returns **S_OK** if the operation associated with the current instance of this interface should continue.

## Return value

Type: **HRESULT**

Returns **S_OK** if the calling application should continue, **S_FALSE** if not.

## Remarks

In typical usage, a pointer to an [IQueryContinue](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iquerycontinue) interface is passed to a method of another object. That object, in turn, runs this method periodically to determine whether to continue its actions. For example, if a user clicks a cancel button, this method will start returning **S_FALSE**.

## See also

[IQueryContinue](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iquerycontinue)

[IUserNotification](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iusernotification)