# IAzClientContext::get_UserDn

## Description

The **UserDn** property retrieves the name of the current client in distinguished name (DN) format.

This property is read-only.

## Parameters

## Remarks

The DN client name is retrieved by impersonating the client token and calling the [GetUserNameEx](https://learn.microsoft.com/windows/desktop/api/secext/nf-secext-getusernameexa) function with **NameFullyQualifiedDN** specified for the *NameFormat* parameter.

An example of a client name in DN format is "CN=Ben Smith, OU=Software, OU=Example, O=FourthCoffee, C=US".