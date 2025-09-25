# WdsCliFreeStringArray function

## Description

This function can be used to free the array of string values that gets allocated by the [WdsCliObtainDriverPackages](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdscliobtaindriverpackages) function.

## Parameters

### `ppwszArray` [in, out, optional]

Pointer to the array of string values being freed.

### `ulCount` [in]

Number of strings in the array that is pointed to by *ppwszArray*.

## Return value

If the function succeeds, the return is **S_OK**.