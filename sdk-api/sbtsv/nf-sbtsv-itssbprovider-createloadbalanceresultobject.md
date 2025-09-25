# ITsSbProvider::CreateLoadBalanceResultObject

## Description

Creates an [ITsSbLoadBalanceResult](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbloadbalanceresult) load-balancing result
object.

## Parameters

### `TargetName` [in]

A **BSTR** variable that contains the target name.

### `ppLBResult` [out]

A pointer to a pointer to an [ITsSbLoadBalanceResult](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbloadbalanceresult) object. When you have finished using the object, release it by calling the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

This method can return one of these values.

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list.

## Remarks

Plug-ins can use this method to create a load-balancing result
object.

## See also

[ITsSbLoadBalanceResult](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbloadbalanceresult)

[ITsSbProvider](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovider)