# FltAttachVolume function

## Description

**FltAttachVolume** creates a new minifilter driver instance and attaches it to the given volume.

## Parameters

### `Filter` [in, out]

Opaque filter pointer for the caller. This parameter is required and cannot be **NULL**.

### `Volume` [in, out]

Opaque volume pointer for the volume that the minifilter driver instance is to be attached to. This parameter is required and cannot be **NULL**.

### `InstanceName` [in, optional]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure containing the instance name for the new instance. This parameter is optional and can be **NULL**. If it is **NULL**, **FltAttachVolume** attempts to read the minifilter driver's default instance name from the registry. (For more information about this parameter, see the following Remarks section.)

### `RetInstance` [out]

Pointer to a caller-allocated variable that receives an opaque instance pointer for the newly created instance. This parameter is optional and can be **NULL**.

## Return value

**FltAttachVolume** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_DELETING_OBJECT** | The specified *Filter* or *Volume* is being torn down. This is an error code. |
| **STATUS_FLT_FILTER_NOT_READY** | The minifilter driver has not started filtering. For more information, see [FltStartFiltering](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltstartfiltering). This is an error code. |
| **STATUS_FLT_INSTANCE_NAME_COLLISION** | An instance already exists with this name on the volume specified. |
| **STATUS_INSUFFICIENT_RESOURCES** | **FltAttachVolume** encountered a pool allocation failure. This is an error code. |
| **STATUS_OBJECT_NAME_COLLISION** | Another instance was already attached at the altitude specified in the instance attributes that were read from the registry. This is an error code. |

## Remarks

If the caller specifies a non-**NULL** value for *InstanceName*, **FltAttachVolume** reads any instance attributes specified by the minifilter driver that are stored in the registry under HKLM\CurrentControlSet\Services\\*ServiceName*\Instances\InstanceName, where *ServiceName* is the minifilter driver's service name. This service name is specified in the [AddService directive](https://learn.microsoft.com/windows-hardware/drivers/install/inf-addservice-directive) in the [DefaultInstall.Services section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-defaultinstall-services-section) of the minifilter driver's INF file. (For more information about filter driver INF files, see [Installing a File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/installing-a-file-system-filter-driver).)

If the caller does not specify a value for *InstanceName*, **FltAttachVolume** uses the name stored in the registry under HKLM\CurrentControlSet\Services\\*ServiceName*\Instances\DefaultInstance for the *InstanceName* portion of the registry path.

The instance name specified in the *InstanceName* parameter is required to be unique across the system.

**FltAttachVolume** returns an opaque instance pointer for the new instance in **RetInstance*. This pointer value uniquely identifies the minifilter driver instance and remains constant as long as the instance is attached to the volume.

**FltAttachVolume** adds a rundown reference to the opaque instance pointer returned in **RetInstance*. When this pointer is no longer needed, the caller must release it by calling [FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference). Thus every successful call to **FltAttachVolume** must be matched by a subsequent call to **FltObjectDereference**.

To attach a minifilter driver instance to a volume at a given altitude, call [FltAttachVolumeAtAltitude](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltattachvolumeataltitude).

To compare the altitudes of two minifilter driver instances attached to the same volume, call [FltCompareInstanceAltitudes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompareinstancealtitudes).

To detach a minifilter driver instance from a volume, call [FltDetachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdetachvolume).

## See also

[FltAttachVolumeAtAltitude](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltattachvolumeataltitude)

[FltCompareInstanceAltitudes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompareinstancealtitudes)

[FltDetachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdetachvolume)

[FltGetVolumeInstanceFromName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeinstancefromname)

[FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference)

[FltStartFiltering](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltstartfiltering)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)