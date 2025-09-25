# IWMDMDevice::GetSerialNumber

## Description

The **GetSerialNumber** method retrieves a serial number that uniquely identifies the device.

## Parameters

### `pSerialNumber` [out]

Pointer to a [WMDMID](https://learn.microsoft.com/windows/desktop/WMDM/wmdmid) structure specifying the serial number information. The **WMDID** structure is allocated and released by the application.

### `abMac` [in, out]

Array of bytes specifying the message authentication code for the parameter data of this method.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Not all devices support serial numbers. To determine whether the device supports serial numbers, the caller must always check the return code when calling this function. If a media device supports serial numbers, the serial number of the media device is guaranteed to be unique for that device.

After calling this method, an application can verify that the serial has not been modified during transport by using the *abMAC* parameter. For example code on this, see [Using Secure Authenticated Channels](https://learn.microsoft.com/windows/desktop/WMDM/using-secure-authenticated-channels).

#### Examples

The following C++ code retrieves the device serial number and verifies the MAC.

```cpp

//
// Get and verify the serial number.
//
WMDMID serialNumber;
BYTE receivedMAC[WMDM_MAC_LENGTH];
hr = pIWMDMDevice->GetSerialNumber(&serialNumber, receivedMAC);

// Check the MAC to guarantee the serial number has not been tampered with.
if (hr == S_OK)
{
    // Initialize a MAC handle,
    // next add all parameters to the MAC,
    // and finally retrieve the calculated MAC value.
    HMAC hMAC;
    BYTE calculatedMAC[WMDM_MAC_LENGTH];
    hr = m_pSAC->MACInit(&hMAC);
    hr = m_pSAC->MACUpdate(hMAC, (BYTE*)(&serialNumber), sizeof(serialNumber));
    hr = m_pSAC->MACFinal(hMAC, (BYTE*)calculatedMAC);
    if (memcmp(calculatedMAC, receivedMAC, sizeof(calculatedMAC)) == 0)
    {
        // MAC is authentic. Print the serial number.
        CHAR* serialNumberBuffer = new CHAR[serialNumber.SerialNumberLength + 1];
        ZeroMemory(serialNumberBuffer, (serialNumber.SerialNumberLength + 1) * sizeof(CHAR));
        memcpy(serialNumberBuffer, serialNumber.pID, serialNumber.SerialNumberLength * sizeof(CHAR));
        // TODO: Display the serial number.
        delete serialNumberBuffer;
    }
    else
        // TODO: Display a message indicating that the serial number MAC does not match in EnumDevices
}

```

## See also

[IWMDMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice)

[Using Secure Authenticated Channels](https://learn.microsoft.com/windows/desktop/WMDM/using-secure-authenticated-channels)