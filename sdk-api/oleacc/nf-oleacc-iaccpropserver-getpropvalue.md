# IAccPropServer::GetPropValue

## Description

Retrieves a property value for an accessible element.

## Parameters

### `pIDString` [in]

Type: **const BYTE***

Contains a string that identifies the property being requested.

### `dwIDStringLen` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the length of the identity string specified by the *pIDString* parameter.

### `idProp` [in]

Type: **MSAAPROPID**

Specifies a GUID indicating the desired property.

### `pvarValue` [out]

Type: **VARIANT***

Specifies the value of the overridden property. This parameter is valid only if *pfHasProp* is **TRUE**. The server must set this to VT_EMPTY if *pfHasProp* is set to **FALSE**.

### `pfHasProp` [out]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Indicates whether the server is supplying a value for the requested property. The server should set this to **TRUE** if it is returning an overriding property or to **FALSE** if it is not returning a property (in which case it should also set *pvarValue* to VT_EMPTY).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return S_OK, except under exceptional error conditions such as low memory. If the specified property is not overridden, then *pfHasProp* should be set to **FALSE** and *pvarValue* should be set to VT_EMPTY by the server.

## Remarks

If a single callback object is registered for annotating multiple accessible elements, the identity string can be used to determine which element this request refers to.

If the accessible element is **HWND**-based, [IAccPropServices::DecomposeHwndIdentityString](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-decomposehwndidentitystring) can be used to extract the HWND/idObject/idChild from the identity string.

If the callback has a value to return for the specified property, it should return it in *pvarValue* and set *pfHasProp* to **TRUE**. Otherwise it should set *pvarValue* to VT_EMPTY and set *pfHasProp* to **FALSE**. In this latter case, the original [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface pointer will be used to obtain a value for this property.