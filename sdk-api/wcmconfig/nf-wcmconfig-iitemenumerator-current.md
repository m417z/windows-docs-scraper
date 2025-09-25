# IItemEnumerator::Current

## Description

Retrieves an item from the current position of the enumerator.

## Parameters

### `Item` [out]

A variant that contains the key value for the collection. For most collections, the key is the name of the item.

## Return value

This method returns an HRESULT value. **S_OK** indicates success.

## Remarks

**Note** When the item is no longer required, call [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) to free the resources associated with the item.

## See also

[IItemEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-iitemenumerator)