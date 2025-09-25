# IFaxStatus::Refresh

## Description

The **Refresh** method updates [FaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxstatus) object information for the associated parent [FaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxport) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call the **IFaxStatus::Refresh** method to update the information for a [FaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxstatus) object. An application must call this method to poll a fax port for new status information. After you successfully call **IFaxStatus::Refresh**, you must call the appropriate [IFaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxstatus) interface method to retrieve new attribute values that are valid.

It is recommended that you limit calls to this method because frequent calls to **IFaxStatus::Refresh** can affect system performance.

## See also

[IFaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxstatus)