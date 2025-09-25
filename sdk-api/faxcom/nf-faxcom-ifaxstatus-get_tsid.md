# IFaxStatus::get_Tsid

## Description

Retrieves the **Tsid** property for the [FaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxstatus) object of a parent [FaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxport) object. The **Tsid** property is a null-terminated string that contains the transmitting station identifier (TSID) associated with the fax port.

This property is read-only.

## Parameters

## Remarks

The **Tsid** property is set for both inbound and outbound fax transmissions. If the TSID information is not available, the **IFaxStatus::get_Tsid** method returns an empty string.

The **IFaxStatus::get_Tsid** method allocates the memory required for the buffer pointed to by the pVal parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxport)

[IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports)

[IFaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxstatus)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)