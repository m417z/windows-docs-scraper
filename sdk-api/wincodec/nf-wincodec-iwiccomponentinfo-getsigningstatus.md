# IWICComponentInfo::GetSigningStatus

## Description

Retrieves the signing status of the component.

## Parameters

### `pStatus` [out]

Type: **DWORD***

A pointer that receives the [WICComponentSigning](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wiccomponentsigning) status of the component.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Signing is unused by WIC. Therefore, all components WICComponentSigned.

This function can be used to determine whether a component has no binary component or has been added to the disabled components list in the registry.