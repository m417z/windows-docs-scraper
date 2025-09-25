# IItemEnumerator::Reset

## Description

Resets the state of the enumerator to its initialized state. You must immediately follow **IItemEnumerator::Reset** with a call to [IItemEnumerator::MoveNext](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-iitemenumerator-movenext) on the enumerator in order to set the current pointer at the first position in the enumeration.

## Return value

This method returns an HRESULT value. **S_OK** indicates success.

## See also

[IItemEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-iitemenumerator)