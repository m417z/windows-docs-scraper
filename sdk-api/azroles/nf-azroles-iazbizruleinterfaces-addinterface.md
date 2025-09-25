# IAzBizRuleInterfaces::AddInterface

## Description

The **AddInterface** method adds the specified interface to the list of [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interfaces that can be called by business rule (BizRule) scripts. To add the specified interface, AzMan calls the [AddNamedItem](https://learn.microsoft.com/scripting/winscript/reference/iactivescript-addnameditem) method of the [IActiveScript](https://learn.microsoft.com/scripting/winscript/reference/iactivescript) interface.

## Parameters

### `bstrInterfaceName` [in]

A string that contains the name used by scripts to call the interface specified by the *varInterface* parameter.

### `lInterfaceFlag` [in]

Flags sent to the [AddNamedItem](https://learn.microsoft.com/scripting/winscript/reference/iactivescript-addnameditem) method of the [IActiveScript](https://learn.microsoft.com/scripting/winscript/reference/iactivescript) interface. The **AddNamedItem** always behaves as if the **SCRIPTITEM_ISVISIBLE** flag is set, and the **SCRIPTITEM_ISPERSISTENT** flag is not set.

### `varInterface` [in]

The ID of the interface to be added.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IAzBizRuleInterfaces](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazbizruleinterfaces)