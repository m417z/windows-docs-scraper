# CSecureChannelClient::fIsAuthenticated

## Description

The **fIsAuthenticated** method verifies that a secure authenticated channel has been successfully established. This method is not used by applications.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method is used to ensure that a secure authentication channel has been established between components before allowing other operations. This includes calls by devices and storages prior to accessing and transferring data streams.

Applications do not need to call this method, but service providers call the corresponding [CSecureChannelServer::fIsAuthenticated](https://learn.microsoft.com/previous-versions/bb231600(v=vs.85)) method and return WMDM_E_NOTCERTIFIED if it returns **FALSE**.

## See also

[Authenticating the Application](https://learn.microsoft.com/windows/desktop/WMDM/authenticating-the-application)

[CSecureChannelClient Class](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelclient-class)