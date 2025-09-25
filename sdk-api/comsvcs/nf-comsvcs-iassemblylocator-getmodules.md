# IAssemblyLocator::GetModules

## Description

Used to get the names of the modules that are contained in an assembly.

## Parameters

### `applicationDir` [in]

The directory containing the application.

### `applicationName` [in]

The name of the application domain.

### `assemblyName` [in]

The name of the assembly.

### `pModules` [out]

An array listing the names of the modules in the assembly.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IAssemblyLocator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iassemblylocator)