# IVssDifferentialSoftwareSnapshotMgmt::QueryDiffAreasForVolume

## Description

The
**QueryDiffAreasForVolume**
method queries shadow copy storage areas in use by the volume.

## Parameters

### `pwszVolumeName` [in]

Name of the volume that contains shadow copy storage areas.

The name of the volume must be in one of the following formats and must include a trailing backslash (\\):

* The path of a mounted folder, for example, Y:\MountX\
* A drive letter, for example,
  D:\
* A volume GUID path of the form \\?\*Volume*{*GUID*}\ (where *GUID* identifies the volume)

### `ppEnum` [out]

The address of an [IVssEnumMgmtObject](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivssenummgmtobject) interface
pointer, which is initialized on return. Callers must release the interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully queried the shadow copy storage areas. |
| **E_ACCESSDENIED** | Caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_PROVIDER_VETO** | Provider error - the provider logged the error in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The returned [IVssEnumMgmtObject](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivssenummgmtobject) enumerator object will contain [VSS_DIFF_AREA_PROP](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ns-vsmgmt-vss_diff_area_prop) structures inside the [VSS_MGMT_OBJECT_UNION](https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-scmp/63b53947-2649-4eac-a883-498f77361396) union inside the [VSS_MGMT_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ns-vsmgmt-vss_mgmt_object_prop) structure.

## See also

[IVssDifferentialSoftwareSnapshotMgmt](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt)

[IVssEnumMgmtObject](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivssenummgmtobject)