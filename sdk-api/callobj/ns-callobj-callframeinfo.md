# CALLFRAMEINFO structure

## Description

Provides information about a call frame such as the method in the call frame, if it has in, out, or in/out parameters, the number of [in], [out], or [in, out] interfaces, the interface ID, the number of methods in the interface and the number of parameters in this method.

## Members

### `iMethod`

The method number within the interface in question.

### `fHasInValues`

**TRUE** if there are any [in] parameters in the method; otherwise, **FALSE**.

### `fHasInOutValues`

**TRUE** if there are any [in, out] parameters in the method; otherwise, **FALSE**.

### `fHasOutValues`

**TRUE** if there are any out parameters other than **HRESULT** or **void** return values in the method; otherwise, **FALSE**.

### `fDerivesFromIDispatch`

**TRUE** if the interface is derived from **IDispatch**; otherwise, **FALSE**.

### `cInInterfacesMax`

If this parameter has a value greater or equal to 0, then the value is an absolute upper bound on the number [in] interfaces. If this parameter is less than 0, then the method may have an unbounded number of [in] interfaces. If this parameter is equal to 0, then there are no [in] interfaces.

### `cInOutInterfacesMax`

If this parameter has a value greater or equal to 0, then the value is an absolute upper bound on the number [in, out] interfaces. If this parameter is less than 0, then the method may have an unbounded number of [in, out] interfaces. If this parameter is equal to 0, then there are no [in, out] interfaces.

### `cOutInterfacesMax`

If this parameter has a value greater or equal to 0, then the value is an absolute upper bound on the number [out] interfaces. If this parameter is less than 0, then the method may have an unbounded number of [out] interfaces. If this parameter is equal to 0, then there are no [out] interfaces.

### `cTopLevelInInterfaces`

The number of parameters that are in interface pointers.

### `iid`

The interface ID.

### `cMethod`

The number of methods in **iid**.

### `cParams`

The number of parameters in **imethod**. The receiver is excluded.

## See also

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)

[ICallIndirect](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallindirect)