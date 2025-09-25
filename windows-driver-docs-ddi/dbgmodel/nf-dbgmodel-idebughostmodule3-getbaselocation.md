## Description

The GetBaseLocation method returns the base load address of the module as a location structure. The returned location structure for a module will typically refer to a virtual address.

## Parameters

### `moduleBaseLocation`

The loading address of the base of the module in memory is returned here as a location structure. Typically, this refers to a virtual address.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostModule3> spModule; /* get a module (see FindModuleByName) */

Location moduleBase;
if (SUCCEEDED(spModule->GetBaseLocation(&moduleBase)))
{
    // moduleBase contains the base address of the module
}
```

## See also

[IDebugHostModule3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmodule3)