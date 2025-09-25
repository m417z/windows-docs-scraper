# GROUPPROP enumeration

## Description

[Queue Manager (QMGR) is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Background Intelligent Transfer Service (BITS)](https://learn.microsoft.com/windows/desktop/Bits/background-intelligent-transfer-service-portal).]

The **GROUPPROP** enumeration defines the constant values for retrieving and setting group property values.

## Constants

### `GROUPPROP_PRIORITY:0`

Determines when the QMGR processes the group relative to other groups in the queue.

There is only one priority. You must specify a value of 1 when setting this property. The property always returns a value of 1.

Variant data type can be VT_I4, VT_I2, VT_UI4, VT_UI2, VT_INT, or VT_UINT.

### `GROUPPROP_REMOTEUSERID:1`

Not supported.

### `GROUPPROP_REMOTEUSERPWD:2`

Not supported.

### `GROUPPROP_LOCALUSERID:3`

Not supported.

### `GROUPPROP_LOCALUSERPWD:4`

Not supported.

### `GROUPPROP_PROTOCOLFLAGS:5`

Specifies the protocol to use for the download.

You must specify QM_PROTOCOL_HTTP when setting this property.

Variant data type can be VT_I4, VT_I2, VT_UI4, VT_UI2, VT_INT, or VT_UINT.

### `GROUPPROP_NOTIFYFLAGS:6`

Specifies the type of event notification to receive for the group. See Remarks.

Variant data type can be VT_I4, VT_I2, VT_UI4, VT_UI2, VT_INT, or VT_UINT.

### `GROUPPROP_NOTIFYCLSID:7`

The CLSID to activate when an event specified by **GROUPPROP_NOTIFYFLAGS** occurs. For more details on CLSID activation, see [IBackgroundCopyCallback1](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopycallback1).

Variant data type is VT_BSTR.

### `GROUPPROP_PROGRESSSIZE:8`

Not supported.

### `GROUPPROP_PROGRESSPERCENT:9`

Not supported.

### `GROUPPROP_PROGRESSTIME:10`

Not supported.

### `GROUPPROP_DISPLAYNAME:11`

Specifies a display name that can be used to identify the group in a user interface. The length of the string is limited to 256 characters, not including the null terminator.

Variant data type is VT_BSTR.

### `GROUPPROP_DESCRIPTION:12`

Specifies a description to associate with the group. The length of the string is limited to 1,024 characters, not including the null terminator.

Variant data type is VT_BSTR.

## Remarks

The **GROUPPROP_NOTIFYFLAGS** group property can contain one or more of the following notification flags.

| Flag | Meaning |
| --- | --- |
| QM_NOTIFY_FILE_DONE | Not supported. |
| QM_NOTIFY_JOB_DONE | Not supported. |
| QM_NOTIFY_GROUP_DONE | Notifies the application through [IBackgroundCopyCallback1::OnStatus](https://learn.microsoft.com/windows/desktop/api/qmgr/nf-qmgr-ibackgroundcopycallback1-onstatus) that the group is complete. |
| QM_NOTIFY_DISABLE_NOTIFY | Disables all notifications. |
| QM_NOTIFY_USE_PROGRESSEX | Not supported. |

**Note** By default, QMGR calls your [IBackgroundCopyCallback1::OnStatus](https://learn.microsoft.com/windows/desktop/api/qmgr/nf-qmgr-ibackgroundcopycallback1-onstatus) method when an error occurs.