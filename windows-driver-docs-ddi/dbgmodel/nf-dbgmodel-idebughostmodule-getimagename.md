# IDebugHostModule::GetImageName

## Description

The GetImageName method returns the image name of the module. Depending on the value of the allowPath argument, the returned image name may or may not include the full path to the image.

## Parameters

### `allowPath`

If true, indicates that the full path to the module may be included in the output. Whether such path is or is not included is up to the specific debug host and the manner in which the module was loaded. If false, indicates that only the image name of the module will be included in the output.

### `imageName`

The image name (or full path) of the module will be returned here as an allocated string. The caller is responsible for calling SysFreeString to free the string after use.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostModule> spModule; /* get a module (see FindModuleByName) */

BSTR imageName;
if (SUCCEEDED(spModule->GetImageName(false, &imageName)))
{
    // imageName is the name of the image (guaranteed not to have a path
    // in it).  For instance, this might be "notepad.exe"
    SysFreeString(imageName);
}
```

## See also

[IDebugHostModule interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmodule)