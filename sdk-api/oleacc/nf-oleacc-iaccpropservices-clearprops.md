# IAccPropServices::ClearProps

## Description

Servers use **ClearProps** to restore default values to properties of accessible elements that they had previously annotated.

If servers know the **HWND** of the object they want to clear, they can use [IAccPropServices::ClearHwndProps](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-clearhwndprops).

## Parameters

### `pIDString` [in]

Type: **const [BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Identify the accessible element that is to be un-annotated.

### `dwIDStringLen` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of *pIDString*.

### `paProps` [in]

Type: **const MSAAPROPID***

Specify an array of properties that is to be reset. These properties will revert to the default behavior they displayed before they were annotated.

### `cProps` [in]

Type: **int**

Size of *paProps* array.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK, even if the specified properties were never annotated on the accessible object; clearing already cleared properties is considered a success.

Returns E_INVALIDARG if any of the properties in the *paProps* array are not supported.

May return other error codes under exceptional error conditions such as low memory.

## Remarks

See the support section for a list of supported properties and their expected types.

Clearing the annotation for a property will cause any associated resources to be released. If a callback property server was used (see [SetPropServer](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-setpropserver)), it will be released.