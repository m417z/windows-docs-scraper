# ISdoMachine::GetServiceSDO

## Description

The **GetServiceSDO** method retrieves a
Server Data Object (SDO) for the specified service.

## Parameters

### `eDataStore` [in]

Specifies a value from the [IASDATASTORE](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-iasdatastore) enumeration
type.

### `bstrServiceName` [in]

Specifies a
[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr) that contains the service
name. This parameter is one of the following values.

#### "IAS"

Network Policy Server

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server starting with
Windows Server 2008.

#### "RemoteAccess"

Remote Access Server

### `ppServiceSDO` [out]

Pointer to a pointer that points to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface
pointer. Use the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method of this
**IUnknown** interface to obtain an
[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface for the
[ISdoServiceControl](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdoservicecontrol) object.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## Remarks

Before calling this method, use the
[ISdoMachine::Attach](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-attach) method to attach to the SDO
computer.

None of the parameters for this method can be **NULL**.

## See also

[ISdoMachine](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdomachine)

[ISdoMachine::Attach](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-attach)

[Retrieving a Service SDO](https://learn.microsoft.com/windows/desktop/Nps/sdo-retrieving-a-service-sdo)