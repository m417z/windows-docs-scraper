# IFaxServer::get_ArchiveDirectory

## Description

The **IFaxServer::get_ArchiveDirectory** method retrieves the **ArchiveDirectory** property for a [FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver-client) object. The **ArchiveDirectory** property is a null-terminated string that contains the location in which the fax server stores archived outbound faxes.

This property is read/write.

## Parameters

## Remarks

Set the [ArchiveOutboundFaxes](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-archiveoutboundfaxes-vb) property to **TRUE** to archive faxes in the directory specified by the **ArchiveDirectory** property. The fax server must have access to the directory to successfully store outbound fax transmissions.

The **get_ArchiveDirectory** method allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver-client)

[Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources)

[IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxserver)

[IFaxServer::get_ArchiveOutboundFaxes](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-archiveoutboundfaxes-vb)