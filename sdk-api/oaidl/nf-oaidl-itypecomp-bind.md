# ITypeComp::Bind

## Description

Maps a name to a member of a type, or binds global variables and functions contained in a type library.

## Parameters

### `szName` [in]

The name to be bound.

### `lHashVal` [in]

The hash value for the name computed by [LHashValOfNameSys](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-lhashvalofnamesys).

### `wFlags` [in]

One or more of the flags defined in the INVOKEKIND enumeration. Specifies whether the name was referenced as a method or a property. When binding to a variable, specify the flag INVOKE_PROPERTYGET. Specify zero to bind to any type of member.

### `ppTInfo` [out]

If a FUNCDESC or VARDESC was returned, then *ppTInfo* points to a pointer to the type description that contains the item to which it is bound.

### `pDescKind` [out]

Indicates whether the name bound to is a VARDESC, FUNCDESC, or TYPECOMP. If there was no match, DESCKIND_NONE.

### `pBindPtr` [out]

The bound-to VARDESC, FUNCDESC, or [ITypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypecomp) interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

Use **Bind** for binding to the variables and methods of a type, or for binding to the global variables and methods in a type library. The returned DESCKIND pointer *pDescKind* indicates whether the name was bound to a VARDESC, a FUNCDESC, or to an [ITypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypecomp) instance. The returned *pBindPtr* points to the VARDESC, FUNCDESC, or **ITypeComp**.

If a data member or method is bound to, then ppTInfopoints to the type description that contains the method or data member.

If **Bind** binds the name to a nested binding context, it returns a pointer to an [ITypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypecomp) instance in *pBindPtr* and a null type description pointer in *ppTInfo*. For example, if the name of a type description is passed for a module (TKIND_MODULE), enumeration (TKIND_ENUM), or coclass (TKIND_COCLASS), Bind returns the **ITypeComp** instance of the type description for the module, enumeration, or coclass. This feature supports languages such as Visual Basic that allow references to members of a type description to be qualified by the name of the type description. For example, a function in a module can be referenced by *modulename*.*functionname.*

The members of TKIND_ENUM, TKIND_MODULE, and TKIND_COCLASS types marked as Application objects can be bound to directly from [ITypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypecomp), without specifying the name of the module. The **ITypeComp** of a coclass defers to the **ITypeComp** of its default interface.

As with other methods of [ITypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypecomp), [ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo), and **ITypeInfo**, the calling code is responsible for releasing the returned object instances or structures. If a VARDESC or FUNCDESC is returned, the caller is responsible for deleting it with the returned type description and releasing the type description instance itself. Otherwise, if an **ITypeComp** instance is returned, the caller must release it.

Special rules apply if you call a type library's **Bind** method, passing it the name of a member of an Application object class (a class that has the TYPEFLAG_FAPPOBJECT flag set). In this case, Bind returns DESCKIND_IMPLICITAPPOBJ in *pDescKind*, a VARDESC that describes the Application object in *pBindPtr*, and the [ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo) of the Application object class in *ppTInfo*. To bind to the object, [ITypeInfo::GetTypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypeinfo-gettypecomp) must make a call to get the [ITypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypecomp) of the Application object class, and then reinvoke its **Bind** method with the name initially passed to the type library's **ITypeComp**.

The caller should use the returned [ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo) pointer (*ppTInfo*) to get the address of the member.

**Note** The *wflags* parameter is the same as the *wflags* parameter in [IDispatch::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke).

## See also

[ITypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypecomp)