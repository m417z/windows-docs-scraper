# KsGetPinFromFileObject function

## Description

The **KsGetPinFromFileObject** function returns the AVStream pin object associated with *FileObject*.

## Parameters

### `FileObject` [in]

A pointer to the [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure for which to return the associated AVStream pin object.

## Return value

**KsGetPinFromFileObject** returns a pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure associated with *FileObject*.

## Remarks

The minidriver must verify that *FileObject* is a file object associated with an AVStream pin. Do this by calling [KsGetObjectTypeFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetobjecttypefromfileobject).

This call is an inline call to [KsGetObjectFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetobjectfromfileobject). **KsGetPinFromFileObject** typecasts the return as a PKSPIN.

## See also

[KsGetObjectFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetobjectfromfileobject)

[KsGetObjectTypeFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetobjecttypefromfileobject)