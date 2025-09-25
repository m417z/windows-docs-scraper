# KsGetObjectFromFileObject function

## Description

The **KsGetObjectFromFileObject** function returns the AVStream object cast to PVOID from *FileObject*.

## Parameters

### `FileObject` [in]

A pointer to the [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure for which to determine the associated AVStream object.

## Return value

**KsGetObjectFromFileObject** returns a pointer to the AVStream object associated with *FileObject* (cast to PVOID). For example, this pointer may point to a [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) or a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin).

## Remarks

The **KsGetObjectFromFileObject** function does not check that the file object is associated with a KS object. If it is not, this may result in a memory access error. Driver developers should consider using structured exception handling to catch a possible exception.

## See also

[KsGetFilterFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetfilterfromfileobject)

[KsGetObjectTypeFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetobjecttypefromfileobject)

[KsGetPinFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetpinfromfileobject)

[KsPinGetConnectedPinFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetconnectedpinfileobject)