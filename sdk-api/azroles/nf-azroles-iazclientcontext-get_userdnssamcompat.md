# IAzClientContext::get_UserDnsSamCompat

## Description

The **UserDnsSamCompat** property retrieves the name of the current client in a DNS format compatible with Windows Security Account Manager (SAM).

This property is read-only.

## Parameters

## Remarks

The SAM-compatible DNS client name is retrieved by impersonating the client token and calling the [GetUserNameEx](https://learn.microsoft.com/windows/desktop/api/secext/nf-secext-getusernameexa) function with **NameDnsDomain** specified for the *NameFormat* parameter.

An example of a client name in SAM-compatible DNS format is "example.fourthcoffee.com\Username".