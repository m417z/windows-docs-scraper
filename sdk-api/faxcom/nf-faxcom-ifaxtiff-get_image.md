# IFaxTiff::get_Image

## Description

Sets or retrieves the **Image** property for a [FaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxtiff) object. The **Image** property is a null-terminated string that contains the full path and file name of the file represented by the FaxTiff object. The file is a Tagged Image File Format Class F (TIFF Class F) file.

This property is read/write.

## Parameters

## Remarks

A fax client application must set the **Image** property before retrieving another property for a [FaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxtiff) object.

A fax client application can call the **get_Image** retrieval method to determine the name of the facsimile image file that is open as a result of a successful call to the **put_Image** method.

A fax client application can use this retrieval method to determine the name of the facsimile image file that is open as a result of successful assignment of the **Image** property.

The **get_Image** method allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxtiff)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)