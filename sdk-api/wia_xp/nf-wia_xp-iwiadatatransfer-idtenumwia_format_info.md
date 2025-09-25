# IWiaDataTransfer::idtEnumWIA_FORMAT_INFO

## Description

The **IWiaDataTransfer::idtEnumWIA_FORMAT_INFO** method creates a banded transfer implementation of the [IEnumWIA_FORMAT_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_format_info) interface.

## Parameters

### `ppEnum` [out]

Type: **[IEnumWIA_FORMAT_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_format_info)****

Receives the address of a pointer to the [IEnumWIA_FORMAT_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_format_info) interface.

## Return value

Type: **HRESULT**

If it fails for any reason other than those specified in the following table, this method will return a standard COM error.

| Return Value | Meaning |
| --- | --- |
| E_INVALIDARG | The *ppEnum* parameter is not the address of a pointer to the [IEnumWIA_FORMAT_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_format_info) interface. |
| E_OUTOFMEMORY | There is not enough memory to create the enumerator object. |
| S_OK | The enumerator object was successfully created. |

## Remarks

This method creates the [IEnumWIA_FORMAT_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_format_info) interface that applications use to enumerate an array of [WIA_FORMAT_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_format_info) structures. This provides applications with the ability to determine the formats and media types of incoming data when transferring banded data.

Note that applications must call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the interface pointers they receive through the *ppEnum* parameter.