# ITsSbLoadBalancingNotifySink::OnGetMostSuitableTarget

## Description

Returns a load-balancing result to Remote Desktop Connection Broker (RD Connection Broker).

## Parameters

### `pLBResult` [in]

A pointer to a [ITsSbLoadBalanceResult](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbloadbalanceresult) object that includes the name of the target to which the connection should
be redirected.

### `fIsNewConnection` [in]

Indicates whether this is a new connection. **TRUE** if it is a new connection; **FALSE** otherwise.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list.

## Remarks

Your plug-in should call this method on the [ITsSbLoadBalancingNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbloadbalancingnotifysink) object passed to [GetMostSuitableTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nf-sbtsv-itssbloadbalancing-getmostsuitabletarget).

## See also

[ITsSbLoadBalanceResult](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbloadbalanceresult)

[ITsSbLoadBalancing](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbloadbalancing)

[ITsSbLoadBalancingNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbloadbalancingnotifysink)