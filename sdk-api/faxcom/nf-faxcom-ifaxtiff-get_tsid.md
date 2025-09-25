# IFaxTiff::get_Tsid

## Description

Retrieves the **Tsid** property for a [FaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxtiff) object. The **Tsid** property is a null-terminated string that contains transmitting station identifier (TSID) information, which is typically the fax number of the device that sent the specified fax file.

This property is read-only.

## Parameters

## Remarks

A fax client application must set the [Image](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxtiff-get-image-vb) property before retrieving another property for a [FaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxtiff) object.

The **get_Tsid** method sets the *pVal* parameter to the TSID associated with the specified fax file, if it is available. If the information is not available, the method returns "Unavailable".

The **Tsid** property is a string that represents the TSID associated with the specified fax file, if it is available. If the information is not available, **Tsid** is an empty string.

The **get_Tsid** method allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxtiff)

[IFaxTiff::get_Image](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxtiff-get-image-vb)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)