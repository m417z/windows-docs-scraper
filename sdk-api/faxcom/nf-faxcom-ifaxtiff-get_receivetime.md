# IFaxTiff::get_ReceiveTime

## Description

Retrieves the **ReceiveTime** property for a [FaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxtiff) object. The **ReceiveTime** property is a null-terminated string that contains the time at which reception began for an inbound fax file. The string can contain the time at which reception or transmission began for an archived file.

This property is read-only.

## Parameters

## Remarks

A fax client application must set the [Image](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxtiff-get-image-vb) property before retrieving another property for a [FaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxtiff) object.

The **get_ReceiveTime** method sets the *pVal* parameter to the time at which reception began for an inbound fax file, if it is available. If the information is not available, the method returns an empty string.

The **ReceiveTime** property is a string that represents the time at which reception began for an inbound fax file, if it is available. If the information is not available, **RecipientName** is "Unavailable".

The **get_ReceiveTime** method allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

The fax service formats the string according to the user's locale. It is a concatenation of the date and time the service transmitted the fax. The date is separated from the time by an "@" character. For example, in the English locale, a string would be formatted as follows:

10/02/98@10:15AM

The [RawReceiveTime](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxtiff-get-rawreceivetime-vb) property contains the time expressed in Coordinated Universal Time (UTC).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxtiff)

[IFaxTiff::get_Image](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxtiff-get-image-vb)

[IFaxTiff::get_RawReceiveTime](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxtiff-get-rawreceivetime-vb)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)