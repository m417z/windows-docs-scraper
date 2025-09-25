# ISdoMachine::GetDomainType

## Description

The **GetDomainType** retrieves the type of domain in which the SDO computer
resides.

## Parameters

### `eDomainType` [out]

Pointer to an [IASDOMAINTYPE](https://learn.microsoft.com/windows/win32/api/sdoias/ne-sdoias-iasdomaintype) variable that receives
the type of the domain in which the SDO computer resides.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## Remarks

Before calling this method, use the
[ISdoMachine::Attach](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-attach) method to attach to the SDO
computer.

## See also

[IASDOMAINTYPE](https://learn.microsoft.com/windows/win32/api/sdoias/ne-sdoias-iasdomaintype)

[ISdoMachine](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdomachine)

[ISdoMachine::Attach](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-attach)