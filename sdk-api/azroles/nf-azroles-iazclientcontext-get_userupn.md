# IAzClientContext::get_UserUpn

## Description

The **UserUpn** property retrieves the name of the current client in user principal name (UPN) format.

This property is read-only.

## Parameters

## Remarks

The UPN client name is retrieved by impersonating the client token and calling the [GetUserNameEx](https://learn.microsoft.com/windows/desktop/api/secext/nf-secext-getusernameexa) function with **NameUserPrincipal** specified for the *NameFormat* parameter.

An example of a client name in UPN format is "someone@example.com".