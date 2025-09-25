# MprConfigServerInstall function

## Description

The
**MprConfigServerInstall** function configures Routing and Remote Access Service with a default configuration.

## Parameters

### `dwLevel` [in]

This parameter is reserved for future use, and should be zero.

### `pBuffer` [in]

This parameter is reserved for future use, and should be **NULL**.

## Return value

If the functions succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the following is true: <br><br>* *dwLevel* is not zero.<br>* *pBuffer* is non-**NULL**. |

## Remarks

The
**MprConfigServerInstall** function performs the following tasks:

* Resets the current Router Manager and Interface keys.
* Initializes RAS structures for IP.
* Sets the router type to include:

  ROUTER_TYPE_RAS

  ROUTER_TYPE_WAN

  ROUTER_TYPE_LAN
* Sets the error logging level and authorization settings to defaults.
* Sets the devices for Routing and RAS.
* Adds the RRAS snap-in to the computer management console.
* Deletes the router phone book.
* Registers the router in the domain.
* Writes out the **router is configured** registry key.

The
**MprConfigServerInstall** function does not start Routing and RAS or set the service start type for Routing and RAS.

## See also

[Windows 2000 Registry Layout](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-registry-layout)