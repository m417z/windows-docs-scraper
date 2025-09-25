# IAccPropServices::SetPropServer

## Description

Servers use **SetPropServer** to specify a callback object to be used to annotate an array of properties for the accessible element. You can also specify whether the annotation is to be applied to this accessible element or to the element and its children. This method is used for [server annotation](https://learn.microsoft.com/windows/desktop/WinAuto/server-annotation).

If server developers know the **HWND** of the accessible element they want to annotate, they can use [IAccPropServices::SetHwndPropServer](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccpropservices-sethwndpropserver).

## Parameters

### `pIDString` [in]

Type: **const [BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Identifies the accessible element that is to be annotated.

### `dwIDStringLen` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the length of the string identified by the *pIDString* parameter.

### `paProps` [in]

Type: **const MSAAPROPID***

Specifies an array of properties to be handled by the specified callback object.

### `cProps` [in]

Type: **int**

Specifies an array of properties to be handled by the specified callback object.

### `pServer` [in]

Type: **IAccPropServer***

Specifies the callback object that will be invoked when a client requests one of the overridden properties.

### `annoScope` [in]

Type: **AnnoScope**

May be ANNO_THIS, indicating that the annotation affects the indicated accessible element only; or ANNO_CONTAINER, indicating that it applies to the element and its immediate element children.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

Returns E_INVALIDARG if any of the properties in the *paProps* array are not supported properties, if the identity string is not valid, or if *annoScope* is not one of ANNO_THIS or ANNO_CONTAINER.

May return other error codes under exceptional error conditions such as low memory.

## Remarks

See the support section for a list of supported properties and their expected types.

The annotation run time will use [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) to increment the reference counter for the *pServer* callback object appropriately. The caller is free to [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) it after calling this method. The annotation run time will automatically release the callback object after the accessible element being annotated is no longer being used.