# IFaxSecurity2::Refresh

## Description

Refreshes [FaxSecurity2](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity2) object information from the fax server.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the **IFaxSecurity2::Refresh** method is called, any configuration changes made after the last [IFaxSecurity2::Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity2-save-vb) method call are lost.

To use this method, a user must have the [far2QUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2) access right.

## See also

[FaxSecurity2](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity2)

[IFaxSecurity2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxsecurity2)