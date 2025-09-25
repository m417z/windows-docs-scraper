# IWMDMStorageGlobals::GetSerialNumber

## Description

The **GetSerialNumber** method retrieves a serial number that uniquely identifies the storage medium.

## Parameters

### `pSerialNum` [out]

Pointer to a [WMDMID](https://learn.microsoft.com/windows/desktop/WMDM/wmdmid) structure specifying the serial number information.

### `abMac` [in, out]

Array of bytes specifying the message authentication code for the parameter data of this method. This memory is allocated and freed by the caller.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Not all storage media support serial numbers, but a serial number is required to support Microsoft digital rights management. If the storage medium cannot report a unique serial number, content protected by Microsoft digital rights management cannot be transferred to this storage medium. The return code should be checked to determine whether the storage medium provides this support.

#### Examples

The following C++ code retrieves the serial number of the root storage object, and verifies the MAC.

```cpp

    hr = m_pStorageGlobals->GetSerialNumber(&m_SerialNumber, (BYTE*)abMAC);
    if (SUCCEEDED(hr))
    {
        // Verify the MAC using the CSecureChannelClient member.
        m_pSAC->MACInit(&hMAC);
        m_pSAC->MACUpdate(hMAC, (BYTE*)(&m_SerialNumber), sizeof(m_SerialNumber));
        m_pSAC->MACFinal(hMAC, (BYTE*)abMACVerify);
        if (memcmp(abMACVerify, abMAC, sizeof(abMAC)) != 0)
        {
            hr = E_FAIL;
        }
    }

```

## See also

[IWMDMStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals)

[Using Secure Authenticated Channels](https://learn.microsoft.com/windows/desktop/WMDM/using-secure-authenticated-channels)