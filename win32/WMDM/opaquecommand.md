# OPAQUECOMMAND structure

The **OPAQUECOMMAND** structure contains data for commands that are passed through Windows Media Device Manager to a device but are not intended to be acted upon by Windows Media Device Manager.

## Members

**guidCommand**

**GUID** representing the requested command.

**dwDataLen**

Length of the data to which *pData* points, in bytes.

**pData**

Data required to execute the command, and/or data returned by the command.

**abMAC\[20\]**

This message authentication code (MAC) should include the **guidCommand** member, the data to which *pdwDataLen* points, and the data to which *pData* points, if any. If *pData* is **NULL**, it must not be included in the MAC. WMDM\_MAC\_LENGTH is defined as 20.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | Wmdm.idl |

## See also

[**IMDSPDevice::SendOpaqueCommand**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevice-sendopaquecommand)

[**IMDSPStorage::SendOpaqueCommands**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage-sendopaquecommand)

[**IWMDMDevice::SendOpaqueCommand**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice-sendopaquecommand)

[**IWMDMStorage::SendOpaqueCommand**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-sendopaquecommand)

[**Structures**](https://learn.microsoft.com/windows/win32/wmdm/structures)

