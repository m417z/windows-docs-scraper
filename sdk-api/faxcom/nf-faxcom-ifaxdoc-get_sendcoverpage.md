# IFaxDoc::get_SendCoverpage

## Description

Sets or retrieves the **SendCoverpage** property for a [FaxDoc](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdoc) object. The **SendCoverpage** property is a Boolean value that indicates whether the specified cover page file is stored on the fax server.

This property is read/write.

## Parameters

## Remarks

To send a cover page with a fax document, the following are required:

* The **SendCoverpage** property must be equal to **TRUE**.
* The **CoverpageName** property must specify a valid cover page file.

In addition, the [ServerCoverpage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxdoc-get-servercoverpage-vb) property must be equal to **TRUE** if the cover page file is a common cover page file. For more information, see [CoverpageName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxdoc-get-coverpagename-vb).

You can call the [ServerCoverpage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-servercoverpage-vb) method to determine whether the fax server is configured to permit personal cover pages.

The **IFaxDoc::get_SendCoverpage** method allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

For more information, see [Cover Pages](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-cover-pages) and [Sending a Cover Page](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-sending-a-cover-page).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxDoc](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxdoc)

[IFaxDoc::get_FileName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxdoc-get-filename-vb)

[IFaxDoc::get_ServerCoverpage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxdoc-get-servercoverpage-vb)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)