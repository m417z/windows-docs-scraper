# ObjectFromLresult function

## Description

Retrieves a requested interface pointer for an accessible object based on a previously generated object reference.

This function is designed for internal use by Microsoft Active Accessibility and is documented for informational purposes only. Neither clients nor servers should call this function.

## Parameters

### `lResult` [in]

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A 32-bit value returned by a previous successful call to the [LresultFromObject](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-lresultfromobject) function.

### `riid` [in]

Type: **REFIID**

Reference identifier of the interface to be retrieved. This is IID_IAccessible.

### `wParam` [in]

Type: **[WPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value sent by the associated [WM_GETOBJECT](https://learn.microsoft.com/windows/win32/winauto/wm-getobject) message in its *wParam* parameter.

### `ppvObject` [out]

Type: **void****

Receives the address of the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface on the object that corresponds to the [WM_GETOBJECT](https://learn.microsoft.com/windows/win32/winauto/wm-getobject) message.

## Return value

Type: **STDAPI**

If successful, returns S_OK.

If not successful, returns one of the following standard [COM error codes](https://learn.microsoft.com/windows/desktop/WinAuto/return-values).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are not valid. This occurs when the *lResult* parameter specified is not a value obtained by a call to [LresultFromObject](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-lresultfromobject), or when *lResult* is a value used on a previous call to [ObjectFromLresult](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-objectfromlresult). |
| **E_NOINTERFACE** | The object specified in the *ppvObject* parameter does not support the interface specified by the *riid* parameter. |
| **E_OUTOFMEMORY** | Insufficient memory to store the object reference. |
| **E_UNEXPECTED** | An unexpected error occurred. |

## See also

[WM_GETOBJECT](https://learn.microsoft.com/windows/win32/winauto/wm-getobject)