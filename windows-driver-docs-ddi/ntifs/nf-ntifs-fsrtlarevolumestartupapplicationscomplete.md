# FsRtlAreVolumeStartupApplicationsComplete function

## Description

The **FsRtlAreVolumeStartupApplicationsComplete** function determines whether volume startup applications have completed processing.

## Return value

**FsRtlAreVolumeStartupApplicationsComplete** returns **TRUE** if all volume startup applications for the system have completed their startup processing, **FALSE** otherwise.

## Remarks

The **FsRtlAreVolumeStartupApplicationsComplete** function returns **TRUE** if session manager (*Smss.exe*) has completed running all startup applications for the system volume(s), **FALSE** otherwise.

You can use this information to modify the behavior of file system drivers. For example, a file system driver can adversely affect *Autochk.exe* if the driver starts its processing before *Autochck.exe* has fully completed. If **FsRtlAreVolumeStartupApplicationsComplete** returns **TRUE**, *Autochk.exe* is guaranteed to have fully completed.

To retrieve information about the volume that a minifilter instance is attached to, see [**FltQueryVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation).

To retrieve information about the volume associated with a given file, directory, or storage device, see [**ZwQueryVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwqueryvolumeinformationfile).

## See also

[**FltQueryVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation)

[**ZwQueryVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwqueryvolumeinformationfile)