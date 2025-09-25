# FltGetFilterFromInstance function

## Description

The **FltGetFilterFromInstance** routine returns an opaque filter pointer for the minifilter driver that created the given instance.

## Parameters

### `Instance` [in]

Opaque instance pointer for the instance.

### `RetFilter` [out]

Pointer to a caller-allocated variable that receives an opaque filter pointer for the minifilter driver. This parameter is required and cannot be **NULL**.

## Return value

**FltGetFilterFromInstance** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_DELETING_OBJECT** | The minifilter driver is being torn down. This is an error code. |

## Remarks

**FltGetFilterFromInstance** adds a rundown reference to the opaque filter pointer returned in the *RetFilter* parameter. When this pointer is no longer needed, the caller must release it by calling [FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference). Thus every successful call to **FltGetFilterFromInstance** must be matched by a subsequent call to **FltObjectDereference**.

To get an opaque volume pointer for the volume to which a given minifilter driver instance is attached, call [FltGetVolumeFromInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefrominstance).

To enumerate all instances of a given minifilter driver, call [FltEnumerateInstanceInformationByFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyfilter).

To enumerate instances of all minifilter drivers on all volumes, call [FltEnumerateInstances](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstances).

## See also

[FltEnumerateInstanceInformationByFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyfilter)

[FltEnumerateInstances](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstances)

[FltGetVolumeFromInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefrominstance)

[FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference)