# IWMDMStorage::SendOpaqueCommand

## Description

The **SendOpaqueCommand** method sends a command to the storage through Windows Media Device Manager, without processing it.

## Parameters

### `pCommand` [in, out]

Pointer to an [OPAQUECOMMAND](https://learn.microsoft.com/windows/desktop/WMDM/opaquecommand) structure containing the command to execute. Data can be passed two ways—from the application to the device, and from the device back to the application when the call finishes.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method is intended for storage media commands that do not affect the operation of Windows Media Device Manager and should be passed through unchanged.

#### Examples

The following C++ code calls **SendOpaqueCommand** to perform a simple custom authentication step with a device. The caller sends its certificate and MAC to the device, which sends back its own certificate and MAC. The application compares the retrieved certificate with the one it has stored, and if they match (and the MAC is correct), it sets bExtraCertified to **TRUE**.

```cpp

    // Call SendOpaqueCommand to exchange extended authentication information.
    {
        HMAC           hMAC;
        OPAQUECOMMAND  Command;
        CERTINFOEX    *pCertInfoEx;
        DWORD          cbData_App   = sizeof(bCertInfoEx_App)/sizeof(bCertInfoEx_App[0]);
        DWORD          cbData_SP    = sizeof(bCertInfoEx_SP)/sizeof(bCertInfoEx_SP[0]);
        DWORD          cbData_Send  = sizeof(CERTINFOEX) + cbData_App;

        // Fill opaque command structure with the application's certificate.
        memcpy(&(Command.guidCommand), &guidCertInfoEx, sizeof(GUID));

        Command.pData = (BYTE *)CoTaskMemAlloc(cbData_Send);
        if (!Command.pData)
        {
            ExitOnFail(hr = E_OUTOFMEMORY);
        }
        Command.dwDataLen = cbData_Send;

        // Map the data in the opaque command to a CERTINFOEX structure, and
        // fill in the cert info to send.
        pCertInfoEx = (CERTINFOEX *)Command.pData;
        pCertInfoEx->hr     = S_OK;
        pCertInfoEx->cbCert = cbData_App;
        memcpy(pCertInfoEx->pbCert, bCertInfoEx_App, cbData_App);

        // Compute MAC on the data, and add to the OPAQUECOMMAND struct.
        g_cWmdm.m_pSAC->MACInit(&hMAC);
        g_cWmdm.m_pSAC->MACUpdate(hMAC, (BYTE*)(&(Command.guidCommand)), sizeof(GUID));
        g_cWmdm.m_pSAC->MACUpdate(hMAC, (BYTE*)(&(Command.dwDataLen)), sizeof(Command.dwDataLen));
        if (Command.pData)
        {
            g_cWmdm.m_pSAC->MACUpdate(hMAC, Command.pData, Command.dwDataLen);
        }
        g_cWmdm.m_pSAC->MACFinal(hMAC, Command.abMAC);

        // Send the opaque command.
        hr = pDevice->SendOpaqueCommand(&Command);
        if (SUCCEEDED(hr))
        {
            // Now verify the retrieved MAC.
            BYTE abMACVerify2[ WMDM_MAC_LENGTH ];
            g_cWmdm.m_pSAC->MACInit(&hMAC);
            g_cWmdm.m_pSAC->MACUpdate(hMAC, (BYTE*)(&(Command.guidCommand)), sizeof(GUID));
            g_cWmdm.m_pSAC->MACUpdate(hMAC, (BYTE*)(&(Command.dwDataLen)), sizeof(Command.dwDataLen));
            if (Command.pData)
            {
                g_cWmdm.m_pSAC->MACUpdate(hMAC, Command.pData, Command.dwDataLen);
            }
            g_cWmdm.m_pSAC->MACFinal(hMAC, abMACVerify2);

            // Verify MAC matches.
            if (memcmp(abMACVerify2, Command.abMAC, WMDM_MAC_LENGTH) == 0)
            {
                 // They match; verify the retrieved certificate.
                // Map the data in the opaque command to a CERTINFOEX structure
                //
                pCertInfoEx = (CERTINFOEX *)Command.pData;

                // In this simple extended authentication scheme, the callee must
                // provide the exact certificate information.
                //
                if ((pCertInfoEx->cbCert != cbData_SP) &&
                    (memcmp(pCertInfoEx->pbCert, bCertInfoEx_SP, cbData_SP) == 0))
                {
                    bExtraCertified = TRUE;
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

[IWMDMStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage)