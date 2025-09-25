# IFaxServer::GetDeviceProviders

## Description

The **IFaxServer::GetDeviceProviders** method creates a [IFaxDeviceProviders](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdeviceproviders) interface, a collection of fax service providers (FSPs) that are currently registered with the fax service. You can use the **IFaxDeviceProviders** interface to enumerate the FSPs associated with a fax server and to create and access [IFaxDeviceProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdeviceprovider) interfaces for them.

## Parameters

### `ppFaxDeviceProviders` [out, retval]

Type: **[IFaxDeviceProviders](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdeviceproviders)****

An address of a pointer that receives a [IFaxDeviceProviders](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdeviceproviders) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver)

[IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-fax-device-providers)