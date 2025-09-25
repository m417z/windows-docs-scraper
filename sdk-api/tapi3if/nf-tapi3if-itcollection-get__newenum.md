# ITCollection::get__NewEnum

## Description

The
**get__NewEnum** method gets an enumerator for the collection.

## Parameters

### `ppNewEnum` [out]

Pointer to an
[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on an enumerator object for the collection.

Call the
[QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method on the returned **IUnknown** interface to obtain a pointer to an
[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) enumeration interface on the collection. **IEnumVARIANT** provides a number of methods that you can use to iterate through the collection.

For more information, see the following Remarks section.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

Each TAPI 3 interface that includes a method that returns a collection also includes a method that returns a pointer to a TAPI 3 enumerator interface. If you are programming in C/C++, it can be easier to call a collection's enumerator method directly to obtain an enumerator object, instead of calling the **ITCollection::get__NewEnum** method. For example, the
[ITTAPI::EnumerateAddresses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-enumerateaddresses) method returns a pointer to an
[IEnumAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumaddress) interface.
**IEnumAddress** provides enumeration methods for the
[Address object](https://learn.microsoft.com/windows/desktop/Tapi/address-object).

If you are programming in Visual Basic, you do not need to call this method to enumerate a collection. This is because you can invoke the method's functionality implicitly using the **For...Each...in...Next...** construct.

## See also

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)