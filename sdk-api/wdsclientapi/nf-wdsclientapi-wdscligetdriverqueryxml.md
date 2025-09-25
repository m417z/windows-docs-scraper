# WdsCliGetDriverQueryXml function

## Description

This function generates an XML string which can be used to query a WDS server for driver packages using the [WdsCliObtainDriverPackagesEx](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdscliobtaindriverpackagesex) function. The target OS information section of the WDS driver query XML is generated if the path to the Windows directory of the applied image is specified.

## Parameters

### `pwszWinDirPath` [in, optional]

The path to the Windows directory of the applied image. This parameter is optional. If it is specified, the section of the WDS driver query XML for the target operating system is generated.

### `ppwszDriverQuery` [out]

A pointer to a pointer to a string that receives the generated WDS driver query XML. The caller has to free this buffer using "delete\[\]\(\*ppwszDriverQuery\)".

## Return value

If the function succeeds, the return is **S_OK**.