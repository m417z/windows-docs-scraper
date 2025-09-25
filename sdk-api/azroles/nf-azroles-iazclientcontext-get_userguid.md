# IAzClientContext::get_UserGuid

## Description

The **UserGuid** property retrieves the name of the current client in GUID format.

This property is read-only.

## Parameters

## Remarks

The GUID client name is retrieved by impersonating the client token and calling the [GetUserNameEx](https://learn.microsoft.com/windows/desktop/api/secext/nf-secext-getusernameexa) function with **NameUniqueId** specified for the *NameFormat* parameter.

An example of a client name in GUID format is "{4fa050f0-f561-11cf-bdd9-00aa003a77b6}Ben Smith".