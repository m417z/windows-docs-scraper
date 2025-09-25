# IFaxTiff::get_RecipientNumber

## Description

Retrieves the **RecipientNumber** property for a [FaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxtiff) object. The **RecipientNumber** property is a null-terminated string that contains the fax number to which a fax was transmitted.

This property is read-only.

## Parameters

## Remarks

A fax client application must set the [Image](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxtiff-get-image-vb) property before retrieving another property for a [FaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxtiff) object.

The **RecipientNumber** property has meaning only for outbound fax transmissions. This is because the [Csid](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxtiff-get-csid-vb) property and the **RecipientNumber** property are identical for inbound faxes.

The **get_RecipientNumber** method sets the *pVal* parameter to the fax number of the fax recipient, if it is available. If the information is not available, the method returns "Unavailable".

The **RecipientNumber** property is a string that represents the fax number of the fax recipient, if it is available. If the information is not available, **RecipientNumber** is an empty string.

The **get_RecipientNumber** method allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxtiff)

[IFaxTiff::get_Csid](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxtiff-get-csid-vb)

[IFaxTiff::get_Image](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxtiff-get-image-vb)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)