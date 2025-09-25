# IPortClsVersion::GetVersion

## Description

The `GetVersion` method returns the version of the Windows operating system that the driver is running on.

## Return value

The `GetVersion` method returns a DWORD value that specifies the Windows version number. For more information, see the following Remarks section.

## Remarks

The `GetVersion` method returns version information that specifies the Windows release.

The possible Windows version numbers that `GetVersion` can return are shown in the following table.

| Version Number | Windows Version | Supports |
|----------------|-----------------|----------|
|**kVersionWin98**|Windows 98|no|
|**kVersionWin98SE**|Windows 98 Second Edition|no|
|**kVersionWin2K**|Windows 2000|no|
|**kVersionWin98SE_QFE2**|Windows 98 SE + Hot-Fix Package 269601.)|no|
|**kVersionWin2K_SP2**|Windows 2000 + Service Pack 2|YES|
|**kVersionWinME**|Windows Me|no|
|**kVersionWin98SE_QFE3**|Reserved for future use|YES|
|**kVersionWinME_QFE1**|Reserved for future use|YES|
|**kVersionWinXP**|Windows XP|YES|
|**kVersionWinXPSP1**|Windows XP + Service Pack 1|YES|
|**kVersionWinServer2003**|Windows Server 2003|YES|
|**kVersionWin2K_UAAQFE**|Windows 2000 + hot-fix package with IUnregister_Xxx_ support (See [Dynamic Audio Subdevices](https://learn.microsoft.com/windows-hardware/drivers/audio/dynamic-audio-subdevices).)|YES|
|**kVersionWinXP_UAAQFE**|Windows XP + hot-fix package with IUnregister_Xxx_ support (See [Dynamic Audio Subdevices](https://learn.microsoft.com/windows-hardware/drivers/audio/dynamic-audio-subdevices).)|YES|
|**kVersionWinServer2003_UAAQFE**|Windows Server 2003 + hot-fix package with IUnregister_Xxx_ support (See [Dynamic Audio Subdevices](https://learn.microsoft.com/windows-hardware/drivers/audio/dynamic-audio-subdevices).)|YES|

The version numbers in the preceding table are defined in header file portcls.h. Note that portcls.h defines version numbers both for Windows versions that do and do not support the **IPortClsVersion** interface. Both types of version number can be useful. A miniport driver typically contains a proprietary routine that determines the Windows version and can return any of the version numbers in the preceding table. When executed on a platform that does not support **IPortClsVersion**, this routine needs to use other software tests to determine the Windows version. These tests typically rely on the [IoIsWdmVersionAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioiswdmversionavailable) function. For a code example of such a routine, see the sb16 sample audio driver in the Windows Driver Kit (WDK).

The version numbers in the preceding table are listed in roughly chronological order. Each successive Windows version in the table does not necessarily represent a feature superset of the preceding version. For example, the version that is represented by **kVersionWin2K** has more audio features than the version that is represented by **kVersionWin98SE_QFE2**.

## See also

[IPortClsVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportclsversion)

[IoIsWdmVersionAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioiswdmversionavailable)