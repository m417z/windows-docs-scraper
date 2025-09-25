# IFaxTiff::get_RawReceiveTime

## Description

Retrieves the **RawReceiveTime** property for a [FaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxtiff) object. The **RawReceiveTime** property is the time at which reception began for an inbound fax file, expressed in Coordinated Universal Time (UTC). This property can also be the time at which reception or transmission began for an archived file.

This property is read-only.

## Parameters

## Remarks

A fax client application must set the [Image](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxtiff-get-image-vb) property before retrieving another property for a [FaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxtiff) object.

The **get_RawReceiveTime** method sets the *pVal* parameter to the local time at which the fax job started receiving or transmitting the fax file.

The **RawReceiveTime** property contains the local time at which the fax job started receiving or transmitting the fax file.

The [get_ReceiveTime](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxtiff-get-receivetime-vb) method returns the time in a formatted string.

The [ReceiveTime](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxtiff-get-receivetime-vb) property contains the time in a formatted string.

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxtiff)

[IFaxTiff::get_Image](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxtiff-get-image-vb)

[IFaxTiff::get_ReceiveTime](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxtiff-get-receivetime-vb)