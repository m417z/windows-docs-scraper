# IMbnSmsReadMsgTextCdma::get_Timestamp

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The timestamp of a message.

This property is read-only.

## Parameters

## Remarks

The format of the timestamp string is "YY/MM/DD,HH:mm:SS±ZZ".

The following table defines the format of the timestamp string.

| Field | Meaning | Example | Range |
| --- | --- | --- | --- |
| YY | Last 2 digits of the year | 07 for 2007 | 00 through 99 |
| MM | Month in double digits | 01 for January | 01 through 12 |
| DD | Date in double digits | 01 for the 1st | 01 through 31 |
| HH | Hours in 24 hour format | 13 for 1PM | 00 through 23 |
| mm | Minutes in double digits | 1 for 1 minute | 00 through 59 |
| SS | Seconds in double digits | 01 for 1 second | 00 though 59 |
| ZZ | Time in relation to GMT | +01 for 1 hour greater | -12 through +13 |

## See also

[IMbnSmsReadMsgTextCdma](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsreadmsgtextcdma)