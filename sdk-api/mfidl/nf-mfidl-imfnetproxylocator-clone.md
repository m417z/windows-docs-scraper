# IMFNetProxyLocator::Clone

## Description

Creates a new instance of the default proxy locator.

## Parameters

### `ppProxyLocator` [out]

Receives a pointer to the new proxy locator object's [IMFNetProxyLocator](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetproxylocator) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFNetProxyLocator](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetproxylocator)