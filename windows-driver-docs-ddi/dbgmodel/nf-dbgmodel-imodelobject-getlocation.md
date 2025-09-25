# IModelObject::GetLocation

## Description

The GetLocation method will return the location of the native object. While such a location is typically a virtual address within the address space of the debug target, it is not necessarily so. The location returned by this method is an abstract location that may be a virtual address, may indicate placement within a register or sub-register, or may indicate some other arbitrary address space as defined by the debug host. If the HostDefined field of the resulting Location object is 0, it indicates that the location is actually a virtual address. Such virtual address may be retrieved by examining the Offset field of the resulting location. Any non-zero value of the HostDefined field indicates an alternate address space where the Offset field is the offset within that address space. The exact meaning of non-zero HostDefined values here are private to the debug host.

If the [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) on which this method is called is not a native construct with a location in some abstract address space of the debug target, this method will return E_FAIL.

## Parameters

### `location`

The abstract location of the native object represented by the this pointer will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

In this sample, the [Location structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/ns-dbgmodel-location) defines the location for an object.

```cpp
ComPtr<IModelObject> spObject; /* get a native object */

Location loc;
if (SUCCEEDED(spObject->GetLocation(&loc)))
{
    if (loc.IsVirtualAddress()) /* or loc.HostDefined == 0 */
    {
        // The object is in memory at an address specified by Offset
        ULONG64 address = loc.Offset;
    }
    else
    {
        // The object is in some abstract "address space" (e.g.: it's enregistered).
        // Arithmetic can still be used on the 'Offset' field in order to access
        // sub-objects within the abstract "address space"
    }
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)