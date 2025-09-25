# IFaxDoc::get_RecipientName

## Description

Sets or retrieves the **RecipientName** property of a [FaxDoc](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdoc) object. The **RecipientName** property is a null-terminated string that contains the name of the recipient of the fax transmission.

This property is read/write.

## Parameters

## Remarks

The fax recipient's name can appear on the cover page.

The **get_RecipientName** method allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxDoc](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxdoc)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)