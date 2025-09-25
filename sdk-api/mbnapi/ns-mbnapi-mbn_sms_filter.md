# MBN_SMS_FILTER structure

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_SMS_FILTER** structure contains the values that describe a set of SMS messages.

## Members

### `flag`

An [MBN_SMS_FLAG](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_sms_flag) value that specifies the message class.

### `messageIndex`

Contains the index of a particular message in device memory. This value is only meaningful when **flag** is set to **MBN_SMS_FLAG_INDEX**. The maximum range of this value is from 1 to the [MaxMessageIndex](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323170(v=vs.85)) property of [IMbnSmsConfiguration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsconfiguration).