# IAzClientContext::get_UserDisplay

## Description

The **UserDisplay** property retrieves the name of the current client in user display name format.

This property is read-only.

## Parameters

## Remarks

The user display client name is retrieved by impersonating the client token and calling the [GetUserNameEx](https://learn.microsoft.com/windows/desktop/api/secext/nf-secext-getusernameexa) function with **NameCanonical** specified for the *NameDisplay* parameter.

An example of a client name in user display name format is "Ben Smith".