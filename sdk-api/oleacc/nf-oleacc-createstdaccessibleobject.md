# CreateStdAccessibleObject function

## Description

Creates an accessible object with the methods and properties of the specified type of system-provided user interface element.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Window handle of the system-provided user interface element (a control) for which an accessible object is created.

### `idObject` [in]

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Object ID. This value is usually [OBJID_CLIENT](https://learn.microsoft.com/windows/desktop/WinAuto/object-identifiers), but it may be another object identifier.

### `riid` [in]

Type: **REFIID**

Reference identifier of the requested interface. This value is one of the following: IID_IAccessible, IID_IDispatch, IID_IEnumVARIANT, or IID_IUnknown.

### `ppvObject` [out]

Type: **void****

Address of a pointer variable that receives the address of the specified interface.

## Return value

Type: **STDAPI**

If successful, returns S_OK.

If not successful, returns a standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values).

## Remarks

Server applications call this function when they contain a custom UI object that is similar to a system-provided object. Server developers can call **CreateStdAccessibleObject** to override the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) methods and properties as required to match their custom objects. Alternatively, server developers can use Dynamic Annotation to override specific properties without having to use difficult subclassing techniques that **CreateStdAccessibleObject** requires. Server developers should still use **CreateStdAccessibleObject** for structural changes, such as hiding a child element or creating a placeholder child element. This approach saves server developers the work of fully implementing all of the **IAccessible** properties and methods.

This function is similar to [CreateStdAccessibleProxy](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-createstdaccessibleproxya), except that **CreateStdAccessibleProxy** allows you to specify the class name as a parameter whereas **CreateStdAccessibleObject** uses the class name associated with the *hwnd* parameter.

## See also

[CreateStdAccessibleProxy](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-createstdaccessibleproxya)

[IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface)

[Shortcuts for Exposing Custom User Interface Elements](https://learn.microsoft.com/windows/desktop/WinAuto/shortcuts-for-exposing-custom-user-interface-elements)