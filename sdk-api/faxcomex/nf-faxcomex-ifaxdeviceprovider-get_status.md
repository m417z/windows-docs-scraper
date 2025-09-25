# IFaxDeviceProvider::get_Status

## Description

The **IFaxDeviceProvider::get_Status** property is a number that indicates whether the fax service provider (FSP) loaded and initialized successfully.

This property is read-only.

## Parameters

## Remarks

If the FSP did not load successfully, the property indicates the reason for the failure, and [IFaxDeviceProvider::get_InitErrorCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceprovider-initerrorcode-vb) holds the last error code value. For more information, see [FAX_PROVIDER_STATUS_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_provider_status_enum).

## See also

[FaxDeviceProvider](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceprovider)

[IFaxDeviceProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdeviceprovider)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-fax-device-providers)