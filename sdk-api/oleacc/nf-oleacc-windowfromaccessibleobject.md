# WindowFromAccessibleObject function

## Description

Retrieves the window handle that corresponds to a particular instance of an [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface.

## Parameters

### `unnamedParam1` [in]

Type: **IAccessible***

Pointer to the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface whose corresponding window handle will be retrieved. This parameter must not be **NULL**.

### `phwnd` [out]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Address of a variable that receives a handle to the window containing the object specified in *pacc*. If this value is **NULL** after the call, the object is not contained within a window; for example, the mouse pointer is not contained within a window.

## Return value

Type: **STDAPI**

If successful, returns S_OK.

If not successful, returns the following or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | An argument is not valid. |

## See also

[AccessibleObjectFromWindow](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-accessibleobjectfromwindow)

[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)