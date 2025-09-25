# IDebugHostSymbols::EnumerateModules

## Description

The EnumerateModules method creates an enumerator which will enumerate every module available in a particular host context. That host context might encapsulate a process context or it might encapsulate something like the Windows kernel.

## Parameters

### `context`

The host context for which to enumerate every loaded module.

### `moduleEnum`

An enumerator which will enumerate every module loaded into the given context will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHost> spHost; /* get the host */

ComPtr<IDebugHostSymbols> spSym;
if (SUCCEEDED(spHost.As(&spSym)))
{
    // Enumerate all modules in the current UI context (process) of the debug host:
    ComPtr<IDebugHostSymbolEnumerator> spEnum;
    if (SUCCEEDED(spSym->EnumerateModules(USE_CURRENT_HOST_CONTEXT, &spEnum)))
    {
        HRESULT hr = S_OK;
        while (SUCCEEDED(hr))
        {
            ComPtr<IDebugHostSymbol> spModSym;
            hr = spEnum->GetNext(&spModSym);
            if (SUCCEEDED(hr))
            {
                ComPtr<IDebugHostModule> spModule;
                if (SUCCEEDED(spModSym.As(&spModule))) /* should always succeed */
                {
                    // spModule is one of the modules in the current
                    // UI context (process) of the debug host
                }
            }
        }

        // hr == E_BOUNDS : hit the end of the enumerator
        // hr == E_ABORT  : a user interrupt was requested /
        //                  propagate upwards immediately
    }
}
```

## See also

[IDebugHostSymbols interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostsymbols)