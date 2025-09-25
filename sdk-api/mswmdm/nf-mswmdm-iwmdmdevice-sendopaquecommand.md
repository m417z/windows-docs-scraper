# IWMDMDevice::SendOpaqueCommand

## Description

The **SendOpaqueCommand** method sends a device-specific command to the device through Windows Media Device Manager. Windows Media Device Manager does not attempt to read the command.

## Parameters

### `pCommand` [in, out]

Pointer to an [OPAQUECOMMAND](https://learn.microsoft.com/windows/desktop/WMDM/opaquecommand) structure specifying the information required to execute the command. If the device returns data, it is returned through the *pData* member of *pCommand*.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method is intended for device commands that do not affect the operation of Windows Media Device Manager and are passed through unchanged.

#### Examples

The following code performs a simplified extended authentication procedure with a device. This procedure is specific to a device.

```cpp

// Call opaque command to exchange extended authentication information.
    //
    {
        HMAC           hMAC;
        OPAQUECOMMAND  Command;
        CERTINFOEX    *pCertInfoEx;
        DWORD          cbData_App   = sizeof(bCertInfoEx_App)/sizeof(bCertInfoEx_App[0]);
        DWORD          cbData_SP    = sizeof(bCertInfoEx_SP)/sizeof(bCertInfoEx_SP[0]);
        DWORD          cbData_Send  = sizeof(CERTINFOEX) + cbData_App;

        // Fill out opaque command structure.
        memcpy(&(Command.guidCommand), &guidCertInfoEx, sizeof(GUID));

        Command.pData = (BYTE *)CoTaskMemAlloc(cbData_Send);
        if (!Command.pData)
        {
            ExitOnFail(hr = E_OUTOFMEMORY);
        }
        Command.dwDataLen = cbData_Send;

        // Map the data in the opaque command to a CERTINFOEX structure, and
        // fill in the certificate info to send.
        pCertInfoEx = (CERTINFOEX *)Command.pData;

        pCertInfoEx->hr     = S_OK;
        pCertInfoEx->cbCert = cbData_App;
        memcpy(pCertInfoEx->pbCert, bCertInfoEx_App, cbData_App);

        // Compute the MAC to send.
        g_cWmdm.m_pSAC->MACInit(&hMAC);
        g_cWmdm.m_pSAC->MACUpdate(hMAC, (BYTE*)(&(Command.guidCommand)), sizeof(GUID));
        g_cWmdm.m_pSAC->MACUpdate(hMAC, (BYTE*)(&(Command.dwDataLen)), sizeof(Command.dwDataLen));
        if (Command.pData)
        {
            g_cWmdm.m_pSAC->MACUpdate(hMAC, Command.pData, Command.dwDataLen);
        }
        g_cWmdm.m_pSAC->MACFinal(hMAC, Command.abMAC);

        // Send the command.
        hr = pDevice->SendOpaqueCommand(&Command);
        if (SUCCEEDED(hr))
        {
            BYTE abMACVerify2[ WMDM_MAC_LENGTH ];

            // Compute retrieved MAC for verification.
            g_cWmdm.m_pSAC->MACInit(&hMAC);
            g_cWmdm.m_pSAC->MACUpdate(hMAC, (BYTE*)(&(Command.guidCommand)), sizeof(GUID));
            g_cWmdm.m_pSAC->MACUpdate(hMAC, (BYTE*)(&(Command.dwDataLen)), sizeof(Command.dwDataLen));
            if (Command.pData)
            {
                g_cWmdm.m_pSAC->MACUpdate(hMAC, Command.pData, Command.dwDataLen);
            }
            g_cWmdm.m_pSAC->MACFinal(hMAC, abMACVerify2);

            // Verify the MAC matches.
            //
            if (memcmp(abMACVerify2, Command.abMAC, WMDM_MAC_LENGTH) == 0)
            {
                // Cast the data in the opaque command to a CERTINFOEX structure.
                //
                pCertInfoEx = (CERTINFOEX *)Command.pData;

                // In this simple extended authentication scheme, the callee must
                // provide the exact certificate info.
                //
                if ((pCertInfoEx->cbCert != cbData_SP) ||
                    (memcmp(pCertInfoEx->pbCert, bCertInfoEx_SP, cbData_SP) == 0))
                {
                    m_fExtraCertified = TRUE;
                }
            }
        }

        if (Command.pData)
        {
            CoTaskMemFree(Command.pData);
        }
    }

```

## See also

[IWMDMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice)