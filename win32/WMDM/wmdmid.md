# WMDMID structure

The **WMDMID** structure describes serial numbers and group IDs.

## Members

**cbSize**

Size of the **WMDMID** structure, in bytes.

**dwVendorID**

**DWORD** containing the registered ID number of the vendor. Contains zero if not in use.

**pID\[WMDMID\_LENGTH\]**

Pointer to an array of bytes containing the serial number. The serial number is a string of byte values that have no standard format. Note that this is not a wide-character value. **WMDMID\_LENGTH** is a constant value defined in mswmdm.h.

**SerialNumberLength**

Actual length of the serial number returned, in bytes.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | Wmdm.idl |

## See also

[**IMDSPDevice::GetSerialNumber**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevice-getserialnumber)

[**IMDSPStorageGlobals::GetSerialNumber**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorageglobals-getserialnumber)

[**IWMDMDevice::GetSerialNumber**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice-getserialnumber)

[**IWMDMStorageGlobals::GetSerialNumber**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorageglobals-getserialnumber)

[**Structures**](https://learn.microsoft.com/windows/win32/wmdm/structures)

