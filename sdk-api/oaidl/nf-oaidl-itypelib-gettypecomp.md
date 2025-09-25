# ITypeLib::GetTypeComp

## Description

Enables a client compiler to bind to the types, variables, constants, and global functions for a library.

## Parameters

### `ppTComp` [out]

The [ITypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypecomp) instance for this [ITypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypelib). A client compiler uses the methods in the **ITypeComp** interface to bind to types in **ITypeLib**, as well as to the global functions, variables, and constants defined in **ITypeLib**

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The [Bind](https://learn.microsoft.com/windows/desktop/api/oaidl/nf-oaidl-itypecomp-bind) function of the returned **TypeComp** binds to global functions, variables, constants, enumerated values, and coclass members. The **Bind** function also binds the names of the TYPEKIND enumerations of TKIND_MODULE, TKIND_ENUM, and TKIND_COCLASS. These names shadow any global names defined within the type information. The members of TKIND_ENUM, TKIND_MODULE, and TKIND_COCLASS types marked as Application objects can be directly bound to from [ITypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypecomp) without specifying the name of the module.

[ITypeComp::Bind](https://learn.microsoft.com/windows/desktop/api/oaidl/nf-oaidl-itypecomp-bind) and [ITypeComp::BindType](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypecomp-bindtype) accept only unqualified names. **ITypeLib::GetTypeComp** returns a pointer to the [ITypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypecomp) interface, which is then used to bind to global elements in the library. The names of some types (TKIND_ENUM, TKIND_MODULE, and TKIND_COCLASS) share the name space with variables, functions, constants, and enumerators.

If a member requires qualification to differentiate it from other items in the name space, **GetTypeComp** can be called successively for each qualifier in order to bind to the desired member. This allows programming language compilers to access members of modules, enumerations, and coclasses, even though the member can't be bound to with a qualified name.

## See also

[ITypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypelib)