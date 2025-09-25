# IMbnSignal::GetSignalError

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the received signal error rate.

## Parameters

### `signalError` [out, retval]

Pointer to the error rate in the received signal.

Mobile Broadband Interfaces report the signal error rate as a coded value that maps to the percentage range of error rates. This is the Channel Bit Error Rate for GSM and Frame Error Rate for CDMA. In both the cases, MBN_ERROR_RATE_UNKNOWN specifies an unknown error rate.

The following table shows the values for the error rate codes.

| Bit error rate (in %) | Frame error rate (in %) | Coded value (0-7) |
| --- | --- | --- |
| < 0.2 | < 0.01 | 0 |
| 0.2 - 0.4 | 0.01 - 0.1 | 1 |
| 0.4 - 0.8 | 0.1 - 0.5 | 2 |
| 0.8 - 1.6 | 0.5 - 1.0 | 3 |
| 1.6 - 3.2 | 1.0 - 2.0 | 4 |
| 3.2 - 6.4 | 2.0 - 4.0 | 5 |
| 6.4 - 12.8 | 4.0 - 8.0 | 6 |
| > 12.8 | > 8.0 | 7 |
| unknown | unknown | MBN_ERROR_RATE_UNKNOWN |

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully<br><br>. |
| **E_PENDING** | The error rate is not yet available. The Mobile Broadband service is current probing the device to retrieve the information. When the error rate is available, the Mobile Broadband service will call the [OnSignalStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsignalevents-onsignalstatechange) method of [IMbnSignalEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsignalevents). |

## Remarks

Mobile Broadband interfaces report the signal error rate as a coded value that maps to a percentage range of error rates. This is the Channel Bit Error Rate for GSM and Frame Error Rate for CDMA. For both the cases, **MBN_ERROR_RATE_UNKNOWN** specifies an unknown error rate.

## See also

[IMbnSignal](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsignal)