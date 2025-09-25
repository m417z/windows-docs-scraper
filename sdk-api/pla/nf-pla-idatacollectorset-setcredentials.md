# IDataCollectorSet::SetCredentials

## Description

Specifies the user account under which the data collector set runs.

## Parameters

### `user` [in]

A user account under which the data collector set runs. Specify the user name in the form *domain*\*user* or *user*@*domain*.

### `password` [in]

The password of the user account.

## Return value

The property returns S_OK if successful.

## Remarks

To clear the user credentials, set both parameters to **NULL**.

If you do not specify the credentials, PLA tries to run the set as LocalSystem if the current user is a member of the administrator group.

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::UserAccount](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_useraccount)