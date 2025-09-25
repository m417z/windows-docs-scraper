# IPropertySetStorage::Enum

## Description

The **Enum** method creates an enumerator object which contains information on the property sets stored in this property set storage. On return, this method supplies a pointer to the
[IEnumSTATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ienumstatpropsetstg) pointer on the enumerator object.

## Parameters

### `ppenum` [out]

Pointer to
[IEnumSTATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ienumstatpropsetstg) pointer variable that receives the interface pointer to the newly created enumerator object.

## Return value

This method can return one of these values.

## Remarks

**IPropertySetStorage::Enum** creates an enumerator object that can be used to iterate through
[STATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropsetstg) structures. These sometimes provide information on the property sets managed by
[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage). This method, on return, supplies a pointer to the
[IEnumSTATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ienumstatpropsetstg) interface on this enumerator object on return.

## See also

[EnumAll Sample](https://learn.microsoft.com/windows/desktop/Stg/enumall-sample)

[IEnumSTATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ienumstatpropsetstg)

[IEnumSTATPROPSETSTG - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/ienumstatpropsetstg-compound-file-implementation)

[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage)

[Samples](https://learn.microsoft.com/windows/desktop/Stg/samples)