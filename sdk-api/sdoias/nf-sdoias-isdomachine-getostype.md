# ISdoMachine::GetOSType

## Description

The
**GetOSType** method retrieves the type of operating system running on the SDO computer.

## Parameters

### `eOSType` [out]

Pointer to an
[IASOSTYPE](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-iasostype) variable that receives the type of the operating system on the SDO computer.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## Remarks

Before calling this method, use the
[ISdoMachine::Attach](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-attach) method to attach to the SDO computer.

## See also

[IASOSTYPE](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-iasostype)

[ISdoMachine](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdomachine)

[ISdoMachine::Attach](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-attach)