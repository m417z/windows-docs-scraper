## Description

This is a callback method that you implement in your app, in order to determines the most suitable target to which to direct an incoming client connection. The Remote Desktop Connection Broker (RD Connection Broker) calls your implementation when the broker needs to redirect an incoming client connection.

## Parameters

### `pConnection` [in]

A pointer to an [ITsSbClientConnection](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbclientconnection) object. Information specific to a client connection, such as user name and
farm name, can be obtained from this object.

### `pLBSink` [in]

A pointer to an [ITsSbLoadBalancingNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbloadbalancingnotifysink) object. If the plug-in successfully determines where to redirect the connection, it should return the load balancing result by using this sink object. For more information, see [ITsSbLoadBalanceResult](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbloadbalanceresult).

## Return value

If the method succeeds, then return **S_OK**. Otherwise, indicate failure by returning *any* failure **HRESULT**. But if you want your plug-in to indicate that it has failed to determine a target, then you can return **E_SB_LOAD_BAL_FAILED**.

## Remarks

The default load-balancing algorithm in RD Connection Broker redirects an incoming connection to the server with the
fewest remote sessions. Your plug-in can use this method to override the default load-balancing algorithm. For example, you could define an algorithm that assigns connections to servers by comparing resource use on the target servers. You could also redirect the connection based on the
information in the client connection object, such as the [InitialProgram](https://learn.microsoft.com/windows/desktop/api/sbtsv/nf-sbtsv-itssbclientconnection-get_initialprogram) property.

## See also

[ITsSbClientConnection](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbclientconnection)

[ITsSbLoadBalanceResult](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbloadbalanceresult)

[ITsSbLoadBalancing](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbloadbalancing)

[ITsSbLoadBalancingNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbloadbalancingnotifysink)