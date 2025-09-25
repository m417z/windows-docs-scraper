# IFaxTiff::get_SenderName

## Description

Retrieves the **SenderName** property for a [FaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxtiff) object. The **SenderName** property is a null-terminated string that contains the name of the user who queued the fax transmission.

This property is read-only.

## Parameters

## Remarks

A fax client application must set the [Image](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxtiff-get-image-vb) property before retrieving another property for a [FaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxtiff) object.

The **SenderName** property has meaning only for outbound fax transmissions.

The **get_SenderName** method sets the *pVal* parameter to the name of the sender of the specified fax file, if it is available. If the information is not available, the method returns an "Unavailable".

The **SenderName** property is a string that represents the name of the sender of the specified fax file, if it is available. If the information is not available, **SenderName** is an empty string.

The **get_SenderName** method allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxtiff)

[IFaxTiff::get_Image](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxtiff-get-image-vb)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)