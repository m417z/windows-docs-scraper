# IFaxTiff::get_TiffTagString

## Description

Retrieves the **TiffTagString** property for a [FaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxtiff) object. The **TiffTagString** property is a null-terminated string that contains the value of a specified Tagged Image File Format (TIFF) tag (field).

This property is read/write.

## Parameters

## Remarks

For more information about Tagged Image File Format Class F (TIFF Class F) files, see [Fax Image Format](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-image-format). For current information about TIFF tags, or for the list of valid TIFF tag numbers, contact Adobe Systems Incorporated.

A fax client application must set the [Image](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxtiff-get-image-vb) property before retrieving another property for a [FaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxtiff) object.

The **get_TiffTagString** method sets the *pVal* parameter to a string that represents the value of the TIFF tag, if it is available. If the information is not available, the method returns "Unavailable".

The **TiffTagString** property is a string that represents the value of the TIFF tag, if it is available. If the information is not available, **TiffTagString** is an empty string.

You can call the **get_TiffTagString** to retrieve information about any TIFF tag, including those that the fax service does not support. Note that you can retrieve this property only for the first page of a TIFF file.

The **TiffTagString** property contains information about any TIFF tag, including those that the fax service does not support. Note that this property only contains information for the first page of a TIFF file.

The **get_TiffTagString** method allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxtiff)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)