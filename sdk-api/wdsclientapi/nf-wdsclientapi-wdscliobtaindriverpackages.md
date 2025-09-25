# WdsCliObtainDriverPackages function

## Description

This function obtains from a WDS image, the driver packages (INF files) that can be used on this computer. The [WdsCliFreeStringArray](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifreestringarray) function can be used to free the array of string values allocated by this function.

## Parameters

### `hImage` [in]

A handle to a WDS image.

### `ppwszServerName` [out]

A pointer to a pointer to a string value that receives the IP address of the server hosting the driver packages.

### `pppwszDriverPackages` [out]

An array of string values that are the full paths for the driver packages (INF files.) The Internet Protocol (IP) address, rather than a computer name, is returned as part of the path. For example, a string value **\\172.31.224.245\REMINST\Stores\Drivers\driver.inf** in the array gives the full path to driver.inf.

### `pulCount` [out]

The number of driver packages returned by *pppwszDriverPackages*.

## Return value

If the function succeeds, the return is **S_OK**.

## See also

[Windows Deployment Services Client Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-client-functions)