# IFaxDeviceProviders::get_Item

## Description

The **IFaxDeviceProviders::get_Item** property returns a [FaxDeviceProvider](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceprovider) object from the [FaxDeviceProviders](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceproviders) collection.

## Parameters

### `vIndex` [in]

Type: **VARIANT**

**VARIANT** that specifies the item to retrieve from the collection.

If this parameter is type VT_I2 or VT_I4, the parameter specifies the index of the item to retrieve from the collection. The index is 1-based. If this parameter is type VT_BSTR, the parameter is the unique name that identifies the FSP to retrieve. Other types are not supported.

### `pFaxDeviceProvider` [out]

Type: **[IFaxDeviceProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdeviceprovider)****

Address of a pointer to a [IFaxDeviceProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdeviceprovider) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FaxDeviceProvider](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceprovider)

[IFaxDeviceProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdeviceprovider)

[IFaxDeviceProviders](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdeviceproviders)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-fax-device-providers)