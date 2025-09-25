# IFaxDoc::get_Tsid

## Description

Sets or retrieves the **Tsid** property of a [FaxDoc](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdoc) object. The **Tsid** property is a null-terminated string that contains a user-defined transmitting station identifier (TSID).

This property is read/write.

## Parameters

## Remarks

If the fax server allows user-defined TSID strings, the service will transmit the value of the *pVal* parameter to the receiving fax device instead of the TSID associated with the sending device. You can call the [UseDeviceTsid](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-usedevicetsid-vb) method to determine whether the fax server is configured to permit user-specified TSIDs.

If the fax server allows user-defined TSID strings, the service will transmit the value of *pVal* to the receiving fax device instead of the TSID associated with the sending device. You can use the [UseDeviceTsid](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-usedevicetsid-vb) property to determine whether the fax server is configured to permit user-specified TSIDs.

The TSID is typically the fax number of the device sending the transmission. Note that the T.30 specification of the International Telecommunication Union (ITU) restricts the value of a TSID to 20 ASCII characters. If a fax client application specifies a TSID that contains non-ASCII characters, the fax service removes them. If the TSID exceeds 20 characters, the service truncates the extra characters.

The **get_Tsid** method allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxDoc](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxdoc)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)

[UseDeviceTsid](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-usedevicetsid-vb)