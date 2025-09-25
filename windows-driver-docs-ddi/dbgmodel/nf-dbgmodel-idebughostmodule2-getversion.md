# IDebugHostModule2::GetVersion

## Description

The GetVersion method returns version information about the module (assuming that such information can successfully be read out of the headers). If a given version is requested (via a non-nullptr output pointer) and it cannot be read, an appropriate error code will be returned from the method call.

## Parameters

### `fileVersion`

If a non-nullptr address is supplied, the file version of the module will be returned here. If the file version cannot be read from the module headers, this method will fail if a non-nullptr address is provided here. If the file version cannot be read from the module headers and this value is provided as nullptr, it will not cause a failure.

### `productVersion`

If a non-nullptr address is supplied, the product version of the module as indicated in the module headers is returned here. If the product version cannot be read from the module headers, this method will fail if a non-nullptr address is provided here. If the product version cannot be read from the module headers and this value is provided as nullptr, it will not cause a failure.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostModule2> spModule; /* get a module (see FindModuleByName) */

ULONG64 fileVersion;
ULONG64 productVersion;
if (SUCCEEDED(spModule->GetVersion(&fileVersion, &productVersion)))
{
    // fileVersion contains a.b.c.d (16.16.16.16) file version
    // productVersion contains a.b.c.d (16.16.16.16) product version
}
```

## See also

[IDebugHostModule2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmodule2)