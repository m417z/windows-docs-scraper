## Description

The **IFaxServer::RegisterDeviceProvider** method registers a fax service provider (FSP) with the fax service. Registration takes place after the fax service restarts.

## Parameters

### `bstrGUID`

Type: **BSTR**

Null-terminated string that contains the GUID that uniquely identifies the FSP that is registering.

### `bstrFriendlyName`

Type: **BSTR**

Null-terminated string that contains the user-friendly name to display for the FSP that is registering.

### `bstrImageName`

Type: **BSTR**

Null-terminated string that contains the fully qualified path and file name of the FSPÂ DLL.

### `TspName`

Type: **BSTR**

Null-terminated string that contains the name of the telephony service provider associated with the devices for the FSP.

### `lFSPIVersion`

Type: **long**

A **long** value that indicates the version of the FSP. Should be equal to 0x00010000.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Only an administrator can register a FSP.

To use this method, a user must have the [farMANAGE_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver)

[IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver)