# IMbnConnectionProfile::GetProfileXmlData

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the XML data of the current profile.

## Parameters

### `profileData` [out, retval]

A pointer to a string containing the profile in XML format. If the method returns S_OK, the calling application must free the allocated memory by calling [SysFreeString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The data provided by this method complies with the [Mobile Broadband Profile Schema Reference](https://learn.microsoft.com/windows/desktop/mbn/schema-schema). The data will not contain the password used in the profile.

## See also

[IMbnConnectionProfile](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofile)