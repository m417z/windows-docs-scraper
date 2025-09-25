# ITypeChangeEvents::AfterTypeChange

## Description

Raised after a type has been changed.

## Parameters

### `changeKind` [in]

The type of change.

#### CHANGEKIND_ADDMEMBER

#### CHANGEKIND_DELETEMEMBER

#### CHANGEKIND_SETNAMES

#### CHANGEKIND_SETDOCUMENTATION

#### CHANGEKIND_GENERAL

#### CHANGEKIND_INVALIDATE

#### CHANGEKIND_CHANGEFAILED

### `pTInfoAfter` [in]

An object that implements the [ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo), [ITypeInfo2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo2), [ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo), or [ICreateTypeInfo2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo2) interface and that contains the type information before the change was made. The client subscribes to this object to receive notifications about any changes.

### `pStrName` [in]

The name of the change. This value may be null.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## See also

[ITypeChangeEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypechangeevents)