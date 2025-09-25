# IComIdentityEvents::OnIISRequestInfo

## Description

Generated when an activity is part of an ASP page.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `ObjId` [in]

The unique identifier for this object.

### `pszClientIP` [in]

The Internet Protocol (IP) address of the IIS client.

### `pszServerIP` [in]

The IP address of the IIS server.

### `pszURL` [in]

The URL on IIS server generating object reference.

## Return value

The user verifies the return values from this method.

## See also

[IComIdentityEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomidentityevents)