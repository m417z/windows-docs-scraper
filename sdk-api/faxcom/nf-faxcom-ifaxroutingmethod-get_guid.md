# IFaxRoutingMethod::get_Guid

## Description

The **IFaxRoutingMethod::get_Guid** property is a null-terminated string that contains the GUID that uniquely identifies the fax routing method.

This property is read-only.

## Parameters

## Remarks

A fax client application can use the **IFaxRoutingMethod::get_Guid** property to uniquely identify a fax routing method. It is possible for multiple routing methods to have the same user-friendly name, and even the same function name. For more information, see [Fax Routing Methods](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-routing-methods).

**IFaxRoutingMethod::get_Guid** allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxroutingmethod)

[IFaxRoutingMethod::get_FriendlyName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxroutingmethod-get-friendlyname-vb)

[IFaxRoutingMethod::get_FunctionName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxroutingmethod-get-functionname-vb)

[IFaxRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxroutingmethods)