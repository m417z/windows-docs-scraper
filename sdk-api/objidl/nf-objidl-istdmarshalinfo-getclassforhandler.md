# IStdMarshalInfo::GetClassForHandler

## Description

Retrieves the CLSID of the object handler to be used in the destination process during standard marshaling.

## Parameters

### `dwDestContext` [in]

The destination context, that is, the process in which the unmarshaling will be done. Possible values are taken from the enumeration [MSHCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-mshctx).

### `pvDestContext` [in]

This parameter must be **NULL**.

### `pClsid` [out]

A pointer to the handler's CLSID.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and S_OK.

## Remarks

### Notes to Implementers

Your implementation of **IStdMarshalInfo::GetClassForHandler** must return your own CLSID. This enables an object to be created by a different server.

## See also

[IStdMarshalInfo](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istdmarshalinfo)