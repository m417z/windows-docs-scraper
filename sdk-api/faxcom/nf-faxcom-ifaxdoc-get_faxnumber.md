# IFaxDoc::get_FaxNumber

## Description

Sets or retrieves the **FaxNumber** property of a [FaxDoc](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdoc) object. The **FaxNumber** property is a null-terminated string that contains the fax number to which the fax server will send the fax transmission.

This property is read/write.

## Parameters

## Remarks

The recipient's fax number can appear on the cover page.

The **FaxNumber** property is required to send a fax transmission using a call to the [IFaxDoc::Send](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxdoc-send-vb) method. For more information, see [Transmitting Faxes](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-transmitting-faxes).

The **FaxNumber** property is required to send a fax transmission using a call to the [Send](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxdoc-send-vb) method. For more information, see [Transmitting Faxes](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-transmitting-faxes).

The **get_FaxNumber** method allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxDoc](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxdoc)

[IFaxDoc::Send](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxdoc-send-vb)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)