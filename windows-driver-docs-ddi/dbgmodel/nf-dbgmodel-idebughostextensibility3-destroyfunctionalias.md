## Description

The DestroyFunctionAlias method undoes a prior call to the CreateFunctionAlias method. The function will no longer be available under the quick alias name.

## Parameters

### `aliasName`

The (quick) name of the alias being destroyed.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHost> spHost; /* get the debug host */

ComPtr<IDebugHostExtensibility> spHostExtensibility;
if (SUCCEEDED(spHost.As(&spHostExtensibility)))
{
    if (SUCCEEDED(spHostExtensibility->DestroyFunctionAlias(L"sumit")))
    {
        // The alias sumit is now gone.
    }
}
```

## See also

[IDebugHostExtensibility3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostextensibility3)