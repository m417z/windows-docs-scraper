# IAccIdentity::GetIdentityString

## Description

Retrieves a string of bytes (an identity string) that uniquely identifies an accessible element.

If server developers know the **HWND** of the object they want to annotate, they can use one of the following methods instead of using this
method and getting an identity string.

* [IAccPropServices::SetHwndPropStr](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethwndpropstr)
* [IAccPropServices::SetHwndProp](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethwndprop)
* [IAccPropServices::SetHwndPropServer](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethwndpropserver)

## Parameters

### `dwIDChild` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies which child of the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) object the caller wants to identify.

### `ppIDString` [out]

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)****

Address of a variable that receives a pointer to a callee-allocated identity string. The callee allocates the identity string using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc); the caller must release the identity string by using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) when finished.

### `pdwIDStringLen` [out]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Address of a variable that receives the length, in bytes, of the callee-allocated identity string.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return S_OK, except under exceptional error conditions, such as low memory. If not supported, calling [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on [IAccIdentity](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccidentity) should fail.

## Remarks

The returned string should be considered opaque; clients should use it only as a whole, and should not attempt to dissect it or otherwise interpret it manually.

If a client knows or expects that a string is HWND—based, it can use [IAccPropServices::DecomposeHwndIdentityString](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-decomposehwndidentitystring) to attempt to decompose the identity string.