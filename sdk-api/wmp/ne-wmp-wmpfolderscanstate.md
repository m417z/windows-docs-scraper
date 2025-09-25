# WMPFolderScanState enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMPFolderScanState** enumeration type defines the possible operational states of Windows Media Player as it monitors file folders for digital media content.

## Constants

### `wmpfssUnknown:0`

Not a valid state.

### `wmpfssScanning`

Scanning folders.

### `wmpfssUpdating`

Updating the library.

### `wmpfssStopped`

Folder monitoring is stopped.

## Remarks

A scanning operation consists of two phases: scanning and updating. During the first phase, Windows Media Player determines which digital media files to add to the library. During the second phase, the Player adds the files. You can determine the current scan state by calling **IWMPFolderMonitorServices::get_scanState** or by handling the **FolderScanStateChange** event.

Windows Media Player 10 Mobile: This enumeration is not supported.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/WMP/enumeration-types)

[IWMPEvents3::FolderScanStateChange](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpevents3-folderscanstatechange)

[IWMPFolderMonitorServices::get_scanState](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpfoldermonitorservices-get_scanstate)