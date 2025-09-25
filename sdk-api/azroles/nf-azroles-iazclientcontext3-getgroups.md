# IAzClientContext3::GetGroups

## Description

The **GetGroups** method returns an array of the application groups associated with this client context.

## Parameters

### `bstrScopeName` [in]

The name of the scope in which to check for application groups. This parameter is ignored if the value of the ulOptions parameter is set to **AZ_CLIENT_CONTEXT_GET_GROUPS_STORE_LEVEL_ONLY**.

### `ulOptions` [in]

A set of flags that modify the behavior of this method. This can be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **AZ_CLIENT_CONTEXT_GET_GROUPS_STORE_LEVEL_ONLY**<br><br>0x2 | This method checks only for application groups at the store level. |

### `pGroupArray` [out]

A pointer to an array of the names of application groups associated with this client context.

This is a variant that contains either a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) or the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object. Each element of the array holds a **VT_BSTR** that contains the name of an application group.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IAzClientContext3](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazclientcontext3)