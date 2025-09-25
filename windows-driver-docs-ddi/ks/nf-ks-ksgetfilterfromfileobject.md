# KsGetFilterFromFileObject function

## Description

The **KsGetFilterFromFileObject** function returns the AVStream filter object associated with *FileObject*.

## Parameters

### `FileObject` [in]

A pointer to the [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) for which to return the associated AVStream filter object.

## Return value

**KsGetFilterFromFileObject** returns a pointer to the [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure associated with *FileObject*.

## Remarks

It is the responsibility of the minidriver to verify that *FileObject* is a file object associated with an AVStream filter. Do this by calling [KsGetObjectTypeFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetobjecttypefromfileobject) before calling **KsGetFilterFromFileObject**.

**KsGetFilterFromFileObject** is an inline call to [KsGetObjectFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetobjectfromfileobject). The difference is that **KsGetFilterFromFileObject** typecasts the return as type pointer to a [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure.

## See also

[KsGetDeviceForDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetdevicefordeviceobject)

[KsGetObjectFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetobjectfromfileobject)

[KsGetObjectTypeFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetobjecttypefromfileobject)