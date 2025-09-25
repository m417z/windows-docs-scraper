# KsGetObjectTypeFromFileObject function

## Description

The **KsGetObjectTypeFromFileObject** function returns the AVStream object type that is associated with a given file object.

## Parameters

### `FileObject` [in]

A pointer to the [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure for which to determine the associated AVStream object type.

## Return value

**KsGetObjectTypeFromFileObject** returns the object type of the AVStream object associated with *FileObject* as a [KSOBJECTTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksobjecttype) enumeration. This can be one of the following: **KsObjectTypeDevice**, **KsObjectTypeFilterFactory**, **KsObjectTypeFilter**, or **KsObjectTypePin**.

## Remarks

The **KsGetObjectTypeFromFileObject** function does not check that the file object is associated with a KS object. If it is not, this may result in a memory access error. Driver developers should consider using structured exception handling to catch a possible exception.

## See also

[KsGetFilterFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetfilterfromfileobject)

[KsGetObjectFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetobjectfromfileobject)

[KsGetPinFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetpinfromfileobject)

[KsPinGetConnectedPinFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetconnectedpinfileobject)