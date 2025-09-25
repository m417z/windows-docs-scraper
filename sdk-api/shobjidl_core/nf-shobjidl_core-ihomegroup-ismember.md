# IHomeGroup::IsMember

## Description

Determines whether the local computer is a member of a HomeGroup.

## Parameters

### `member` [out]

Type: **BOOL***

When this method returns successfully, receives **TRUE** if the local computer is a member of a HomeGroup; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The following code snippet shows how to create an instance of [IHomeGroup](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ihomegroup) and call **IHomeGroup::IsMember**.

```
#include "shobjidl.h"
#include "atlbase.h"   // For COM smart pointers

CComPtr<IHomeGroup> spHomeGroup;
HRESULT hr = S_OK;
BOOL fIsHGMember = FALSE;

// Initialize the COM subsystem.
hr = CoInitialize(NULL);
if (FAILED(hr)) return hr;

// Create an instance of IHomeGroup.
hr = CoCreateInstance(CLSID_HomeGroup,
                      NULL,
                      CLSCTX_INPROC_SERVER,
                      IID_PPV_ARGS(&spHomeGroup));

if (FAILED(hr)) return hr;

// fIsHGMember receives the value TRUE if the local computer is a member of a
// HomeGroup, or FALSE if the computer is not a HomeGroup member.
hr = spHomeGroup->IsMember(&fIsHGMember);
```

## See also

[CComPtr](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2010/ezzw7k98(v=vs.100))

[CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance)

[CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize)

[IHomeGroup](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ihomegroup)