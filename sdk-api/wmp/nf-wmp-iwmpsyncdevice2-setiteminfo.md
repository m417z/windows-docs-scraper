# IWMPSyncDevice2::setItemInfo

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **setItemInfo** method specifies an attribute value for a device.

## Parameters

### `bstrItemName` [in]

**BSTR** specifying the name of the attribute on which to set the new value. For supported attribute names, see Remarks.

### `bstrVal` [in]

**BSTR** specifying the new value. For information about supported values, see Remarks.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded or a partnership exists. |

## Remarks

The following table lists the supported attributes.

| Attribute | Description |
| --- | --- |
| AutoSyncDefaultRules | Specifies whether automatic synchronization is done according to default rules or custom rules. A value of "true" specifies default rules, and a value of "false" specifies custom rules.<br><br>Use of this attribute is permitted only for devices with which Windows Media Player has a partnership.<br><br>Requires Windows Media Player 12. |
| BackgroundSyncState | Specifies whether Windows Media Player is allowed to perform background operations for the device.<br><br>The value can be a string (**BSTR**) representation of a bitwise combination of one or more of the following flags.<br><br>* 1 Allow background synchronization.<br>* 2 Allow background transcoding.<br><br>The value can also be one of the following strings.<br><br>* "0" No background operations are allowed.<br>* "255" Allow all background operations.<br><br>The value of this attribute lasts for the lifetime of Windows Media Player, but is not stored in the Windows Media Player library.<br><br>Use of this attribute is permitted only for devices with which Windows Media Player has a partnership.<br><br>Requires Windows Media Player 12. |
| IncludeSkippedFiles | When the user deletes files from the device, Windows Media Player marks those files as skipped and does not include them in future synchronization operations. Setting this attribute instructs Windows Media Player to include skipped files in the next synchronization.<br><br>Set the value of this attribute to the empty **BSTR**.<br><br>Use of this attribute is permitted only for devices with which Windows Media Player has a partnership.<br><br>Requires Windows Media Player 12. |
| PercentSpaceReserved | Limits the amount of device storage that Windows Media Player uses for file synchronization by specifying a portion of the storage as reserved. The value is a numeric percentage of total storage on the device represented by a string (**BSTR**). Supported values range from "0" to "95".<br><br>Use of this attribute is permitted only for devices with which Windows Media Player has a partnership. |
| SyncFilter | Specifies the types of files that will be synchronized during the next synchronization session, and specifies whether content can be acquired from the device during that synchronization session.<br><br>The value can be a string (BSTR) representation of a bitwise combination of one or more of the following flags.<br><br>* 1 Synchronize music files.<br>* 2 Synchronize video files.<br>* 4 Synchronize picture files.<br>* 8 Content can be written to the device, but cannot be acquired from the device.<br><br>For example, the string "5" specifies that music and picture files will be synchronized.<br><br>The value can also be one of the following strings.<br><br>* "0xFF" Apply no filter to the synchronization session. That is, synchronize all types of files and allow content to be both written to the device and acquired from the device.<br>* "0x07" Synchronize files of all types.<br><br>This attribute affects only the next synchronization session.<br><br>Use of this attribute is permitted only for devices with which Windows Media Player has a partnership.<br><br>Requires Windows Media Player 12. |
| SyncOnConnect | Specifies whether Windows Media Player should synchronize the device when the device gets connected. The value "true" specifies that Windows Media Player should synchronize the device, and the value "false" specifies that Windows Media Player should not synchronize the device.<br><br>Use of this attribute is permitted only for devices with which Windows Media Player has a partnership.<br><br>Requires Windows Media Player 12. |

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPSyncDevice2 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsyncdevice2)