# IAccessibleEx::GetRuntimeId

## Description

Retrieves the runtime identifier of this element.

## Parameters

### `pRetVal` [out]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)****

Receives a pointer to the runtime identifier.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The runtime identifier is a provider-defined array of integers, the first item of which must be **UiaAppendRuntimeId**. The runtime identifier must be unique within the parent window.

The MSAA-to-UIA Proxy uses the runtime identifier (together with the window handle) to determine if two interface instances refer to the same underlying element. If **IAccessibleEx::GetRuntimeId** is not implemented, the proxy performs field-by-field comparisons on the two [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) objects to determine if they are equivalent, which is less efficient.

## See also

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

**Conceptual**

[IAccessibleEx](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iaccessibleex)

**Reference**