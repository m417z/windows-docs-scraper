# INetSharingManager::get_SharingInstalled

## Description

[Internet Connection Firewall may be altered or unavailable in subsequent versions. Instead, use the [Windows Firewall API](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page).]

The
**get_SharingInstalled** method reports whether the currently-installed version of Windows XP supports connection sharing.

## Parameters

### `pbInstalled` [out]

A pointer to a **VARIANT_BOOL** that specifies whether the currently-installed version Windows XP supports connection sharing. For more information, see Remarks.

## Return value

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ABORT** | The operation was aborted. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **E_NOINTERFACE** | A specified interface is not supported. |
| **E_NOTIMPL** | A specified method is not implemented. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | A pointer passed as a parameter is not valid. |
| **E_UNEXPECTED** | The method failed for unknown reasons. |

## Remarks

This method sets the *pbInstalled* parameter to **TRUE** when called on the following versions of Windows XP:

* Windows XP Home Edition
* Windows XP Professional
* Windows XP Embedded

This function sets the *pbInstalled* parameter to **FALSE** when called on other versions of Windows XP.

To determine whether sharing is enable for a particular connection, call
[INetSharingConfiguration::get_SharingEnabled](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nf-netcon-inetsharingconfiguration-get_sharingenabled) method for that connection.

## See also

[INetSharingManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingmanager)

[Internet Connection Sharing and Internet Connection Firewall Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-interfaces)

[Internet Connection Sharing and Internet Connection Firewall Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-reference)