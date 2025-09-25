# IAzClientContext::get_UserSamCompat

## Description

The **UserSamCompat** property retrieves the name of the current client in a format compatible with Windows Security Account Manager (SAM).

This property is read-only.

## Parameters

## Remarks

The SAM-compatible client name is retrieved by impersonating the client token and calling the [GetUserNameEx](https://learn.microsoft.com/windows/desktop/api/secext/nf-secext-getusernameexa) function with **NameSamCompatible** specified for the *NameFormat* parameter.

An example of a client name in SAM-compatible format is "ExampleDomain\UserName".