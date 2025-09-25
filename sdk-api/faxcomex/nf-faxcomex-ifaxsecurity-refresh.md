# IFaxSecurity::Refresh

## Description

The **IFaxSecurity::Refresh** method refreshes [FaxSecurity](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity) object information from the fax server.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the **IFaxSecurity::Refresh** method is called, any configuration changes made after the last [IFaxSecurity::Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity-save-vb) method call are lost.

To read this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxSecurity](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity)

[IFaxSecurity](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxsecurity)