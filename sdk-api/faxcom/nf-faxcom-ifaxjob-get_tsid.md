# IFaxJob::get_Tsid

## Description

The **IFaxJob::get_Tsid** property is a null-terminated string that contains the
transmitting station identifier (TSID)) associated with the fax job.

This property is read-only.

## Parameters

## Remarks

If the TSID is not available, **IFaxJob::get_Tsid** is an empty string.

You can use the [UseDeviceTsid](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-usedevicetsid-vb) property to determine if the fax server is configured to permit user-specified TSIDs.

Note that the T.30 specification of the International Telecommunication Union (ITU) restricts the value of a TSID to 20 ASCII characters. If a fax client application specifies a TSID that contains non-ASCII characters, the fax service removes them. If the TSID exceeds 20 characters, the service truncates the extra characters.

**IFaxJob::get_Tsid** allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjob)

[IFaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjobs)

[UseDeviceTsid](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-usedevicetsid-vb)