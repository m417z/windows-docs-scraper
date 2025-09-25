# ISdoMachine::GetUserSDO

## Description

The **GetUserSDO** method retrieves an interface
to the Server Data Object (SDO) for the specified user.

## Parameters

### `eDataStore` [in]

Specifies a value from the [IASDATASTORE](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-iasdatastore) enumeration
type.

### `bstrUserName` [in]

Specifies a [BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr) that contains
the name of the user. The name can be in Lightweight Directory Access Protocol (LDAP) format, or in Security
Accounts Manager (SAM) format.

### `ppUserSDO` [out]

Pointer to a pointer that points to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface
pointer. Use the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method of this
**IUnknown** interface to obtain an
[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface to an
[ISdo](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdo) object for the specified user.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## Remarks

Before calling this method, use the
[ISdoMachine::Attach](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-attach) method to attach to the SDO
computer.

If the SDO computer has a directory, then the
**ISdoMachine::GetUserSDO** automatically uses the
**DATA_STORE_DIRECTORY** value of
[IASDATASTORE](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-iasdatastore) instead of
**DATA_STORE_LOCAL**.

None of the parameters can be **NULL**.

## See also

[ISdoMachine](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdomachine)

[ISdoMachine::Attach](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-attach)

[Retrieving a User SDO](https://learn.microsoft.com/windows/desktop/Nps/sdo-retrieving-a-user-sdo)

[USERPROPERTIES](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-userproperties)