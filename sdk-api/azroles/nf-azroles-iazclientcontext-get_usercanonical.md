# IAzClientContext::get_UserCanonical

## Description

The **UserCanonical** property retrieves the name of the current client in canonical format.

This property is read-only.

## Parameters

## Remarks

The canonical client name is retrieved by impersonating the client token and calling the [GetUserNameEx](https://learn.microsoft.com/windows/desktop/api/secext/nf-secext-getusernameexa) function with **NameCanonical** specified for the *NameFormat* parameter.

An example of a client name in canonical format is "example.fourthcoffee.com/software/Ben Smith".