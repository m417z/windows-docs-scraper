# SHCreateLibrary function

## Description

Creates an [IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary) object.

## Parameters

### `riid` [in]

Type: **REFIID**

The IID for [IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary). (See usage remarks.)

### `ppv` [out]

Type: **void****

Receives a new [IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary) object. (See usage remarks.)

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

### Usage

The **IID_PPV_ARGS** macro is generally used to generate the *riid* and *ppv* parameters for this function. For example:

```
#include "shobjidl.h"
#include "objbase.h" // Defines the IID_PPV_ARGS macro.

...

IShellLibrary *pIShellLib;
SHCreateLibrary(IID_PPV_ARGS(&pIShellLib));

```

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)