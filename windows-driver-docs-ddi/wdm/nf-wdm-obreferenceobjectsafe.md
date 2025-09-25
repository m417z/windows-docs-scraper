# ObReferenceObjectSafe function

## Description

The ObReferenceObjectSafe function increments the reference count for an object and determines if it is safe to use the object. It returns FALSE if the object is being deleted or TRUE if it's safe to use the object further.

## Parameters

### `Object`

Supplies a pointer to the object whose reference count is incremented.

## Return value

ObReferenceObjectSafe returns one of the following values:

Return Value|Meaning
---|--
TRUE |The object was successfully referenced and safe to use.
FALSE |The object is being deleted.

## Remarks

## See also

- [ObReferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobject)
- [ObReferenceObjectWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectwithtag)
- [ObReferenceObjectByPointerWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbypointerwithtag)
- [ObReferenceObjectByPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbypointer)