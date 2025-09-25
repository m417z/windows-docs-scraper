# IAzBizRuleInterfaces::AddInterfaces

## Description

The **AddInterfaces** method adds the specified interfaces to the list of [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interfaces that can be called by business rule (BizRule) scripts. To add the specified interfaces, AzMan calls the [AddNamedItem](https://learn.microsoft.com/scripting/winscript/reference/iactivescript-addnameditem) method of the [IActiveScript](https://learn.microsoft.com/scripting/winscript/reference/iactivescript) interface once for each specified interface.

## Parameters

### `varInterfaceNames` [in]

A [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) that specifies the names that scripts use to call the interfaces specified by the *varInterfaces* array.

### `varInterfaceFlags` [in]

A [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) that specifies flags sent to the [AddNamedItem](https://learn.microsoft.com/scripting/winscript/reference/iactivescript-addnameditem) method of the [IActiveScript](https://learn.microsoft.com/scripting/winscript/reference/iactivescript) interface. The **AddNamedItem** always behaves as if the **SCRIPTITEM_ISVISIBLE** flag is set, and the **SCRIPTITEM_ISPERSISTENT** flag is not set.

### `varInterfaces` [in]

A [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) that specifies the IDs of the interfaces to be added.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The names of the interfaces specified by the *varInterfaceNames* array are in the same order as the corresponding interface IDs specified by the *varInterfaces* array.