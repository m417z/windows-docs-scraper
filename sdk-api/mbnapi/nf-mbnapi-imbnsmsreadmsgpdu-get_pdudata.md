# IMbnSmsReadMsgPdu::get_PduData

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The PDU message in hexadecimal format as used by GSM devices.

This property is read-only.

## Parameters

## Remarks

 For GSM devices, this data in *PduData* is compliant to the PDU structure defined in 3GPP TS 27.005 and 3GPP TS 23.040.

The table below shows an example of how a PDU message containing the message "Hello" would be structured.

|  |  |  |  |
| --- | --- | --- | --- |
| Example | 07 | 91198994000010 | 11000A9189945086180000AA05C8329BFD06 |
| Contents | Size of Service Center Address | Service Center Address | PDU in hexadecimal format |
| Size | 1 byte | Variable | Variable |

For CDMA devices, this property returns **NULL**.

## See also

[IMbnSmsReadMsgPdu](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsreadmsgpdu)