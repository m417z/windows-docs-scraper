# ISdo::ResetProperty

## Description

The
**ResetProperty** method resets the specified property to its default value.

## Parameters

### `Id`

Specifies the ID of an existing property.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## Remarks

Very few IAS properties have default values. If you reset a property that does not have a default value, **E_INVALIDARG** is returned. In Visual Basic, an error similar to the following is returned: "Function call is invalid".

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008.

## See also

[ISdo](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdo)

[ISdo::PutProperty](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdo-putproperty)

[ISdo::Restore](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdo-restore)