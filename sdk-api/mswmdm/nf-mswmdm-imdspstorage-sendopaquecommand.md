# IMDSPStorage::SendOpaqueCommand

## Description

The **SendOpaqueCommands** method sends a command through Windows Media Device Manager. Without acting on it, Windows Media Device Manager passes the command through to a device.

## Parameters

### `pCommand` [in, out]

Pointer to an **OPAQUECOMMAND** structure containing the information required to execute the command.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method is used with device commands that do not affect Windows Media Device Manager, and are passed through unchanged.

This method is optional. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage)

[OPAQUECOMMAND](https://learn.microsoft.com/windows/desktop/WMDM/opaquecommand)