# _WDF_FILEOBJECT_CLASS enumeration

## Description

[Applies to KMDF and UMDF]

The **WDF_FILEOBJECT_CLASS** enumeration defines values that identify whether a driver requires a framework file object to represent a file that an application or another driver is attempting to create or open. These values also specify where the framework can store the object's handle.

## Constants

### `WdfFileObjectInvalid:0`

Reserved for internal use.

### `WdfFileObjectNotRequired:1`

The driver does not require a framework file object.

### `WdfFileObjectWdfCanUseFsContext:2`

The driver requires a framework file object. The framework can store the object's handle in the **FsContext** member of the file's Windows Driver Model (WDM) [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure.

### `WdfFileObjectWdfCanUseFsContext2:3`

The driver requires a framework file object. The framework can store the object's handle in the **FsContext2** member of the file's WDM FILE_OBJECT structure.

### `WdfFileObjectWdfCannotUseFsContexts:4`

The driver requires a framework file object. The framework cannot store the object's handle in the **FsContext** or **FsContext2** member of the file's WDM FILE_OBJECT structure, because one or more drivers are using these members. Therefore, the framework must store the handle internally.

### `WdfFileObjectCanBeOptional:0x80000000`

The driver typically requires a framework file object, but the driver can also handle special situations in which a framework file object is missing or different. For more information about these situations, see the following Remarks section.

**WdfFileObjectCanBeOptional** is a bit flag that your driver can OR with the **WdfFileObjectWdfCanUseFsContext**, **WdfFileObjectWdfCanUseFsContext2**, or **WdfFileObjectWdfCannotUseFsContexts** enumerator value.

Most framework-based drivers do not use this bit flag.

The **WdfFileObjectCanBeOptional** value is available in version 1.9 and later versions of KMDF.

## Remarks

The **WDF_FILEOBJECT_CLASS** enumeration is used in the [WDF_FILEOBJECT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_fileobject_config) structure.

If your driver calls [WdfRequestGetFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetfileobject) to obtain framework file objects for I/O requests, and if you know that some of the WDM I/O request packets (IRPs) that your driver receives do not include WDM file objects, the driver can set the **WdfFileObjectCanBeOptional** bit flag.

If your driver sets the **WdfFileObjectWdfCanUseFsContext**, **WdfFileObjectWdfCanUseFsContext2**, or **WdfFileObjectWdfCannotUseFsContexts** value and does *not* set the **WdfFileObjectCanBeOptional** bit flag, [the framework's verifier](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-kmdf-verifier) reports an error for the following cases when the driver calls the [WdfRequestGetFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetfileobject) method:

* An IRP does not include a WDM file object.
* An IRP includes a WDM file object, but the file object is different from the one that the file creation IRP included.

If the **WdfFileObjectCanBeOptional** bit flag is set, the framework's verifier ignores such cases.

## See also

[FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)

[WDF_FILEOBJECT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_fileobject_config)