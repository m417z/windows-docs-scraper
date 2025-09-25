# IFaxRoutingMethod::get_ExtensionName

## Description

The **IFaxRoutingMethod::get_ExtensionName** property is a null-terminated string that contains the user-friendly name for the fax routing extension DLL that implements the specified fax routing method.

This property is read-only.

## Parameters

## Remarks

A fax client application can use the [IFaxRoutingMethod::get_ImageName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxroutingmethod-get-imagename-vb) property to uniquely identify the fax routing extension DLL that exports a fax routing method. Note that it is possible for multiple routing extensions to have the same user-friendly name.

**IFaxRoutingMethod::get_ExtensionName** allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxroutingmethod)

[IFaxRoutingMethod::get_ImageName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxroutingmethod-get-imagename-vb)

[IFaxRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxroutingmethods)