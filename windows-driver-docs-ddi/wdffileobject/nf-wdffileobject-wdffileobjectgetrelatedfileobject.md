# WdfFileObjectGetRelatedFileObject function

## Description

[Applies to UMDF only]

The **WdfFileObjectGetRelatedFileObject** method retrieves the related file object to a framework file object.

## Parameters

### `FileObject` [in]

A handle to a framework file object.

## Return value

**WdfFileObjectGetRelatedFileObject** returns a handle to the related file object to a framework file object.

## Remarks

Use of related file objects is technology-specific. For example, [kernel streaming](https://learn.microsoft.com/windows-hardware/drivers/stream/kernel-streaming) uses related file objects to represent the parent filters of child pins.

For more information about related file objects, see the [GetRelatedFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdffile2-getrelatedfileobject) member of the kernel-mode [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure.

## See also

[WdfFileObjectGetFileName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffileobject/nf-wdffileobject-wdffileobjectgetfilename)