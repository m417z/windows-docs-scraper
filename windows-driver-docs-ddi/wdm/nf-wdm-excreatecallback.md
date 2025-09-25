# ExCreateCallback function

## Description

The **ExCreateCallback** routine either creates a new callback object or opens an existing callback object on behalf of the caller.

## Parameters

### `CallbackObject` [out]

A pointer to a location that receives a pointer to a callback object, which is an opaque, system structure. If the **ExCreateCallback** call succeeds, the routine writes the address of the newly created or opened callback object to this location. The callback object pointer obtained from this routine can be supplied as a parameter to the [ExRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exregistercallback) or [ExNotifyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exnotifycallback) routine.

### `ObjectAttributes` [in]

A pointer to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that contains the callback object's attributes. This structure was previously initialized by the [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) routine.

### `Create` [in]

Whether to create a callback object. Set to **TRUE** to create a new callback object if the requested object cannot be opened. Otherwise, set to **FALSE**.

### `AllowMultipleCallbacks` [in]

Whether a newly created callback object should allow multiple registered callback routines. Set to **TRUE** to allow multiple registered callback routines. Otherwise, set to **FALSE**. This parameter is ignored when *Create* is **FALSE** or when opening an existing object.

## Return value

**ExCreateCallback** returns STATUS_SUCCESS if a callback object was opened or created. Otherwise, it returns an NTSTATUS error code to indicate the nature of the failure.

## Remarks

A driver calls **ExCreateCallback** to create a new callback object or to open an existing callback object. After the object has been created or opened, other components can call the [ExRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exregistercallback) routine to register callback routines with the callback object.

Before calling **ExCreateCallback**, the driver must call [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) to initialize the [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure for the callback object. Unnamed callback objects are not permitted. The caller must specify a name for the object; otherwise, the call fails with STATUS_UNSUCCESSFUL. The caller should specify the OBJ_PERMANENT attribute in the callback object to prevent the object from being deleted before it can be registered with the object manager. The caller should also specify any other attributes, such as OBJ_CASE_INSENSITIVE, that might be needed.

When all operations have been completed with the callback object, the driver must delete the object to prevent a memory leak. For information about deleting an object that was created with the OBJ_PERMANENT object attribute, see [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject).

The following table shows the callback objects that the operating system creates for use by drivers.

| Callback object name | Usage |
| --- | --- |
| \Callback\SetSystemTime | The operating system calls any callback routines registered for this object whenever the system time changes. |
| \Callback\PowerState | The operating system calls any callback routines registered for this object whenever certain system power characteristics change. When a driver registers for callback notification (by calling **ExRegisterCallback**), it can specify the changes for which it should be notified. |

For more information about callback objects, see [Callback Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/callback-objects).

## See also

[ExNotifyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exnotifycallback)

[ExRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exregistercallback)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)