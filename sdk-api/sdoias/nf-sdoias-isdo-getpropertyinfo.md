# ISdo::GetPropertyInfo

## Description

The
**GetPropertyInfo** method retrieves a pointer to an **ISdoPropertyInfo** interface for the specified property.

**Warning:** The **ISdoPropertyInfo** interface is unsupported and the use of this method to access it is discouraged.

## Parameters

### `Id` [in]

Specifies the ID of an existing property.

### `ppPropertyInfo` [out]

Pointer to a pointer that receives the address of an **ISdoPropertyInfo** interface for the specified property.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## Remarks

Although Server Data Objects (SDO) exposes this method, you do not need it in order to use SDO.

## See also

[ISdo](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdo)