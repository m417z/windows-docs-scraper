# SysmonFileType enumeration

## Description

Determines the format in which the counter data is saved to a file.

## Constants

### `sysmonFileHtml:1`

Saves the control's property settings, list of counters, and counter data as HTML to a file. If the source of the counter data is a log file, the counter data is not saved.

### `sysmonFileReport:2`

Saves the counter data displayed in the report view as tab-separated data to a file. If the counter data is displayed in the graph view, only the last sampled counter data is saved to the file.

### `sysmonFileCsv:3`

Saves the counter data as comma-separated data to a file.

### `sysmonFileTsv:4`

Saves the counter data as tab-separated data to a file.

### `sysmonFileBlg:5`

Saves the counter data as binary data to a file.

### `sysmonFileRetiredBlg:6`

Saves the counter data in the Windows 2000 binary format to a file.

### `sysmonFileGif:7`

Saves the image of the System Monitor control to a file. The image does not include the toolbar, if enabled.

## See also

[SystemMonitor.Relog](https://learn.microsoft.com/windows/desktop/SysMon/systemmonitor-relog)

[SystemMonitor.SaveAs](https://learn.microsoft.com/windows/desktop/SysMon/systemmonitor-saveas)