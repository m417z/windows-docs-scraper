# IWMPSyncDevice::getItemInfo

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getItemInfo** method retrieves a metadata value from the device.

## Parameters

### `bstrItemName` [in]

**BSTR** containing the metadata item name. The following table lists the supported item names and describes the value that each retrieves.

| Name | Retrieves |
| --- | --- |
| AutoSyncDefaultRules | Whether automatic synchronization is done according to default rules or custom rules. A value of "True" indicates default rules, and a value of "False" indicates custom rules.<br><br>Use of this attribute is permitted only for devices that have a partnership with Windows Media Player.<br><br>Requires Windows Media Player 12. |
| BackgroundSyncState | Whether Windows Media Player is allowed to perform background operations for the device.<br><br>The value can be a string (**BSTR**) representation of a bitwise combination of one or more of the following flags.<br><br>* 1 Background synchronization is allowed.<br>* 2 Background transcoding is allowed.<br><br>The value can also be one of the following strings.<br><br>* "0" No background operations are allowed.<br>* "255" All background operations are allowed.<br><br>The value of this attribute lasts for the lifetime of Windows Media Player, but is not stored in the Windows Media Player library.<br><br>Use of this attribute is permitted only for devices that have a partnership with Windows Media Player.<br><br>Requires Windows Media Player 12. |
| Connected | Whether the device is currently connected to Windows Media Player. Possible values are "True" and "False". |
| FreeSpace | The size, in bytes, of the available device memory. |
| FriendlyName | The friendly name for the device. |
| LastSyncErrorCount | The number of synchronization errors that occurred during the most recent synchronization. |
| LastSyncNoFitCount | The number of media items that would not fit on the device during the most recent synchronization. |
| LastSyncTime | The time of the most recent synchronization. |
| Name | The name of the device. |
| PercentSpaceReserved | Limits the amount of device storage that Windows Media Player uses for file synchronization by specifying a portion of the storage as reserved. The value is the numeric percentage of total storage on the device represented by a string (**BSTR**). Supported values range from "0" to "95" inclusive.Use of this attribute is permitted only for devices that have a partnership with Windows Media Player.<br><br>Requires Windows Media Player 11. |
| PreferredAudio | A string (**BSTR**) representation of the numeric identifier of the preferred storage for audio files on the device. If the device supports hints, the preferred storage is the location specified by the hint. If the device does not support hints, the preferred storage is the largest storage.<br><br>Requires Windows Media Player 12. |
| PreferredVideo | A string (**BSTR**) representation of the numeric identifier of the preferred storage for video files on the device. If the device supports hints, the preferred storage is the location specified by the hint. If the device does not support hints, the preferred storage is the largest storage.<br><br>Requires Windows Media Player 12. |
| PreferredPhoto | A string (**BSTR**) representation of the numeric identifier of the preferred storage for picture files on the device. If the device supports hints, the preferred storage is the location specified by the hint. If the device does not support hints, the preferred storage is the largest storage.<br><br>Requires Windows Media Player 12. |
| SerialNumber | The device serial number. |
| SkippedFiles | Whether the device has any skipped files. A value of "1" indicates that the device has skipped files. A value of "0" indicates that the device does not have any skipped files.<br><br>Use of this attribute is permitted only for devices with which Windows Media Player has a partnership.<br><br>Requires Windows Media Player 12. |
| SupportsAudio | Whether the device supports audio playback. Possible values are "True" and "False". |
| SupportsPhoto | Whether the device supports displaying photos. Possible values are "True" and "False". |
| SupportsVideo | Whether the device supports video playback. Possible values are "True" and "False". |
| SyncFilter | The types of files that will be synchronized during the next synchronization session, and an indication of whether content can be acquired from the device during that synchronization session.<br><br>The value can be a string (**BSTR**) representation of a bitwise combination of one or more of the following flags.<br><br>* "1" Music files will be synchronized.<br>* "2" Video files will be synchronized.<br>* "4" Picture files will be synchronized.<br>* "8" Content can be written to the device, but can not be acquired from the device.<br><br>For example, the string value "5" indicates that music and picture files will be synchronized.<br><br>The value can also be one of the following strings.<br><br>* "0xFF" No filter will be applied to the synchronization session. That is, files of all types will be synchronized, and content can be both written to the device and acquired from the device.<br>* "0x07" Files of all types will be synchronized.<br><br>This attribute affects only the next synchronization session.<br><br>Use of this attribute is permitted only for devices that have a partnership with Windows Media Player.<br><br>Requires Windows Media Player 12. |
| SyncIndex | The partnership index for the device. Possible values are the integers 0 through 16. |
| SyncItemCount | The count of items synchronized to the device. |
| SyncOnConnect | Whether Windows Media Player will synchronize the device when the device gets connected. A value of "True" indicates that Windows Media Player will synchronize the device, and a value of "False" indicates that Windows Media Player will not synchronize the device.<br><br>Use of this attribute is permitted only for devices that have a partnership with Windows Media Player.<br><br>Requires Windows Media Player 12. |
| SyncPercentComplete | The progress of synchronization as a percentage. |
| SyncRelationship | A number indicating how the device synchronizes with respect to the current instance of Windows Media Player. Possible values are:0, meaning no relationship.<br><br>1, meaning manual synchronization.<br><br>2, meaning a partnership exists with the current instance of Windows Media Player.<br><br>3, meaning a partnership exists with another instance of Windows Media Player. |
| TotalSpace | The size, in bytes, of the total memory for the device. |

### `pbstrVal` [out]

Pointer to a **BSTR** that contains the specified metadata item name.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_PDA_INITIALIZINGDEVICES (0xC00D118D)** | Windows Media Player is currently busy initializing devices. Please try again later. |

## Remarks

This method cannot retrieve metadata values for devices having the status **wmpdsManualDevice**.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPSyncDevice Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsyncdevice)

[Retrieving Device Attributes](https://learn.microsoft.com/windows/desktop/WMP/retrieving-device-attributes)