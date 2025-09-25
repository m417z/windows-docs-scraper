# IProvideClassInfo::GetClassInfo

## Description

Retrieves a pointer to the [ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo) interface for the object's type information. The type information for an object corresponds to the object's [coclass](https://msdn.microsoft.com/) entry in a type library.

## Parameters

### `ppTI` [out]

A pointer to an [ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo) pointer variable that receives the interface pointer to the object's type information. The caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned interface pointer if this method returns successfully.

## Return value

This method can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | The address in *ppTI* is not valid. For example, it may be **NULL**. |

## Remarks

### Notes to Implementers

This method must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) before returning. If the object loads the type information from a type library, the type library itself will call **AddRef** in creating the pointer.

Because the caller cannot specify a locale identifier (LCID) when calling this method, this method must assume the neutral language, that is, LANGID_NEUTRAL, and use this value to determine what locale-specific type information to return.

This method must be implemented; E_NOTIMPL is not an acceptable return value.

## See also

[IProvideClassInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iprovideclassinfo)